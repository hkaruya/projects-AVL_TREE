#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "TreeInterface.h"
#include "Node.h"

using namespace std;

template<typename item>
class BinarySearchTree: public TreeInterface<item, Node<item>>{
	public:
		BinarySearchTree();
		virtual ~BinarySearchTree();
		
		virtual bool insert(item value) noexcept;
		
		bool find(item value);
		item findMin();
		item findMax();
		
		virtual bool remove(item value);
		virtual bool removeMin();
		virtual bool removeMax();
	protected:
		void clearTree(Node<item>* subtree) noexcept;
		
		void preorderTraversal(Node<item>* subtree, void visit(item&));
		void postorderTraversal(Node<item>* subtree, void visit(item&));
		void inorderTraversal(Node<item>* subtree, void visit(item&));
		void levelorderTraversal(Node<item>* subtree, void visit(item&));
		
		Node<item>* findMinNode(Node<item>* subtree);
		Node<item>* findMaxNode(Node<item>* subtree);
		
		Node<item>* insertToSubtree(Node<item>* subtree, Node<item>* new_item);
		Node<item>* nodeWithValue(Node<item>* subtree, item value);
		
		int getHeight(Node<item>* subtree) noexcept;
	private:
		bool removeNode(Node<item>* delete_node);
};
#include "BinarySearchTree.hpp"
#endif