#pragma once

#include "../Defines.h"
#include "Asserts.h"

// Disable debug and trace logging for release
#ifdef MRELEASE
	#define LOG_DEBUG_ENABLED 0
	#define LOG_TRACE_ENABLED 0
#endif

// Logging levels
typedef enum log_level {
	LOG_LEVEL_FATAL = 0,
	LOG_LEVEL_ERROR = 1,
	LOG_LEVEL_WARN = 2,
	LOG_LEVEL_INFO = 3,
	LOG_LEVEL_DEBUG = 4,
	LOG_LEVEL_TRACE = 5,
} log_level;


b8 initialize_logging();
void shutdown_logging();

MAPI void log_output(log_level level, const char* message, ...);

// Logs fatal messages
#ifndef MFATAL
	#define MFATAL(message, ...) log_output(LOG_LEVEL_FATAL, message, __VA_ARGS__)
#endif

#ifndef MERROR
	#define MERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, __VA_ARGS__)
#endif


#ifdef LOG_WARN_ENABLED
	#define MWARN(message, ...) log_output(LOG_LEVEL_WARN, message, __VA_ARGS__)
#else
	#define MWARN(message, ...) 
#endif

#ifdef LOG_INFO_ENABLED
	#define MINFO(message, ...) log_output(LOG_LEVEL_INFO, message, __VA_ARGS__)
#else
	#define MINFO(message, ...) 
#endif

#ifdef LOG_DEBUG_ENABLED
	#define MDEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, __VA_ARGS__)
#else
	#define MDEBUG(message, ...) 
#endif

void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line)
{
	log_output(LOG_LEVEL_FATAL, "Assertion Failure: %s, message: %s, in file %s, line %d\n", expression, message, file, line);
}