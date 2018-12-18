#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include "TestSuiteInterface.h"
#include "TreeError.h"

using namespace std;

template<typename item, typename node>
class TreeInterface: public TestSuiteInterface<item>{
	public: 
		//Virtual Deconstructor, helps free up memory allocated in heap
		virtual ~TreeInterface(){}
		
		//Default constructor
		TreeInterface();
		
		bool isEmpty() const noexcept; 
		
		virtual bool insert(item value) noexcept = 0; 
		
		virtual bool find(item value) = 0;
		
		//@return: minimum elelent in tree
		//@throw: TreeError, if tree is empty
		virtual item findMin() = 0; 
		
		//@return: maximum element in tree
		//@throw: TreeError, if tree is empty
		virtual item findMax() = 0;
		
		virtual bool remove(item value) = 0;
		
		//@return: true once minimum item is removed, false otherwise
		virtual bool removeMin() = 0;
		
		//@return: true once maximum item is removed, false otherwise
		virtual bool removeMax() = 0;
		
		virtual bool assert() noexcept = 0;
		
		//Performs preorder traversal applying visit function to each node
		//@param: visit(item&)
		virtual void preorder(void visit(item&));
		
		//Performs postorder traversal applying visit function to each node
		//@param: visit(item&)
		virtual void postorder(void visit(item&)); 
		
		//Performs inorder traversal applying visit function to each node
		//@param: visit(item&)
		virtual void inorder(void visit(item&)); 
		
		//Performs levelorder traversal applying visit function to each node
		//@param: visit(item&)
		virtual void levelorder(void visit(item&));
		
	protected:
		//Clears subtree (recursively)
		//@param: subtree
		virtual void clearTree(node* subtree) noexcept = 0;
		
		//Preorder traversal helper, recursive
		//@param: subtree
		//@param: visit(item&)
		virtual void preorderTraversal(node* subtree, void visit(item&)) = 0; 
		
		//Postorder traversal helper, recursive
		//@param: subtree
		//@param: visit(item&)
		virtual void postorderTraversal(node* subtree, void visit(item&)) = 0; 
		
		//Inorder traversal helper, recursive
		//@param: subtree
		//@param: visit(item&)
		virtual void inorderTraversal(node* subtree, void visit(item&)) = 0;
		
		//Levelorder traversal helper
		//@param: subtree
		//@param: visit(item&)
		virtual void levelorderTraversal(node* subtree, void visit(item&)) = 0;
		
		//Updates given node
		virtual bool updateNode(node* subtree) noexcept = 0;
		
		node* root_ptr = nullptr; 
};

#include "TreeInterface.hpp"
#endif
