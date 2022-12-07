#include "Logger.h"

// TODO: temporary
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 initialize_logging()
{
	//TODO: Create log file.
	return true;
}

void shutdown_logging()
{
	//TODO: Clean up logging/write queued entries.
}

void log_output(log_level level, const char* message, ...)
{
	const char* level_strings[6] = {
		"[FATAL]: ", 
		"[ERROR]: ", 
		"[WARN]: ",
		"[INFO]: ",
		"[DEBUG]: ", 
		"[TRACE]: ", 
	};

	// Buffer for log entries
	char out_message[32000];
	memset(out_message, 0, sizeof(out_message));

	va_list arg_ptr;
	va_start(arg_ptr, message);
	vsnprintf(out_message, 32000, message, arg_ptr);
	va_end(arg_ptr);

	// Format with level_string log name
	char fout_message[320000];
	sprintf(fout_message, "%s%s\n", level_strings[level], out_message);

	// TODO: Platform specific output
	printf("%s", fout_message);
}
