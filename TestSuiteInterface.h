#ifndef TESTSUITEINTERFACE_H
#define TESTSUITEINTERFACE_H

using namespace std;

const int NUMBER_OF_TESTS = 1000000;

template<typename item>
class TestSuiteInterface{
	public:
		//@return: true if tree is empty, false otherwise
		virtual bool isEmpty() const noexcept = 0;
		
		//Inserts item into tree
		//@post: item is inserted into tree
		//@param: value
		//@return: true once item is inserted, false otherwise
		virtual bool insert(item value) noexcept = 0;
		
		//Check tree if value is an element
		//@param: value 
		//@return: true if element in tree, false otherwise
		//@throw: TreeError, if tree is empty
		virtual bool find(item value) = 0;
		
		//Removes value if element in tree while still 
			//maintaining tree properties
		//@post: value is removed from tree
		//@param: value
		//@return: true once item is removed, false otherwise
		virtual bool remove(item value) = 0;
		
		//Asserts properties of given test
		virtual bool assert() noexcept = 0;
};
#endif
