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
	const int split = 10;
	int progress_bar = (2*NUMBER_OF_TESTS)/split;
	cout<<"INSERTION TEST: [";
	cout.flush();
	while(counter < split){
		for(int i = 0; i < progress_bar; i++){
			item value = randomizer_function(NUMBER_OF_TESTS*MULTIPLIER);
			if(data_structure->insert(value)){
				if(!(data_structure->assert())){
					cout<<"]"<<endl;
					throw TestError("~DATA STRUCTURE PROPERTIES BROKEN~");
				}
				if(!(data_structure->find(value))){
					cout<<"]"<<endl;
					throw TestError("~ITEM NOT PROPERLY INSERTED TO TREE AND/OR FIND FUNCTION ERROR~");
				}
			}
			else{
				i--;
			}
		}
		cout<<"|";
		cout.flush();
		counter++;
	}
	
	cout<<"]"<<endl;
	
	counter = 0;
	cout<<"DELETION TEST: [";
	cout.flush();
	while(counter < split){
		for(int i = 0; i < (NUMBER_OF_TESTS/split); i++){
			item value = randomizer_function(NUMBER_OF_TESTS*MULTIPLIER);
			if(data_structure->remove(value)){
				if(!(data_structure->assert())){
					cout<<"]"<<endl;
					throw TestError("~DATA STRUCTURE PROPERTIES BROKEN~");
				}
				if(data_structure->find(value)){
					cout<<"]"<<endl;
					throw TestError("~ITEM NOT PROPERLY DELETED FROM TREE AND/OR FIND FUNCTION ERROR~");
				}
			}
			else{
				i--;
			}
		}
		cout<<"|";
		cout.flush();
		counter++;
	}
	
	cout<<"]"<<endl;
	
	
}
