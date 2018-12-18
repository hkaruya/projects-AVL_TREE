#ifndef TESTSUITE_H
#define TESTSUITE_H

#include "TestSuiteInterface.h"
#include "TestError.h"

const int MULTIPLIER = 7;

using namespace std;

template<typename item>
class TestSuite{
	public:
		TestSuite(TestSuiteInterface<item>* structure, item (*randomizer)(int));
		
		void userInterface();
	private:
		item (*randomizer_function)(int);
		TestSuiteInterface<item>* data_structure;
		
		void runTest();
};
#include "TestSuite.hpp"
#endif
