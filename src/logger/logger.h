#pragma once
#include <stdbool.h>
#include <stdio.h>

#define ANSI_COLOR_INFO "\x1b[37m"
#define ANSI_COLOR_DEBUG "\x1b[36m"
#define ANSI_COLOR_WARN "\x1b[33m"
#define ANSI_COLOR_ERROR "\x1b[31m"
#define ANSI_COLOR_FATAL "\x1b[91;1m"
#define ANSI_COLOR_RESET "\x1b[0m"

typedef enum {
	LOG_INFO,
	LOG_DEBUG,
	LOG_WARN,
	LOG_ERROR,
	LOG_FATAL,
} LOG_LEVEL;

void logging(LOG_LEVEL level, const char *txt);
bool initialize_logger(FILE *file);
void uninitalize_logger();
