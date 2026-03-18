#include "core/asserts.h"
#include "core/logger.h"

int main(void) {

	initialize_logger();
	int x = 0;
	ASSERT(x < 0, "x must be less than 0");
	return 0;
}
