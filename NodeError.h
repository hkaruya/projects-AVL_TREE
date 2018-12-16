#ifndef NODEERROR_H
#define NODEERROR_H

#include<stdexcept>
#include<string>

using namespace std;

class NodeError: public domain_error{
	public:
		NodeError(const string& error_message);
};
#endif
