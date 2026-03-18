#include "logger.h"
#include "asserts.h"
#include <stdlib.h>

FILE *log_file = 0;

static void log_info(const char *txt) {
	printf(ANSI_COLOR_INFO "[INFO] %s" ANSI_COLOR_RESET "\n", txt);
	fprintf(log_file, ANSI_COLOR_INFO "[INFO] %s" ANSI_COLOR_RESET "\n", txt);
}

static void log_debug(const char *txt) {
	printf(ANSI_COLOR_DEBUG "[DEBUG] %s" ANSI_COLOR_RESET "\n", txt);
	fprintf(log_file, ANSI_COLOR_DEBUG "[DEBUG] %s" ANSI_COLOR_RESET "\n", txt);
}

static void log_warn(const char *txt) {
	printf(ANSI_COLOR_WARN "[WARN] %s" ANSI_COLOR_RESET "\n", txt);
	fprintf(log_file, ANSI_COLOR_WARN "[WARN] %s" ANSI_COLOR_RESET "\n", txt);
}

static void log_error(const char *txt) {
	printf(ANSI_COLOR_ERROR "[ERROR] %s" ANSI_COLOR_RESET "\n", txt);
	fprintf(log_file, ANSI_COLOR_ERROR "[ERROR] %s" ANSI_COLOR_RESET "\n", txt);
}

static void log_fatal(const char *txt) {
	printf(ANSI_COLOR_FATAL "[FATAL] %s" ANSI_COLOR_RESET "\n", txt);
	fprintf(log_file, ANSI_COLOR_FATAL "[FATAL] %s" ANSI_COLOR_RESET "\n", txt);
	exit(EXIT_FAILURE);
}

void S_LOG(LOG_LEVEL level, const char *txt) {
	switch (level) {
	case LOG_INFO:
		log_info(txt);
		break;
	case LOG_DEBUG:
		log_debug(txt);
		break;
	case LOG_WARN:
		log_warn(txt);
		break;
	case LOG_ERROR:
		log_error(txt);
		break;
	case LOG_FATAL:
		log_fatal(txt);
		break;
	default:
		printf("[UNKNOWN] %s\n", txt);
		break;
	}
}

void initialize_logger() {
	FILE *file = fopen(LOG_FILE_LOCATION, "a");
	if (!file) {
		char message[256];
		sprintf(message, "failed to open the file at location: %s\n", LOG_FILE_LOCATION);
		perror(message);
		exit(EXIT_FAILURE);
	}
	log_file = file;
	S_LOG(LOG_INFO, "Succcessfully initialized logger with log_file");
}

void uninitalize_logger() {
	log_file = 0; // remove log file for future reuse
}
