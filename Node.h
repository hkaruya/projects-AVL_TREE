#ifndef NODE_H
#define NODE_H

#include "NodeInterface.h"

using namespace std;

template<typename item>
class Node: public NodeInterface<item>{
	public:
		//Initializes class with no parameter; Default constructor
		//@post: children and parent sent to nullptr
		Node();
	
		//Initializes class with item as parameter
		//@post: node_item is set to new_item
		//@param: new_item
		Node(item new_item);
		
		~Node(){}
		
		//Initializes class with item and children as parameter
		//@post: left child set to new_left
		//@post: right child set to new_right
		//@post: node item set to new_item
		//@param: new_left
		//@param: new_right
		//@param: new_item
		Node(item new_item, Node<item>* parent, Node<item>* new_left, Node<item>* new_right);
		
		//@return: left child 
		Node<item>* getLeftChild() noexcept;
		
		//@return: right child
		Node<item>* getRightChild() noexcept;
		
		//@return: parent
		Node<item>* getParent() noexcept;
		
		//Sets left child to given parameter
		//@post: left child is new_child
		void setLeftChild(Node<item>* new_child) noexcept;
		
		//Sets right child to given parameter
		//@post: right child is new_child
		void setRightChild(Node<item>* new_child) noexcept;
		
		//Sets parent to given parameter
		//@post: parent is set to new_parent
		void setParent(Node<item>* new_parent) noexcept; 
		
		//Throws error since function isn't supported
		int getRank();
		
		//@return: true if none of the children are nullptr, false otherwise
		bool isFull() noexcept;
		
		//@return: true if both children are nullptr, false otherwise
		bool isLeaf() noexcept;
		
		//Detaches given child 
		//@return: true once detached, false otherwise
		bool detachChild(Node<item>* child);
	private:
		
		Node<item>* children[2];
		
		Node<item>* parent = nullptr;
};
#include "Node.hpp"
#endif
