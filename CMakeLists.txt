# CMakeLists.txt
# CMake Version
cmake_minimum_required(VERSION 3.9)
# Project Name
project(gl42 LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "My Graphics Library for 42Türkiye")
# CPP Standard
set(CMAKE_CXX_STANDARD 20)
# CPP Standard Required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenGL_GL_PREFERENCE GLVND)

find_package(OpenGL REQUIRED)

# Check GLFW library.

set(LIB_GLFW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw")

if (EXISTS "${LIB_GLFW_PATH}/CMakeLists.txt")
	message("GLFW Already Cloned.")
	add_subdirectory(${LIB_GLFW_PATH})
else ()
	message("Fetching GLFW...")
	include(FetchContent)

	FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw
		GIT_TAG master
		SOURCE_DIR "${LIB_GLFW_PATH}"
	)

	FetchContent_Populate(glfw)
	add_subdirectory(${LIB_GLFW_PATH})
endif ()

# Check GLEW library.

set(LIB_GLEW_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/glew")

if (EXISTS "${LIB_GLEW_PATH}/CMakeLists.txt")
	message("GLEW Already Cloned.")
	add_subdirectory(${LIB_GLEW_PATH})
else ()
	message("${LIB_GLEW_PATH}")
	message("Fetching GLEW...")
	include(FetchContent)

	FetchContent_Declare(
		glew
		GIT_REPOSITORY https://github.com/Perlmint/glew-cmake
		GIT_TAG master
		SOURCE_DIR "${LIB_GLEW_PATH}"
	)

	FetchContent_Populate(glew)
	add_subdirectory(${LIB_GLEW_PATH})
endif ()

################################# STATIC #################################

add_library(gl42Static STATIC)

target_include_directories(gl42Static
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/debug
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/shader
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/assets
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/include/GL
	)
	
	target_link_directories(gl42Static
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug/lib/glew/bin
	)

	if (WIN32)
		target_link_libraries(gl42Static
			PUBLIC libglew_static
			PUBLIC glfw
			PUBLIC opengl32
		)
		target_compile_options(gl42Static
			PRIVATE -Wall
		)
	else()
		target_link_libraries(gl42Static
			PUBLIC m	
			PUBLIC libglew_static
			PUBLIC glfw
			PUBLIC GL
		)
		target_compile_options(gl42Static
			PRIVATE -std=c++20
			PRIVATE -Wall
			PRIVATE -Wextra
			PRIVATE -Werror
			PRIVATE -O2
			PRIVATE -g
		)
	endif ()
	
	target_sources(gl42Static
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Window.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexBuffer.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexArray.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Vertex.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/shader/Shader.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Error.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/debug/Debug.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Math.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Matrix2x2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/assets/AssetLoader.cpp
	)
	
	################################# SHARED #################################
	
	add_library(gl42Shared SHARED)
	
	target_include_directories(gl42Shared
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/debug
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/shader
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/assets
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew/include/GL
	)
	
	target_link_directories(gl42Shared
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/out/build/x64-Debug/lib/glew/bin
	)

	if (WIN32)
		target_link_libraries(gl42Shared
			PUBLIC libglew_static
			PUBLIC glfw
			PUBLIC opengl32
		)
		target_compile_options(gl42Shared
			PRIVATE -Wall
		)
	else()
		target_link_libraries(gl42Shared
			PUBLIC m
			PUBLIC libglew_static
			PUBLIC glfw
			PUBLIC GL
		)
		target_compile_options(gl42Shared
			PRIVATE -std=c++20
			PRIVATE -Wall
			PRIVATE -Wextra
			PRIVATE -Werror
			PRIVATE -O2
			PRIVATE -g
		)
	endif()

	target_sources(gl42Shared
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Window.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexBuffer.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexArray.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Vertex.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/shader/Shader.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Error.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/debug/Debug.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Math.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Matrix2x2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/assets/AssetLoader.cpp
)

#################################OUTPUT#################################

if (WIN32)
	
	set_target_properties(gl42Static PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
	)

	# DLL's are runtime in Windows.
	set_target_properties(gl42Shared PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
	)

else()

	set_target_properties(gl42Static PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
		OUTPUT_NAME gl42
	)

	set_target_properties(gl42Shared PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
		OUTPUT_NAME gl42
	)

endif()