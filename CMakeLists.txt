cmake_minimum_required(VERSION 3.10)
project("Contact-Managment")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(
  "${CMAKE_SOURCE_DIR}/src"
)
