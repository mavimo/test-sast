cmake_minimum_required(VERSION 3.27)
project(palindrome VERSION 1.0.0 LANGUAGES CXX)

# Enable testing, but we want to show the output from google test when executing from console, so we
# add our own target. Execute with for instance `make check`.
enable_testing()
add_custom_target(check COMMAND GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} --verbose)

# Retrieve the standard GNU installation paths
include(GNUInstallDirs)

# GoogleTest requires at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Prevent googletest from overriding the parent project's compiler/linker
# when building with Microsoft Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(src)
add_subdirectory(test)