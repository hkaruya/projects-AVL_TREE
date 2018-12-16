#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char** argv){

	BinarySearchTree<int> fingers_crossed;
	
	fingers_crossed.insert(3);
	fingers_crossed.insert(4);
	fingers_crossed.insert(2);
	fingers_crossed.insert(5);
	
	cout<<fingers_crossed.findMin()<<endl;
	cout<<fingers_crossed.findMax()<<endl;
	
	fingers_crossed.remove(3);

return (0);
}
