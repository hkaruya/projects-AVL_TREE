#ifndef NODEINTERFACE_H
#define NODEINTERFACE_H

#include"NodeError.h"

using namespace std;

template<typename item>
class NodeInterface{
	public:
		//Initializes interface and sets children to nullptr
		NodeInterface();
		
		//Helps free up memory allocated in heap 
		virtual ~NodeInterface(){}
		
		//@return: length of shortest path 
		//@throw: NodeError, if function is not supported
		virtual int getRank() = 0;
		
		//Sets node item to given parameter
		//@post: node_item is new_item
		void setItem(item new_item) noexcept;
		
		//@return: node_item
		item getItem() noexcept; 	
	private:
		item node_item;
};
#include "NodeInterface.hpp"
#endif
