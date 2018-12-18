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
		
		virtual bool assert() noexcept;
		
		//Checks AVL tree properties
		//@return: true if tree is balanced and BST, false otherwise
		bool AVLProperties() noexcept;
	
	protected:
		//Balances tree if unbalanced, recurses up till reaches root
		//@param: subtree
		//@return: balanced tree
		virtual Node<item>* modifyTree(Node<item>* subtree);
		
		//@return: true if tree is left heavy, false otherwise
		bool isLeftHeavy(Node<item>* subtree) noexcept;
		
		//@return: true if tree if right heavy, false otherwise
		bool isRightHeavy(Node<item>* subtree) noexcept;
		
		//Performs LL rotation on given subtree
		//@param: subtree
		//@return: resulting tree with LL Rotation performed
		Node<item>* LLrotation(Node<item>* subtree);
		
		//Performs RR rotation on given subtree
		//@param: subtree
		//@return: resulting tree with RR Rotation performed
		Node<item>* RRrotation(Node<item>* subtree);
		
		//Performs LR rotation on given subtree
		//@param: subtree
		//@return: resulting tree with LR Rotation performed
		Node<item>* LRrotation(Node<item>* subtree);
		
		//Performs RL rotation on given subtree
		//@param: subtree
		//@return: resulting tree with RL Rotation performed
		Node<item>* RLrotation(Node<item>* subtree);
	private: 
		//@return true if given tree and its subtrees are balanced (recursive), false otherwise
		bool isTreeBalanced(Node<item>* subtree) noexcept;
		
		//@return: true if given tree is balanced, false otherwise
		bool isBalanced(Node<item>* subtree) noexcept; 
		
		//@return: parent of node where deletion happened
		Node<item>* deleteStartingPoint(Node<item>* delete_node);
		
		//@return: absolute value if value
		int absoluteValue(int value);
};
#include "AVLTree.hpp"
#endif
