#ifndef TESTERROR_H
#define TESTERROR_H

#include<stdexcept>
#include<string>

using namespace std;

class TestError: public runtime_error{
	public: 
		TestError(const string& error_message);
};
#endif
