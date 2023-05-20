set(HEADER_FILES
	src/Coin.h
    src/Platform.h
    src/Player.h
)

set(SOURCE_FILES
	src/Coin.cpp
    src/Platform.cpp
    src/Player.cpp
)

add_executable(Engine_Game main.cpp ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../ArchiveEngine/include)

target_link_libraries(Engine_Game ArchiveEngine)