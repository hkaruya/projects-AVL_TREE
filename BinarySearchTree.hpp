using namespace std;

template<typename item>
BinarySearchTree<item>::BinarySearchTree(){}

template<typename item>
BinarySearchTree<item>::~BinarySearchTree(){
	clearTree(this->root_ptr);
}

template<typename item>
bool BinarySearchTree<item>::insert(item value) noexcept{
	if(!(find(value))){
		Node<item>* insert_node = new Node<item>(value);
	
		this->root_ptr = insertToSubtree(this->root_ptr, insert_node);
		return true;
	}
	
	return false;
}

template<typename item>
bool BinarySearchTree<item>::find(item value){
	return (nullptr != nodeWithValue(this->root_ptr, value));
}

template<typename item>
item BinarySearchTree<item>::findMin(){
	if(this->isEmpty()){
		throw TreeError("~TREE IS EMPTY~");
	}
	
	item getter = findMinNode(this->root_ptr)->getItem();
	return getter;
}

template<typename item>
item BinarySearchTree<item>::findMax(){
	if(this->isEmpty()){
		throw TreeError("~TREE IS EMPTY~");
	}
	
	item getter = findMaxNode(this->root_ptr)->getItem();
	return getter; 
}

template<typename item>
bool BinarySearchTree<item>::remove(item value){
	Node<item>* delete_node = nodeWithValue(this->root_ptr, value);
	
	if(nullptr != delete_node){
		removeNode(delete_node);
		return true;
	}
	return false;
}

template<typename item>
bool BinarySearchTree<item>::removeMin(){
	if(this->isEmpty()){
		return false;
	}
	
	item getter = findMinNode(this->root_ptr)->getItem();
	
	return remove(getter);
}

template<typename item>
bool BinarySearchTree<item>::removeMax(){
	if(this->isEmpty()){
		return false;
	}
	
	item getter = findMaxNode(this->root_ptr)->getItem();
	
	return remove(getter);
}

template<typename item>
bool BinarySearchTree<item>::BSTProperties() noexcept{
	return checkBST(this->root_ptr);
}

template<typename item>
void BinarySearchTree<item>::clearTree(Node<item>* subtree) noexcept{
	if(nullptr != subtree){
		clearTree(subtree->getLeftChild());
		clearTree(subtree->getRightChild());
		
		delete subtree;
	}
}

template<typename item>
void BinarySearchTree<item>::preorderTraversal(Node<item>* subtree, void visit(item&)){
	if(nullptr != subtree){
		item getter = subtree->getItem();
		visit(getter);
		
		preorderTraversal(subtree->getLeftChild(), visit);
		preorderTraversal(subtree->getRightChild(), visit);
	}
}

template<typename item>
void BinarySearchTree<item>::postorderTraversal(Node<item>* subtree, void visit(item&)){
	if(nullptr != subtree){
		postorderTraversal(subtree->getLeftChild(), visit);
		postorderTraversal(subtree->getRightChild(), visit);
		
		item getter = subtree->getItem();
		visit(getter);
	}
}

template<typename item>
void BinarySearchTree<item>::inorderTraversal(Node<item>* subtree, void visit(item&)){
	if(nullptr != subtree){
		inorderTraversal(subtree->getLeftChild(), visit);
		
		item getter = subtree->getItem();
		visit(getter);
		
		inorderTraversal(subtree->getRightChild(), visit);
	}
}

template<typename item>
void BinarySearchTree<item>::levelorderTraversal(Node<item>* subtree, void visit(item&)){
	if(nullptr != subtree){
		Node<item>* tracer = subtree;
		node_queue.push(nullptr);
		
		while(true){
			item getter = tracer->getItem();
			visit(getter);
			
			if(nullptr != tracer->getLeftChild()){
				node_queue.push(tracer->getLeftChild());
			}
			
			if(nullptr != tracer->getRightChild()){
				node_queue.push(tracer->getRightChild());
			}
			
			if(nullptr == node_queue.peek()){
				if(1 == node_queue.size()){
					break;
				}
				else{
					cout<<"| ";
				}
			}
			
			if(nullptr == node_queue.peek()){
				node_queue.push(nullptr);
				node_queue.pop();
			}
			
			tracer = node_queue.peek();
			node_queue.pop();
		}
		
		node_queue.reset();
	}
}

template<typename item>
Node<item>* BinarySearchTree<item>::findMinNode(Node<item>* subtree){
	if((nullptr == subtree)||(nullptr == subtree->getLeftChild())){
		return subtree;
	}
	
	return findMinNode(subtree->getLeftChild());
}

template<typename item>
Node<item>* BinarySearchTree<item>::findMaxNode(Node<item>* subtree){
	if((nullptr == subtree)||(nullptr == subtree->getRightChild())){
		return subtree;
	}
	
	return findMaxNode(subtree->getRightChild());
}

template<typename item>
Node<item>* BinarySearchTree<item>::insertToSubtree(Node<item>* subtree, Node<item>* new_item){
	if(nullptr == subtree){
		return new_item;
	}
	
	if(new_item->getItem() < subtree->getItem()){
		subtree->setLeftChild(insertToSubtree(subtree->getLeftChild(), new_item));	
	}
	else{
		subtree->setRightChild(insertToSubtree(subtree->getRightChild(), new_item));
	}
	
	return subtree;
}

template<typename item>
Node<item>* BinarySearchTree<item>::nodeWithValue(Node<item>* subtree, item value){
	if((nullptr == subtree)||(value == subtree->getItem())){
		return subtree;
	}
	
	if(value < subtree->getItem()){
		return nodeWithValue(subtree->getLeftChild(), value);
	}
	else{
		return nodeWithValue(subtree->getRightChild(), value);
	}
}

template<typename item>
int BinarySearchTree<item>::getHeight(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return (0);
	}
	
	int left_child = getHeight(subtree->getLeftChild());
	int right_child = getHeight(subtree->getRightChild());
	 
	if(left_child > right_child){
		return left_child + 1;
	}
	else{
		return right_child + 1;
	}
}

template<typename item>
bool BinarySearchTree<item>::updateNode(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return false;
	}
	if(nullptr != subtree->getLeftChild()){
		subtree->getLeftChild()->setParent(subtree);
	}
	
	if(nullptr != subtree->getRightChild()){
		subtree->getRightChild()->setParent(subtree);
	}
	
	return true;
}

template<typename item>
Node<item>* BinarySearchTree<item>::detachLeftTree(Node<item>* subtree){
	if(nullptr == subtree){
		return subtree;
	}
	
	Node<item>* left_tree = subtree->getLeftChild();
	subtree->setLeftChild(nullptr);
	
	if(nullptr == left_tree){
		return left_tree;
	}
	
	left_tree->setParent(nullptr);
	
	return (left_tree);
}

template<typename item>
Node<item>* BinarySearchTree<item>::detachRightTree(Node<item>* subtree){
	if(nullptr == subtree){
		return subtree;
	}
	
	Node<item>* right_tree = subtree->getRightChild();
	subtree->setRightChild(nullptr);
	
	if(nullptr == right_tree){
		return right_tree;
	}
	
	right_tree->setParent(nullptr);
	
	return (right_tree);
}

template<typename item>
bool BinarySearchTree<item>::checkBST(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return true;
	}
	
	if((nullptr != subtree->getLeftChild()) && (subtree->getLeftChild()->getItem() >= subtree->getItem())){
		return false;
	}
	
	if((nullptr != subtree->getRightChild()) && (subtree->getRightChild()->getItem() < subtree->getItem())){
		return false;
	}
	
	return (checkBST(subtree->getLeftChild()) && checkBST(subtree->getRightChild()));
}

template<typename item>
bool BinarySearchTree<item>::removeNode(Node<item>* delete_node){
	if(delete_node->isFull()){
		Node<item>* min_of_right = findMinNode(delete_node->getRightChild());
		item new_value = min_of_right->getItem();
		
		delete_node->setItem(new_value);
		return removeNode(min_of_right);
	}
	else{
		if(!(delete_node->isLeaf())){
			Node<item>* parent = delete_node->getParent();
		
			if(nullptr == delete_node->getLeftChild()){
				if(nullptr == parent){
					this->root_ptr = delete_node->getRightChild();
				}
				else{
					if(delete_node == parent->getLeftChild()){
						parent->setLeftChild(delete_node->getRightChild());
					}
					else{
						parent->setRightChild(delete_node->getRightChild());
					}
				}
			}
			else{
				if(nullptr == parent){
					this->root_ptr = delete_node->getLeftChild();
				}
				else{
					if(delete_node == parent->getLeftChild()){
						parent->setLeftChild(delete_node->getLeftChild());
						
					}
					else{
						parent->setRightChild(delete_node->getLeftChild());
					}
				}
			}
		}
		
		delete delete_node;
		return true;  
	}
}
