objects = main.o TreeError.o NodeError.o QueueError.o TestError.o
template_files = queueInterface.h queue.h queue.hpp NodeInterface.h NodeInterface.hpp Node.h Node.hpp TestSuiteInterface.h TestSuite.h TestSuite.hpp TreeInterface.h TreeInterface.hpp BinarySearchTree.h BinarySearchTree.hpp AVLTree.h AVLTree.hpp
FLAGS = -std=c++11 -g -Wall

AVL_TREE: $(objects)
	g++ $(FLAGS) $(objects) -o AVL_TREE
main.o: main.cpp $(template_files)
	g++ $(FLAGS) -c main.cpp
TreeError.o: TreeError.cpp
	g++ $(FLAGS) -c TreeError.cpp
NodeError.o: NodeError.cpp
	g++ $(FLAGS) -c NodeError.cpp
QueueError.o: QueueError.cpp
	g++ $(FLAGS) -c QueueError.cpp
TestError.o: TestError.cpp
	g++ $(FLAGS) -c TestError.cpp
clear:
	rm *.o AVL_TREE
