
#include "HighResClock.h"

#ifdef _MSC_VER

#include "Windows.h"

namespace
{
	const long long g_Frequency = []() -> long long 
	{
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		return frequency.QuadPart;
	}();
}

HighResClock::time_point HighResClock::now()
{
	LARGE_INTEGER count;
	QueryPerformanceCounter(&count);
	return time_point(duration(count.QuadPart * static_cast<rep>(period::den) / g_Frequency));
}

#endif
