#include <iostream>
#include "AVLTree.h"

using namespace std;

static void print(int& value){
	cout<<value<<" ";
}

int main(int argc, char** argv){

	AVLTree<int> fingers_crossed;
	
	fingers_crossed.insert(3);
		//cout<<endl;
	fingers_crossed.insert(4);
		//cout<<endl;
	fingers_crossed.insert(2);
		//cout<<endl;
	fingers_crossed.insert(6);
		//cout<<endl;
	fingers_crossed.insert(5);
		//cout<<endl;
	fingers_crossed.insert(8);
		//cout<<endl;
	fingers_crossed.insert(7);
		if(fingers_crossed.AVLProperties()){
			cout<<"YEEEERRRRRRRRR"<<endl;
		}
		
	fingers_crossed.preorder(print);
		cout<<endl;
	fingers_crossed.postorder(print);
		cout<<endl;
	fingers_crossed.inorder(print);
		cout<<endl;
	fingers_crossed.levelorder(print);
		cout<<endl;
	
	//fingers_crossed.remove(6);
	//fingers_crossed.remove(4);

return (0);
}
