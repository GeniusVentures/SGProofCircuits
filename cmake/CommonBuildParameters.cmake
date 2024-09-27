include(${CMAKE_CURRENT_LIST_DIR}/functions.cmake)

# BOOST VERSION TO USE
set(BOOST_MAJOR_VERSION "1" CACHE STRING "Boost Major Version")
set(BOOST_MINOR_VERSION "85" CACHE STRING "Boost Minor Version")
set(BOOST_PATCH_VERSION "0" CACHE STRING "Boost Patch Version")

# convenience settings
set(BOOST_VERSION "${BOOST_MAJOR_VERSION}.${BOOST_MINOR_VERSION}.${BOOST_PATCH_VERSION}")
set(BOOST_VERSION_2U "${BOOST_MAJOR_VERSION}_${BOOST_MINOR_VERSION}")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(DEFINED USE_BOOST_INCLUDE_POSTFIX)
        set(BOOST_INCLUDE_POSTFIX "/boost-${BOOST_VERSION_2U}" CACHE STRING "Boost include postfix")
endif()

# --------------------------------------------------------
# Set config of GTest
set(GTest_DIR "${_THIRDPARTY_BUILD_DIR}/GTest/lib/cmake/GTest")
set(GTest_INCLUDE_DIR "${_THIRDPARTY_BUILD_DIR}/GTest/include")
find_package(GTest CONFIG REQUIRED)
include_directories(${GTest_INCLUDE_DIR})
add_compile_definitions(CRYPTO3_CODEC_BASE58)

# Boost should be loaded before libp2p v0.1.2
# --------------------------------------------------------
# Set config of Boost project
set(_BOOST_ROOT "${_THIRDPARTY_BUILD_DIR}/boost/build/${CMAKE_SYSTEM_NAME}${ABI_SUBFOLDER_NAME}")
set(Boost_LIB_DIR "${_BOOST_ROOT}/lib")
set(Boost_INCLUDE_DIR "${_BOOST_ROOT}/include${BOOST_INCLUDE_POSTFIX}")
set(Boost_DIR "${Boost_LIB_DIR}/cmake/Boost-${BOOST_VERSION}")
set(boost_headers_DIR "${Boost_LIB_DIR}/cmake/boost_headers-${BOOST_VERSION}")
set(boost_random_DIR "${Boost_LIB_DIR}/cmake/boost_random-${BOOST_VERSION}")
set(boost_system_DIR "${Boost_LIB_DIR}/cmake/boost_system-${BOOST_VERSION}")
set(boost_filesystem_DIR "${Boost_LIB_DIR}/cmake/boost_filesystem-${BOOST_VERSION}")
set(boost_program_options_DIR "${Boost_LIB_DIR}/cmake/boost_program_options-${BOOST_VERSION}")
set(boost_date_time_DIR "${Boost_LIB_DIR}/cmake/boost_date_time-${BOOST_VERSION}")
set(boost_regex_DIR "${Boost_LIB_DIR}/cmake/boost_regex-${BOOST_VERSION}")
set(boost_atomic_DIR "${Boost_LIB_DIR}/cmake/boost_atomic-${BOOST_VERSION}")
set(boost_chrono_DIR "${Boost_LIB_DIR}/cmake/boost_chrono-${BOOST_VERSION}")
set(boost_log_DIR "${Boost_LIB_DIR}/cmake/boost_log-${BOOST_VERSION}")
set(boost_log_setup_DIR "${Boost_LIB_DIR}/cmake/boost_log_setup-${BOOST_VERSION}")
set(boost_thread_DIR "${Boost_LIB_DIR}/cmake/boost_thread-${BOOST_VERSION}")
set(boost_unit_test_framework_DIR "${Boost_LIB_DIR}/cmake/boost_unit_test_framework-${BOOST_VERSION}")
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_LIBS ON)
set(Boost_NO_SYSTEM_PATHS ON)
option(Boost_USE_STATIC_RUNTIME "Use static runtimes" ON)

# --------------------------------------------------------
# Set config of zkLLVM's Clang
# set(Clang_DIR "${_THIRDPARTY_BUILD_DIR}/circifier/lib/cmake/clang/")
# set(Clang_INCLUDE_DIR "${_THIRDPARTY_BUILD_DIR}/circifier/include/clang/")
# find_package(Clang CONFIG REQUIRED)
# include_directories(${Clang_INCLUDE_DIR})
#
# set(CMAKE_C_COMPILER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/clang")
# set(CMAKE_CXX_COMPILER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/clang++")

# header only libraries must not be added here
find_package(Boost REQUIRED COMPONENTS date_time filesystem random regex system thread log log_setup program_options)
include_directories(${Boost_INCLUDE_DIRS})

# --------------------------------------------------------
# set config for crypto3
option(BUILD_TESTS "Build tests" ON)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(BUILD_APPS "Enable application targets." FALSE)
option(BUILD_EXAMPLES "Enable demonstration targets." FALSE)
option(BUILD_DOCS "Enable documentation targets." FALSE)
set(DOXYGEN_OUTPUT_DIR "${CMAKE_CURRENT_LIST_DIR}/docs" CACHE STRING "Specify doxygen output directory")

include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/../include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/block/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/codec/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/containers/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/hash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/kdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/mac/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/math/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/core/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/zk/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/modes/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/passhash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pbkdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pkpad/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pubkey/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/random/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/stream/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/threshold/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/vdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/zk/include"
)

add_library(${PROJECT_NAME}
        STATIC

        # "${CMAKE_CURRENT_LIST_DIR}/src/circuits/MPCVerifierCircuit.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../src/circuits/TransactionVerifierCircuit.cpp"

        # "${CMAKE_CURRENT_LIST_DIR}/src/SGGenerateProofs.cpp"
)

add_circuit(TransactionVerifierCircuit
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/../src/circuits/TransactionVerifierCircuit.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/../include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/block/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/codec/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/containers/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/hash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/kdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/mac/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/math/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/core/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/zk/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/modes/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/passhash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pbkdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pkpad/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pubkey/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/random/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/stream/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/threshold/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/vdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/zk/include"

        LINK_LIBRARIES

        ${Boost_LIBRARIES})
add_circuit(MPCVerifierCircuit
        SOURCES ${CMAKE_CURRENT_LIST_DIR}/../src/circuits/MPCVerifierCircuit.cpp

        INCLUDE_DIRECTORIES
        "${CMAKE_CURRENT_LIST_DIR}/../include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/block/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/codec/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/containers/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/hash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/kdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/mac/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/math/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/algebra/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/core/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/marshalling/zk/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/modes/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/multiprecision/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/passhash/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pbkdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pkpad/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/pubkey/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/random/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/stream/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/threshold/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/vdf/include"
        "${THIRDPARTY_DIR}/zkLLVM/libs/crypto3/libs/zk/include"

        LINK_LIBRARIES

        ${Boost_LIBRARIES})

add_dependencies(${PROJECT_NAME} TransactionVerifierCircuit MPCVerifierCircuit)

install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/TransactionVerifierCircuit.ll
        ${CMAKE_CURRENT_BINARY_DIR}/MPCVerifierCircuit.ll
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/circuits)

# if(BUILD_TESTS)
# add_executable(${PROJECT_NAME}_test
# "${CMAKE_CURRENT_LIST_DIR}/../test/TransactionVerfierCircuit_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/BitcoinKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/EthereumKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/ElGamalKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/ECElGamalKeyGenerator_test.cpp"
# #"${CMAKE_CURRENT_LIST_DIR}/../test/KDFGenerator_test.cpp"
# )
# target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME} GTest::gtest )
# endif()
