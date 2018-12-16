using namespace std;

template<typename item>
bool AVLTree<item>::insert(item value) noexcept{
	if(BinarySearchTree::insert(value)){
		Node<item>* insert_node = nodeWithValue(value);
		
		this->root_ptr = modifyTree(insert_node);
		return true;
	}
}

template<typename item>
bool AVLTree<item>::remove(item value){
	Node<item>* delete_parent = deleteStartingPoint(nodeWithValue(this->root_ptr, value));
	
	if(BinarySearchTree::remove(value)){
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
bool AVLTree<item>::removeMin(){
	if(this->isEmpty()){
		return false;
	}
	
	item getter = findMinNode(this->root_ptr)->getItem();
	
	return remove(getter);
}

template<typename item>
bool AVLTree<item>::removeMax(){
	if(this->isEmpty()){
		return false;
	}
	
	item getter = findMaxNode(this->root_ptr)->getItem();
	
	return remove(getter);
}

template<typename item>
Node<item>* AVLTree<item>::modifyTree(Node<item>* subtree){
	if(nullptr == this->root_ptr){
		return subtree;
	}
	
	while(this->root_ptr != subtree){
		return modifyTree(subtree->getParent());
	}
	
	return subtree;
}

template<typename item>
Node<item>* AVLTree<item>::LLRotation(Node<item>* subtree){

}

template<typename item>
Node<item>* AVLTree<item>::RRRotation(Node<item>* subtree){

}

template<typename item>
Node<item>* AVLTree<item>::LRRotation(Node<item>* subtree){

}

template<typename item>
Node<item>* AVLTree<item>::RLRotation(Node<item>* subtree){

}

template<typename item>
bool AVLTree<item>::isBalanced(Node<item>* subtree) noexcept{

} 

template<typename item>
Node<item>* AVLTree<item>::deleteStartingPoint(Node<item>* delete_node){

}

template<typename item>
int AVLTree<item>::absouluteValue(int value){

}
