#ifndef GTESTMAIN_H_
#define GTESTMAIN_H_

#include "gtest/gtest.h"
#include <stdio.h>

GTEST_API_ int runAllTests(int argc, char **argv) {
	int result = 0;
	printf("Running main() from gtest_main.cc\n");
	testing::InitGoogleTest();
	result = RUN_ALL_TESTS();
	return result;
}

#endif /* GTESTMAIN_H_ */
