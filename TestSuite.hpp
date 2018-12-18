using namespace std;

template<typename item>
TestSuite<item>::TestSuite(TestSuiteInterface<item>* structure, item (*randomizer)(int)){
	data_structure = structure;
	randomizer_function = randomizer;
}

template<typename item>
void TestSuite<item>::userInterface(){
	char choice = 'N';
	
	cout<<"Run Test? (y/n) ";
	cin>>choice;
	
	choice = toupper(choice);
	
	if('Y' == choice){
		try{
			runTest();
			cout<<"~TEST COMPLETED: NO ERRORS~"<<endl;
		}
		catch(TestError te){
			cerr<<te.what()<<endl;
		}
	}
}

template<typename item>
void TestSuite<item>::runTest(){
	int counter = 0; 
	while(counter < (2*NUMBER_OF_TESTS)){
		item value = randomizer_function(NUMBER_OF_TESTS*MULTIPLIER);
		if(data_structure->insert(value)){
			if(!(data_structure->assert())){
				throw TestError("~DATA STRUCTURE PROPERTIES BROKEN~");
			}
			if(!(data_structure->find(value))){
				throw TestError("~ITEM NOT PROPERLY INSERTED TO TREE AND/OR FIND FUNCTION ERROR~");
			}
			counter++;
		}
	}
	
	cout<<"INSERTION TEST: [DONE]"<<endl;
	
	counter = 0;
	while(counter < NUMBER_OF_TESTS){
		item value = randomizer_function(NUMBER_OF_TESTS*MULTIPLIER);
		
		if(data_structure->remove(value)){
			if(!(data_structure->assert())){
				throw TestError("~DATA STRUCTURE PROPERTIES BROKEN~");
			}
			if(data_structure->find(value)){
				throw TestError("~ITEM NOT PROPERLY DELETED FROM TREE AND/OR FIND FUNCTION ERROR~");
			}
			counter++;
		}
	}
	
	cout<<"DELETION TEST: [DONE]"<<endl;
	
	
}
