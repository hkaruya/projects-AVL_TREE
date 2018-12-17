#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

const int SIZE = 10000;

using namespace std;

template<typename item>
class queueInterface{
	public:
		virtual bool push(item new_item) = 0;
		
		virtual item peek() = 0;
		
		virtual bool pop() = 0;
		
		virtual bool isEmpty() = 0;
		
		virtual int size() = 0;
};
#endif
