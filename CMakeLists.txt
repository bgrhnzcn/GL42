# CMakeLists.txt
# CMake Version
cmake_minimum_required(VERSION 3.10)
# Project Name
project(GL42 LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "My Graphics Library for 42Türkiye")
# Add Executable
add_library(gl42 STATIC)

set(SOURCE_DIR src)
INCLUDE_DIRECTORIES(inc)

# Add Source Files
target_sources(gl42 PRIVATE
	$(SOURCE_DIR)/window/window.cpp
	$(SOURCE_DIR)/exception/exception.cpp
)

target_include_directories()

# CPP Standard
set(CMAKE_CXX_STANDARD 21)
# CPP Standard Required
set(CMAKE_CXX_STANDARD_REQUIRED ON)