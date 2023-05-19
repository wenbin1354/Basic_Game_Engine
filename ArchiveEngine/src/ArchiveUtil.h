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

#if ARCHIVE_DEBUG == 2
	#define ARCHIVE_LOG(x) std::cout << "Log: " << x << std::endl;
	#define ARCHIVE_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#elif ARCHIVE_DEBUG == 1
	#define ARCHIVE_LOG(x)
	#define ARCHIVE_ERROR(x) std::cerr << "ERROR: " << x << std::endl;
#else
	#define ARCHIVE_LOG(x)
	#define ARCHIVE_ERROR(x)
#endif