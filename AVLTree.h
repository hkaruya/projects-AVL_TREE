#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinarySearchTree.h"

using namespace std;

template<typename item>
class AVLTree: public BinarySearchTree<item>{
	public: 
		AVLTree(){}
		
		bool insert(item value) noexcept;
		
		bool remove(item value);
		bool removeMin();
		bool removeMax();
	
	protected:
		virtual Node<item>* modifyTree(Node<item>* subtree);
		
		Node<item>* LLrotation(Node<item>* subtree);
		Node<item>* RRrotation(Node<item>* subtree);
		Node<item>* LRrotation(Node<item>* subtree);
		Node<item>* RLrotation(Node<item>* subtree);
	private: 
		bool isBalanced(Node<item>* subtree) noexcept; 
		
		Node<item>* deleteStartingPoint(Node<item>* delete_node);
		
		int absouluteValue(int value);
};
#include "AVLTree.hpp"
#endif
