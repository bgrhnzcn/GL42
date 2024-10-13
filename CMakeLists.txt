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

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

#################################STATIC#################################

add_library(gl42Static STATIC)

target_include_directories(gl42Static
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/shader
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm/glm
	)
	
	target_link_directories(gl42Static
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew
	)
	
	target_link_libraries(gl42Static
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
	
	target_sources(gl42Static
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Window.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexBuffer.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexArray.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/shader/Shader.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/InitializationExecption.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Error.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Math.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Matrix2x2.cpp
	)
	
	#################################SHARED#################################
	
	add_library(gl42Shared SHARED)
	
	target_include_directories(gl42Shared
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/shader
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utils
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/math
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glm/glm
	)
	
	target_link_directories(gl42Shared
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glfw
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib/glew
	)
	
	target_link_libraries(gl42Shared
	PUBLIC glfw
	)
	
	target_compile_options(gl42Shared
	PRIVATE -std=c++20
	PRIVATE -Wall
	PRIVATE -Wextra
	PRIVATE -Werror
	PRIVATE -g
	)
	
	target_sources(gl42Shared
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/Window.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexBuffer.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/renderer/VertexArray.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/shader/Shader.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/InitializationExecption.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/utils/Error.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Math.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector2.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector3.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Vector4.cpp
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/math/Matrix2x2.cpp
)

#################################OUTPUT#################################

if (WIN32)
	set_target_properties(gl42Static PROPERTIES
		ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
	)

	set_target_properties(gl42Shared PROPERTIES
		LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
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