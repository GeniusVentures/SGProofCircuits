
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
option(BUILD_TESTS "Build tests" ON)
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

# --------------------------------------------------------
# Set config of zkLLVM's Clang
set(Clang_DIR "${_THIRDPARTY_BUILD_DIR}/circifier/lib/cmake/clang/")
set(Clang_INCLUDE_DIR "${_THIRDPARTY_BUILD_DIR}/circifier/include/clang/")
find_package(Clang CONFIG REQUIRED)
include_directories(${Clang_INCLUDE_DIR})

set(CMAKE_C_COMPILER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/clang")
set(CMAKE_CXX_COMPILER "${_THIRDPARTY_BUILD_DIR}/circifier/bin/clang++")


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
        "${CMAKE_CURRENT_LIST_DIR}/include"
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
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/TransactionVerifierCircuit.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/src/circuits/TwoFactor.cpp"

        # "${CMAKE_CURRENT_LIST_DIR}/src/SGGenerateProofs.cpp"
)

# Install Headers
install(DIRECTORY "${CMAKE_SOURCE_DIR}/include/" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}" FILES_MATCHING PATTERN "*.h*")

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
        ${CMAKE_CURRENT_BINARY_DIR}/SGProofCircuitsConfig.cmake
        DESTINATION ${SGProofCircuits_CONFIG_DESTINATION_DIR}
)

# if(BUILD_TESTS)
# add_executable(${PROJECT_NAME}_test
# "${CMAKE_CURRENT_LIST_DIR}/../test/main_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/BitcoinKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/EthereumKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/ElGamalKeyGenerator_test.cpp"
# "${CMAKE_CURRENT_LIST_DIR}/../test/ECElGamalKeyGenerator_test.cpp"
# #"${CMAKE_CURRENT_LIST_DIR}/../test/KDFGenerator_test.cpp"
# )
# target_link_libraries(${PROJECT_NAME}_test PUBLIC ${PROJECT_NAME} GTest::gtest Boost::random)
# endif()
