# @file      CMakeLists.txt
# @brief     CMakeLists file

cmake_minimum_required(VERSION 3.16.3)

# CMake configurations
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define PROJECT_BASE_NAME
set(PROJECT_BASE_NAME sonarcloud-test-c-cpp)
message("Configuring for ${PROJECT_BASE_NAME} - Build type is ${CMAKE_BUILD_TYPE}")

# Declare the executable first, so that we can add flags and sources later on
set(APP_EXECUTABLE_NAME ${PROJECT_BASE_NAME}.elf)
message("Executable name: ${APP_EXECUTABLE_NAME}")
add_executable(${APP_EXECUTABLE_NAME})

# Define compile options
if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(${APP_EXECUTABLE_NAME} PRIVATE -O1 -g)
    target_compile_definitions(${APP_EXECUTABLE_NAME} PRIVATE DEBUG)
else()
    target_compile_options(${APP_EXECUTABLE_NAME} PRIVATE -Os)
endif()

# Add sources
file(GLOB_RECURSE SOURCES_TEMP ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
target_sources(${APP_EXECUTABLE_NAME} PRIVATE ${SOURCES_TEMP})

# Define project LANGUAGES
project(${PROJECT_BASE_NAME} LANGUAGES C ASM)

# Define VERSION if not already done
file(STRINGS ${CMAKE_CURRENT_LIST_DIR}/VERSION VERSION_NUMBER LIMIT_COUNT 1)
STRING(REGEX REPLACE "^([0-9]+)\\.([0-9]+)\\.([0-9]+)-rc[0-9]+" "\\1.\\2.\\3" VERSION_NUMBER "${VERSION_NUMBER}")
project(${PROJECT_BASE_NAME} VERSION ${VERSION_NUMBER} LANGUAGES)
