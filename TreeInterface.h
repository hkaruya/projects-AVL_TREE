#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include "TreeError.h"

using namespace std;

template<typename item, typename node>
class TreeInterface{
	public: 
		virtual ~TreeInterface(){}
		
		TreeInterface();
		
		bool isEmpty() const noexcept; 
		
		virtual bool insert(item value) noexcept = 0; 
		
		virtual bool find(item value) = 0;
		virtual item findMin() = 0; 
		virtual item findMax() = 0;
		
		virtual bool remove(item value) = 0;
		virtual bool removeMin() = 0;
		virtual bool removeMax() = 0;
		
		virtual void preorder(void visit(item&));
		virtual void postorder(void visit(item&)); 
		virtual void inorder(void visit(item&)); 
		virtual void levelorder(void visit(item&));
		
	protected:
		virtual void clearTree(node* subtree) noexcept = 0;
		
		virtual void preorderTraversal(node* subtree, void visit(item&)) = 0; 
		virtual void postorderTraversal(node* subtree, void visit(item&)) = 0; 
		virtual void inorderTraversal(node* subtree, void visit(item&)) = 0;
		virtual void levelorderTraversal(node* subtree, void visit(item&)) = 0;
		
		virtual node* detachLeftTree(node* subtree);
		virtual node* detachRightTree(node* subtree);
		
		node* root_ptr = nullptr; 
};

#include "TreeInterface.hpp"
#endif
