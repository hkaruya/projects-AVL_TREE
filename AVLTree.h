#ifndef AVLTREE_H
#define AVLTREE_H

#include "BinarySearchTree.h"

using namespace std;

template<typename item>
class AVLTree: public BinarySearchTree<item>{
	public: 
		AVLTree(){}
		
		virtual bool insert(item value) noexcept;
		
		virtual bool remove(item value);
		
		bool AVLProperties() noexcept;
	
	protected:
		virtual Node<item>* modifyTree(Node<item>* subtree);
		
		bool isLeftHeavy(Node<item>* subtree) noexcept;
		bool isRightHeavy(Node<item>* subtree) noexcept;
		
		Node<item>* LLrotation(Node<item>* subtree);
		Node<item>* RRrotation(Node<item>* subtree);
		Node<item>* LRrotation(Node<item>* subtree);
		Node<item>* RLrotation(Node<item>* subtree);
	private: 
		bool isTreeBalanced(Node<item>* subtree) noexcept;
		bool isBalanced(Node<item>* subtree) noexcept; 
		
		Node<item>* deleteStartingPoint(Node<item>* delete_node);
		
		int absoluteValue(int value);
};
#include "AVLTree.hpp"
#endif
