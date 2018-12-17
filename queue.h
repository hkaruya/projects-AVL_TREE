#ifndef QUEUE_H
#define QUEUE_H

#include"queueInterface.h"
#include"QueueError.h"

using namespace std;

template<typename item>
class queue: public queueInterface<item>{
	public:
		queue();
		
		bool push(item new_item);
		item peek();
		bool pop();
		bool isEmpty();
		int size();
		
		void reset();
	private:
		item item_queue[SIZE];
		
		int back_pointer = 0;
		int front_pointer = 0;
		
		int data_size = 0;
};
#include"queue.hpp"
#endif
