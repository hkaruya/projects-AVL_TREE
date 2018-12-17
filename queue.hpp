using namespace std;

template<typename item>
queue<item>::queue(){
	reset();
}

template<typename item>
bool queue<item>::push(item new_item){
	if(data_size == SIZE){
		return false;
	}
	else{
		back_pointer++;
		back_pointer = back_pointer % SIZE;
		item_queue[back_pointer] = new_item;
		
		
		data_size++;
		
		return true;
	}	
}

template<typename item>
item queue<item>::peek(){
	if(isEmpty()){
		throw QueueError("~QUEUE IS EMPTY~");
	}
	
	return (item_queue[front_pointer]);
}

template<typename item>
bool queue<item>::pop(){
	if(isEmpty()){
		return false;	
	}
	
	front_pointer++;
	front_pointer = (front_pointer % SIZE);
	
	data_size--;
	
	return true;
}

template<typename item>
bool queue<item>::isEmpty(){
	return (data_size == 0);
}

template<typename item>
int queue<item>::size(){
	return data_size;
}

template<typename item>
void queue<item>::reset(){
	back_pointer = -1;
	front_pointer = 0;

	data_size = 0;
}
