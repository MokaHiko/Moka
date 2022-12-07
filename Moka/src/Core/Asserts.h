#pragma once

#include "../Defines.h"

#ifdef MASSERTIONS_ENABLED
	#if _MSC_VER
		#define mdbreak() __debugbreak()
	#else
		#define mdbreak()
	#endif

	MAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

	#define MASSERT(expr)												\
		{																\
			if (expr) {													\
			}															\
			else {														\
			report_assertion_failure(#expr, "", __FILE__, __LINE__);	\
			mdbreak();													\
			}															\
		}								

	#define MASSERT_MSG(expr,message)										\
		{																	\
			if (expr) {														\
			}																\
			else {															\
			report_assertion_failure(#expr, message, __FILE__, __LINE__);	\
			mdbreak();														\
			}																\
		}								

	#ifdef _DEBUG
		#define MASSERT_DEBUG(expr)											\
			{																\
				if (expr) {													\
				}															\
				else {														\
				report_assertion_failure(#expr, "", __FILE__, __LINE__);	\
				mdbreak();													\
				}															\
			}	
	#else	
		#define MASSERT_DEBUG(expr)											
	#endif
	#else	
		#define mdbreak()
		#define MASSERT(expr)
		#define MASSERT_MSG(expr)
		#define MASSERT_DEBUG(expr)
#endif