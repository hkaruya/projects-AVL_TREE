#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "TreeInterface.h"
#include "queue.h"
#include "Node.h"

using namespace std;

template<typename item>
class BinarySearchTree: public TreeInterface<item, Node<item>>{
	public:
		//Default constructor
		BinarySearchTree();
		
		//Virtual destructor, helps free up memory allocated in heap
		virtual ~BinarySearchTree();
		
		virtual bool insert(item value) noexcept;
		
		bool find(item value);
		item findMin();
		item findMax();
		
		virtual bool remove(item value);
		bool removeMin();
		bool removeMax();
		
		//Checks Binary Search Tree Properties
		//@return: true if binary search tree (less than in left subtree, else on right)
			//false otherwise
		bool BSTProperties() noexcept;
	protected:
		void clearTree(Node<item>* subtree) noexcept;
		
		void preorderTraversal(Node<item>* subtree, void visit(item&));
		void postorderTraversal(Node<item>* subtree, void visit(item&));
		void inorderTraversal(Node<item>* subtree, void visit(item&));
		void levelorderTraversal(Node<item>* subtree, void visit(item&));
		
		//Gets min node of given subtree
		//@param: subtree
		//@return: min node
		Node<item>* findMinNode(Node<item>* subtree);
		
		//Gets max node of given subtree
		//@param: subtree
		//@return: max node
		Node<item>* findMaxNode(Node<item>* subtree);
		
		//Insert helper function, recursive
		//@post: new item is added to correct location
		//@param: subtree
		//@param: new_item
		//@return: tree with new item inserted
		Node<item>* insertToSubtree(Node<item>* subtree, Node<item>* new_item);
		
		//Gets node with value in parameter
		//@param: subtree
		//@param: value
		//@return: node with given value, nullptr if not found
		Node<item>* nodeWithValue(Node<item>* subtree, item value);
		
		//@return: height of given subtree
		int getHeight(Node<item>* subtree) noexcept;
		
		//Updates node, setting parent of each children to subtree
		//@return: true once finished, false if subtree is nullptr
		bool updateNode(Node<item>* subtree) noexcept;
		
		//Detaches left subtree of given subtree
		//@return: detached subtree
		Node<item>* detachLeftTree(Node<item>* subtree);
		
		//Detaches right subtree of given subtree
		//@return: detached subtree
		Node<item>* detachRightTree(Node<item>* subtree);
	private:
		//Checks BST properties, recursively
		bool checkBST(Node<item>* subtree) noexcept;
		
		//Remove helper function
		//@return: true once removed, false otherwise
		bool removeNode(Node<item>* delete_node);
		
		queue<Node<item>*> node_queue;
};
#include "BinarySearchTree.hpp"
#endif
