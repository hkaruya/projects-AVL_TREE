#include "Node.h"
using namespace std;

template<typename item>
Node<item>::Node(){
	parent = nullptr;
	
	children[0] = nullptr;
	children[1] = nullptr;
}

template<typename item>
Node<item>::Node(item new_item){
	this->setItem(new_item);
	
	children[0] = nullptr;
	children[1] = nullptr;
}

template<typename item>
Node<item>::Node(item new_item, Node<item>* new_parent, Node<item>* new_left, Node<item>* new_right){
	this->setItem(new_item);
	
	parent = new_parent;
	
	children[0] = new_left;
	children[1] = new_right;
}

template<typename item>
Node<item>* Node<item>::getLeftChild() noexcept{
	return children[0];
}

template<typename item>
Node<item>* Node<item>::getRightChild() noexcept{
	return children[1];
}

template<typename item>
Node<item>* Node<item>::getParent() noexcept{
	return parent;
}

template<typename item>
void Node<item>::setLeftChild(Node<item>* new_child) noexcept{
	children[0] = new_child;
	
	if(nullptr != new_child){
		new_child->setParent(this);
	}
}

template<typename item>
void Node<item>::setRightChild(Node<item>* new_child) noexcept{
	children[1] = new_child; 
	
	if(nullptr != new_child){
		new_child->setParent(this); 
	}
}

template<typename item>
void Node<item>::setParent(Node<item>* new_parent) noexcept{
	parent = new_parent;
}

template<typename item>
int Node<item>::getRank(){
	throw NodeError("~NO RANK INFORMATION~");
}

template<typename item>
bool Node<item>::isFull() noexcept{
	return ((nullptr != children[0])&&(nullptr != children[1]));
}

template<typename item>
bool Node<item>::isLeaf() noexcept{
	return ((nullptr == children[0])&&(nullptr == children[1]));
}
