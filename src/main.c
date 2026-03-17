#include "logger/logger.h"
#include <stdio.h>

int main(void) {
	FILE *file = fopen("log/log.txt", "a");
	if (!file) {
		perror("failed to open file log/log.txt");
	}
	if (initialize_logger(file)) {
		logging(LOG_INFO, "Succcessfully initialized logger with log_file");
	} else {
		fprintf(stderr, "failed to initialize_logger");
	}
	return 0;
}
