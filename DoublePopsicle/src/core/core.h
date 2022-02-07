#pragma once

#ifdef DP_PLATFORM_WIN
	#ifdef DP_BUILD_DLL
		#define DP_API __declspec(dllexport)
	#else
		#define DP_API __declspec(dllimport)
	#endif // DP_BUILD_DLL
#else
	#error DoublePopsicle only support windows now!
#endif // DP_PLATFORM_WIN

#define BIT(x) (1 << x)