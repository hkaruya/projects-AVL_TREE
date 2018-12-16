#ifndef TREEERROR_H
#define TREEERROR_H

#include<stdexcept>
#include<string>

using namespace std;

class TreeError: public runtime_error{
	public: 
		TreeError(const string& error_message);
};
#endif
