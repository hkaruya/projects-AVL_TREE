#ifndef TESTSUITEINTERFACE_H
#define TESTSUITEINTERFACE_H

using namespace std;

template<typename item>
class TestSuiteInterface{
	public:
		virtual bool isEmpty() const noexcept = 0;
		
		virtual bool insert(item value) noexcept = 0;
		
		virtual bool find(item value) = 0;
		
		virtual bool remove(item value) = 0;
		
		virtual bool assert() = 0;
};
#endif
