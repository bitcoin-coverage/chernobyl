cmake_minimum_required(VERSION 3.9)

project(bitcoin-mutator VERSION 1.0.0 DESCRIPTION "Mutators for Bitcoin Core")
find_package(LLVM REQUIRED CONFIG)
include_directories(${LLVM_INCLUDE_DIRS})

include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS False)

add_compile_options(-fno-rtti)
add_compile_options(-fno-exceptions)

add_compile_options(-Wall -Wextra)

file(GLOB_RECURSE CHECKS "checks/*.h")

add_library(bitcoin-mutator SHARED ${CHECKS} mutator_module.cpp)

install(TARGETS bitcoin-mutator LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
