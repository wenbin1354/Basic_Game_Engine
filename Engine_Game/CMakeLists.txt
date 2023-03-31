add_executable(Engine_Game main.cpp)

include_directories(../ArchiveEngine/include)

target_link_libraries(Engine_Game ArchiveEngine)