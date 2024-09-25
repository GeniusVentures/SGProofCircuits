function(disable_clang_tidy target)
    set_target_properties(${target} PROPERTIES
        C_CLANG_TIDY ""
        CXX_CLANG_TIDY ""
    )
endfunction()

function(addtest test_name)
    add_executable(${test_name} ${ARGN})
    addtest_part(${test_name} ${ARGN})
    target_link_libraries(${test_name}
        GTest::gtest_main
        GTest::gmock_main
    )
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/xunit)
    set(xml_output "--gtest_output=xml:${CMAKE_BINARY_DIR}/xunit/xunit-${test_name}.xml")
    add_test(
        NAME ${test_name}
        COMMAND $<TARGET_FILE:${test_name}> ${xml_output}
    )
    set_target_properties(${test_name} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test_bin
        ARCHIVE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/test_lib
        LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/test_lib
    )
    disable_clang_tidy(${test_name})

    if(FORCE_MULTILE)
        set_target_properties(${test_name} PROPERTIES LINK_FLAGS "${MULTIPLE_OPTION}")
    endif()
endfunction()

function(addtest_part test_name)
    if(POLICY CMP0076)
        cmake_policy(SET CMP0076 NEW)
    endif()

    target_sources(${test_name} PUBLIC
        ${ARGN}
    )
    target_link_libraries(${test_name}
        GTest::gtest
    )
endfunction()

# conditionally applies flag.
function(add_flag flag)
    check_cxx_compiler_flag(${flag} FLAG_${flag})

    if(FLAG_${flag} EQUAL 1)
        add_compile_options(${flag})
    endif()
endfunction()

function(print)
    message(STATUS "[${CMAKE_PROJECT_NAME}] ${ARGV}")
endfunction()

# ## sgnus_install should be called right after add_library(target)
function(sgnus_install target)
    install(TARGETS ${target} EXPORT GeniusKDFTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FRAMEWORK DESTINATION ${CMAKE_INSTALL_PREFIX}
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
    )
endfunction()

function(add_circuit_no_stdlib name)
    set(prefix ARG)
    set(noValues "")
    set(singleValues)
    set(multiValues SOURCES INCLUDE_DIRECTORIES LINK_LIBRARIES COMPILER_OPTIONS)
    cmake_parse_arguments(${prefix}
        "${noValues}"
        "${singleValues}"
        "${multiValues}"
        ${ARGN})

    if(NOT ARG_SOURCES)
        message(FATAL_ERROR "SOURCES for ${name} circuit was not defined")
    endif()

    foreach(source ${ARG_SOURCES})
        if(NOT IS_ABSOLUTE ${source})
            list(APPEND CIRCUIT_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${source}")
        else()
            list(APPEND CIRCUIT_SOURCES "${source}")
        endif()
    endforeach()

    list(REMOVE_DUPLICATES CIRCUIT_SOURCES)

    foreach(ITR ${CIRCUIT_SOURCES})
        if(NOT EXISTS ${ITR})
            message(SEND_ERROR "Cannot find circuit source file: ${source}")
        endif()
    endforeach()

    set(INCLUDE_DIRS_LIST "")

    # Collect include directories from dependencies first
    foreach(lib ${ARG_LINK_LIBRARIES})
        get_target_property(lib_include_dirs ${lib} INTERFACE_INCLUDE_DIRECTORIES)

        foreach(dir ${lib_include_dirs})
            list(APPEND INCLUDE_DIRS_LIST "-I${dir}")
        endforeach()
    endforeach()

    # Add passed include directories
    foreach(include_dir ${ARG_INCLUDE_DIRECTORIES})
        if(NOT IS_ABSOLUTE ${include_dir})
            set(include_dir "${CMAKE_CURRENT_SOURCE_DIR}/${include_dir}")
        endif()

        list(APPEND INCLUDE_DIRS_LIST "-I${include_dir}")
    endforeach()

    list(APPEND INCLUDE_DIRS_LIST -I${_THIRDPARTY_BUILD_DIR}/stdlib/lib/c++/v1 -I${_THIRDPARTY_BUILD_DIR}/circifier/src/circifier-build/lib/clang/17/include/ -I${_THIRDPARTY_BUILD_DIR}/stdlib/lib/libc)

    list(REMOVE_DUPLICATES INCLUDE_DIRS_LIST)

    set(link_options "-S")

    set(CLANG "${_THIRDPARTY_BUILD_DIR}/circifier/bin/clang")
    set(LINKER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/llvm-link")

    # Compile sources
    set(compiler_outputs "")
    add_custom_target(${name}_compile_sources)

    foreach(source ${CIRCUIT_SOURCES})
        get_filename_component(source_base_name ${source} NAME)
        set(compile_command "${CLANG} -target assigner -Xclang -fpreserve-vec3-type -Werror=unknown-attributes -D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
        -D__ZKLLVM__ ${INCLUDE_DIRS_LIST} -emit-llvm -O1 -S ${ARG_COMPILER_OPTIONS}  -o ${name}_${source_base_name}.ll ${source}")
        message(WARNING "The compilation command is:  ${compile_command}")

        add_custom_target(${name}_${source_base_name}_ll
                        COMMAND ${CLANG} -target assigner -Xclang -fpreserve-vec3-type -Werror=unknown-attributes -D_LIBCPP_ENABLE_CXX17_REMOVED_UNARY_BINARY_FUNCTION
                        -D__ZKLLVM__ ${INCLUDE_DIRS_LIST} -emit-llvm -O1 -S ${ARG_COMPILER_OPTIONS}  -o ${name}_${source_base_name}.ll ${source}

                        VERBATIM COMMAND_EXPAND_LISTS

                        SOURCES ${source})
        add_dependencies(${name}_compile_sources ${name}_${source_base_name}_ll)
        list(APPEND compiler_outputs "${name}_${source_base_name}.ll")
    endforeach()

    # Link sources
    add_custom_target(${name}
        COMMAND ${LINKER} ${link_options} -o ${name}.ll ${compiler_outputs}
        DEPENDS ${name}_compile_sources
        VERBATIM COMMAND_EXPAND_LISTS)
    set_target_properties(${name} PROPERTIES OUTPUT_NAME ${name}.ll)
endfunction(add_circuit_no_stdlib)

function(add_circuit)
    list(POP_FRONT ARGV circuit_name)
    list(PREPEND ARGV ${circuit_name}_no_stdlib)
    add_circuit_no_stdlib(${ARGV})

    set(LINKER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/llvm-link")
    set(libc_stdlib ${_THIRDPARTY_BUILD_DIR}/stdlib/lib/zkllvm/zkllvm-libc.ll)
    set(libcpp_stdlib ${_THIRDPARTY_BUILD_DIR}/stdlib/lib/zkllvm/zkllvm-libcpp.ll)
    set(link_options "-S")

    add_custom_target(${circuit_name}
        COMMAND ${LINKER} ${link_options} -o ${circuit_name}.ll ${circuit_name}_no_stdlib.ll ${libc_stdlib} ${libcpp_stdlib}
        DEPENDS ${circuit_name}_no_stdlib
        VERBATIM COMMAND_EXPAND_LISTS)

    #add_dependencies(${circuit_name} zkllvm-libc zkllvm-libcpp)
endfunction(add_circuit)
