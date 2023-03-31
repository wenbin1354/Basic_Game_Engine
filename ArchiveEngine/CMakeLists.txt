set(HEADER_FILES
	src/ArchiveUtil.h
	src/ArchiveApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWImplementation.h
)

set(SOURCE_FILES
	src/ArchiveApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWImplementation.cpp
)

add_library(ArchiveEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)

target_precompile_headers(ArchiveEngine PRIVATE src/pch.h)

target_link_libraries(ArchiveEngine glfw)

add_definitions(-DARCHIVE_LIB)
add_definitions(-DARCHIVE_GLFW)