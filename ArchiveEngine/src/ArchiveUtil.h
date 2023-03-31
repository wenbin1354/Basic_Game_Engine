#pragma once

#ifdef ARCHIVE_WINDOWS
	#ifdef ARCHIVE_LIB
		#define ARCHIVE_API _declspec(dllexport)
	#else
		#define ARCHIVE_API _declspec(dllimport)
	#endif // ARCHIVE_LIB
#else
	#define ARCHIVE_API
#endif // ARCHIVE_WINDOWS



#define ARCHIVE_GAME_START(ClassName) \
int main() {\
	ClassName game;\
	game.Run();\
	return 0;\
}