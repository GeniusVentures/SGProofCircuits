
include(${CMAKE_CURRENT_LIST_DIR}/cmake/functions.cmake)

cmake_minimum_required(VERSION 3.20)
set(
        CMAKE_TOOLCHAIN_FILE
        "${CMAKE_SOURCE_DIR}/cmake/toolchain/cxx17.cmake"
        CACHE
        FILEPATH
        "Default toolchain"
)

add_definitions(-D_WIN32_WINNT=0x0601)
add_definitions(-DBOOST_BIND_GLOBAL_PLACEHOLDERS)

include(GNUInstallDirs)
project(SGProofCircuits C CXX)

if(NOT EXISTS "${CMAKE_TOOLCHAIN_FILE}")
        set(CMAKE_CXX_STANDARD 17)
        set(CMAKE_CXX_STANDARD_REQUIRED ON)
        set(CMAKE_CXX_EXTENSIONS OFF)
endif()

include(cmake/functions.cmake)

find_package(Boost REQUIRED COMPONENTS date_time filesystem random regex system thread log log_setup program_options)
include_directories(${Boost_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---------------------------
# Set version
set(VERSION_STRING 0)
set(SUBVERSION_STRING 1)

# Set source file dir
option(BUILD_TESTING "Build tests" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_APPS "Enable application targets." FALSE)
option(BUILD_EXAMPLES "Enable demonstration targets." FALSE)
option(BUILD_DOCS "Enable documentation targets." FALSE)
set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/docs" CACHE STRING "Specify doxygen output directory")

if(NOT DEFINED THIRDPARTY_BUILD_DIR)
        # print("Setting third party build directory default")
        get_filename_component(BUILD_PLATFORM_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
        set(THIRDPARTY_BUILD_DIR "${THIRDPARTY_DIR}/build/Linux/${CMAKE_BUILD_TYPE}${ANDROID_ABI_FOLDER}" CACHE STRING "Default Third Party Build Directory")
endif()

set(_THIRDPARTY_BUILD_DIR "${THIRDPARTY_BUILD_DIR}" CACHE STRING "Local ThirdParty Build Directory")

# print("THIRDPARTY BUILD DIR: ${_THIRDPARTY_BUILD_DIR}")
if(DEFINED USE_BOOST_INCLUDE_POSTFIX)
        set(BOOST_INCLUDE_POSTFIX "/boost-${BOOST_VERSION_2U}" CACHE STRING "Boost include postfix")
endif()

# header only libraries must not be added here
find_package(Boost REQUIRED COMPONENTS date_time filesystem random regex system thread log log_setup program_options)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_INSTALL_INCLUDEDIR "${CMAKE_INSTALL_INCLUDEDIR}/SGProofCircuits")

include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/include"
)

add_library(${PROJECT_NAME}
        STATIC
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/MPCVerifierCircuit.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionVerifierCircuit.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionVerifierCircuitTOTP.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionValidator.cpp"
)

add_circuit(TransactionVerifierCircuit
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionVerifierCircuit.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionValidator.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${ZKLLVM_BUILD_DIR}/zkLLVM/include"
        LINK_LIBRARIES

        ${Boost_LIBRARIES})
add_circuit(TransactionVerifierCircuitTOTP
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionVerifierCircuitTOTP.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionValidator.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${ZKLLVM_BUILD_DIR}/zkLLVM/include"
        LINK_LIBRARIES

        ${Boost_LIBRARIES})

add_circuit(MPCVerifierCircuit
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/circuits/MPCVerifierCircuit.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${ZKLLVM_BUILD_DIR}/zkLLVM/include"

        LINK_LIBRARIES

        ${Boost_LIBRARIES})
add_circuit(RecursiveTransactionCircuit
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/src/circuits/RecursiveTransactionCircuit.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/include"
        "${ZKLLVM_BUILD_DIR}/zkLLVM/include"

        LINK_LIBRARIES

        ${Boost_LIBRARIES})

add_dependencies(${PROJECT_NAME} TransactionVerifierCircuit MPCVerifierCircuit RecursiveTransactionCircuit TransactionVerifierCircuitTOTP)

install(TARGETS ${PROJECT_NAME} EXPORT SGProofCircuitsTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FRAMEWORK DESTINATION ${CMAKE_INSTALL_PREFIX}
        BUNDLE DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/TransactionVerifierCircuit.ll
        ${CMAKE_CURRENT_BINARY_DIR}/TransactionVerifierCircuitTOTP.ll
        ${CMAKE_CURRENT_BINARY_DIR}/MPCVerifierCircuit.ll
        ${CMAKE_CURRENT_BINARY_DIR}/RecursiveTransactionCircuit.ll
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/circuits)

# Install Headers
install(DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING PATTERN "*.h*"
)

# Install Targets
set(SGProofCircuits_CONFIG_DESTINATION_DIR "lib/cmake/SGProofCircuits")
install(EXPORT SGProofCircuitsTargets
        FILE SGProofCircuitsTargets.cmake
        DESTINATION ${SGProofCircuits_CONFIG_DESTINATION_DIR}
)

include(CMakePackageConfigHelpers)

# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/SGProofCircuitsConfig.cmake"
        INSTALL_DESTINATION "lib/cmake/examples"
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# generate the version file for the config file
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/SGProofCircuitsConfigVersion.cmake"
        VERSION "${VERSION_STRING}.${SUBVERSION_STRING}"
        COMPATIBILITY AnyNewerVersion
)

# install the configuration file
install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/SGProofCircuitsConfigVersion.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/SGProofCircuitsConfig.cmake
        DESTINATION ${SGProofCircuits_CONFIG_DESTINATION_DIR}
)

