using namespace std;

template<typename item>
bool AVLTree<item>::insert(item value) noexcept{
	if(BinarySearchTree<item>::insert(value)){
		Node<item>* insert_node = this->nodeWithValue(this->root_ptr, value);
		
		this->root_ptr = modifyTree(insert_node);
		return true;
	}
	return false;
}

template<typename item>
bool AVLTree<item>::remove(item value){
	Node<item>* delete_parent = deleteStartingPoint(this->nodeWithValue(this->root_ptr, value));
	
	if(BinarySearchTree<item>::remove(value)){
		if(nullptr == delete_parent){
			this->root_ptr = modifyTree(this->root_ptr);
		}
		else{
			this->root_ptr = modifyTree(delete_parent);
		}
		return true;
	}
	return false;
}

template<typename item>
bool AVLTree<item>::assert() noexcept{
	return (AVLProperties());
}

template<typename item>
bool AVLTree<item>::AVLProperties() noexcept{
	return ((this->BSTProperties()) && isTreeBalanced(this->root_ptr));
}

template<typename item>
Node<item>* AVLTree<item>::modifyTree(Node<item>* subtree){
	if((nullptr == subtree)&&(!(this->isEmpty()))){
		throw TreeError("~PARADOX: ENTERED EMPTY TREE BUT TREE STILL EXISTS~");
	}
	
	if(this->isEmpty()){
		return nullptr;
	}
	
	if(isBalanced(subtree)){
		if(subtree == this->root_ptr){
			return subtree;
		}
	}
	else{
		Node<item>* parent = subtree->getParent();
		
		if(isLeftHeavy(subtree)){
			if(isLeftHeavy(subtree->getLeftChild())){
				if(nullptr == parent){
					this->root_ptr = LLrotation(subtree);
					return this->root_ptr;
				}
				
				if(subtree == parent->getLeftChild()){
					parent->setLeftChild(LLrotation(subtree));
				}
				else{
					parent->setRightChild(LLrotation(subtree));
				}
				
			}
			else{
				if(nullptr == parent){
					this->root_ptr = LRrotation(subtree);
					return this->root_ptr;
				}
				
				if(subtree == parent->getLeftChild()){
					parent->setLeftChild(LRrotation(subtree));
				}
				else{
					parent->setRightChild(LRrotation(subtree));
				}
				
			}
		}	
		else{
			if(isRightHeavy(subtree->getRightChild())){
				if(nullptr == parent){
					this->root_ptr = RRrotation(subtree);
					return this->root_ptr;
				}
				
				if(subtree == parent->getLeftChild()){
					parent->setLeftChild(RRrotation(subtree));
				}
				else{
					parent->setRightChild(RRrotation(subtree));
				}
				
			}
			else{
				if(nullptr == parent){
					this->root_ptr = RLrotation(subtree);
					return this->root_ptr;
				}
				
				if(subtree == parent->getLeftChild()){
					parent->setLeftChild(RLrotation(subtree));
				}
				else{
					parent->setRightChild(RLrotation(subtree));
				}
				
			}
		}
	}
	
	return modifyTree(subtree->getParent());
}

template<typename item>
Node<item>* AVLTree<item>::LLrotation(Node<item>* subtree){
	Node<item>* x = subtree; 
	Node<item>* y = subtree->getLeftChild();
	
	Node<item>* temp = this->detachRightTree(y);
	
	y->setParent(nullptr);
	y->setRightChild(x);
	x->setLeftChild(temp);
	
	this->updateNode(y);
	this->updateNode(x);
	
	return y;
}

template<typename item>
Node<item>* AVLTree<item>::RRrotation(Node<item>* subtree){
	Node<item>* x = subtree;
	Node<item>* y = subtree->getRightChild();
	
	Node<item>* temp = this->detachLeftTree(y);
	
	y->setParent(nullptr);
	y->setLeftChild(x);
	x->setRightChild(temp);
	
	this->updateNode(y);
	this->updateNode(x);
	
	return y;	
}

template<typename item>
Node<item>* AVLTree<item>::LRrotation(Node<item>* subtree){
	Node<item>* x = subtree;
	Node<item>* y = subtree->getLeftChild();
	
	x->setLeftChild(RRrotation(y));
	
	
	return (LLrotation(x));
}

template<typename item>
Node<item>* AVLTree<item>::RLrotation(Node<item>* subtree){
	Node<item>* x = subtree;
	Node<item>* y = subtree->getRightChild();
	
	x->setRightChild(LLrotation(y));
	
	return (RRrotation(x));
}

template<typename item>
bool AVLTree<item>::isTreeBalanced(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return true;
	}
	
	return((isBalanced(subtree)) && (isTreeBalanced(subtree->getLeftChild())) && (isTreeBalanced(subtree->getRightChild())));
}

template<typename item>
bool AVLTree<item>::isBalanced(Node<item>* subtree) noexcept{
	return(!(absoluteValue((this->getHeight(subtree->getLeftChild()) - this->getHeight(subtree->getRightChild()))) > 1));
} 

template<typename item>
Node<item>* AVLTree<item>::deleteStartingPoint(Node<item>* delete_node){
	if(nullptr == delete_node){
		return delete_node;	
	}
	
	if(delete_node->isFull()){
		return(this->findMinNode(delete_node->getRightChild())->getParent());
	}
	
	return (delete_node->getParent());
}

template<typename item>
int AVLTree<item>::absoluteValue(int value){
	if(0 > value){
		return (-1 * value);
	}
	
	return value; 
}

template<typename item>
bool AVLTree<item>::isLeftHeavy(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return false;
	}
	
	return(this->getHeight(subtree->getLeftChild()) >= this->getHeight(subtree->getRightChild()));
}

template<typename item>
bool AVLTree<item>::isRightHeavy(Node<item>* subtree) noexcept{
	if(nullptr == subtree){
		return false;
	}
	
	return(this->getHeight(subtree->getRightChild()) >= this->getHeight(subtree->getLeftChild()));
}
