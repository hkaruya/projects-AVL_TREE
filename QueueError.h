#ifndef QUEUEERROR_H
#define QUEUEERROR_H

#include<stdexcept>
#include<string>

using namespace std;

class QueueError: public domain_error{
	public:
		QueueError(const string& error_message);
};
#endif
