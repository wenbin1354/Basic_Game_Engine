cmake_minimum_required(VERSION 3.24)

project(SampleGame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DARCHIVE_WINDOWS)
elseif(APPLE)
	add_definitions(-DARCHIVE_MACOS)
else()
	add_definitions(-DARCHIVE_LINUX)
endif()

add_subdirectory(glfw)
add_subdirectory(glad)
add_subdirectory(stbi)
add_subdirectory(ArchiveEngine)
add_subdirectory(Engine_Game)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Engine_Game)
