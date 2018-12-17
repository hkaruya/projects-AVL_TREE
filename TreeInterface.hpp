using namespace std;

template<typename item, typename node>
TreeInterface<item, node>::TreeInterface(){
	root_ptr = nullptr;
}

template<typename item, typename node>
bool TreeInterface<item, node>::isEmpty() const noexcept{
	return (nullptr == root_ptr);
}

template<typename item, typename node>
void TreeInterface<item, node>::preorder(void visit(item&)){
	preorderTraversal(root_ptr, visit);
}

template<typename item, typename node>
void TreeInterface<item, node>::postorder(void visit(item&)){
	postorderTraversal(root_ptr, visit);
}

template<typename item, typename node>
void TreeInterface<item, node>::inorder(void visit(item&)){
	inorderTraversal(root_ptr, visit);
}

template<typename item, typename node>
void TreeInterface<item, node>::levelorder(void visit(item&)){
	levelorderTraversal(root_ptr, visit);
}
