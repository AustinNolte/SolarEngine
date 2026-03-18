#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(condition, message)                                                                                                         \
	do {                                                                                                                                   \
		if (!(condition)) {                                                                                                                \
			S_ASSERT(#condition, message, __FILE__, __LINE__);                                                                             \
		}                                                                                                                                  \
	} while (0)

static inline void S_ASSERT(const char *condition, const char *message, const char *file, int line) {
	fprintf(stderr, "Assertion Failed: %s\n", condition);
	fprintf(stderr, "Message: %s\n", message);
	fprintf(stderr, "File: %s\n", file);
	fprintf(stderr, "Line: %d\n", line);
	exit(EXIT_FAILURE);
}
