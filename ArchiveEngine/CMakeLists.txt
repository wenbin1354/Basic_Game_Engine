set(HEADER_FILES
	src/ArchiveUtil.h
	src/ArchiveApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWImplementation.h
	src/Renderer.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
)

set(SOURCE_FILES
	src/ArchiveApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWImplementation.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
)

add_library(ArchiveEngine SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)


target_precompile_headers(ArchiveEngine PRIVATE src/pch.h)

target_link_libraries(ArchiveEngine glfw glad stbi)

add_definitions(-DARCHIVE_LIB)
add_definitions(-DARCHIVE_GLFW)
add_definitions(-DARCHIVE_OPENGL)
add_definitions(-DARCHIVE_WINDOWS)
add_definitions(-DARCHIVE_DEBUG=2)

