#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

//MAX SIZE OF QUEUE
const int SIZE = 100000;

using namespace std;

template<typename item>
class queueInterface{
	public:
		//Pushes new_item to back of queue
		//@post: new_item is at back of queue
		//@param: new_item
		//@return: true once inserted, false if full
		virtual bool push(item new_item) = 0;
		
		//Shows item at front of queue
		//@return: item at front of queue
		//@throw: QueueError if queue is empty
		virtual item peek() = 0;
		
		//Removes item at front of queue
		//@return: true once removed, false if queue is empty
		virtual bool pop() = 0;
		
		//@return: true if queue is empty, false otherwise
		virtual bool isEmpty() = 0;
		
		//@return: size of queue
		virtual int size() = 0;
};
#endif
