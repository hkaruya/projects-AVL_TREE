objects = main.o TreeError.o NodeError.o
template_files = NodeInterface.h NodeInterface.hpp Node.h Node.hpp TreeInterface.h TreeInterface.hpp BinarySearchTree.h BinarySearchTree.hpp
FLAGS = -std=c++11 -g -Wall

AVL_TREE: $(objects)
	g++ $(FLAGS) $(objects) -o AVL_TREE
main.o: main.cpp $(template_files)
	g++ $(FLAGS) -c main.cpp
TreeError.o: TreeError.cpp
	g++ $(FLAGS) -c TreeError.cpp
NodeError.o: NodeError.cpp
	g++ $(FLAGS) -c NodeError.cpp
clear:
	rm *.o AVL_TREE
