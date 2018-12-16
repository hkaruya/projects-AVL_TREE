using namespace std;

template<typename item>
NodeInterface<item>::NodeInterface(){}

template<typename item>
void NodeInterface<item>::setItem(item new_item) noexcept{
	node_item = new_item;
}

template<typename item>
item NodeInterface<item>::getItem() noexcept{
	return node_item;
}
