#include <iostream>

#include <time.h>
#include <stdlib.h>
#include "AVLTree.h"
#include "TestSuite.h"

using namespace std;

static int testFunction(int value){
	srand(clock());
	
	int random_number = rand() % value + 1;
	
	return random_number;
}

int main(int argc, char** argv){

	TestSuite<int> tester(new AVLTree<int>(), testFunction);
	
	tester.userInterface();
	

return (0);
}
