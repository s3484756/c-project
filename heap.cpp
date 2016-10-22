#include <vector>
#include <stdio.h>
template <class type> class Heap : public std::vector<type>{
	public:
		bool add(type node);
		void sort();
		bool remove(type node);
		type popQueue();
};

template<class type> bool Heap<type>::add(type node){
	type * temp;
	int index;
	if(this->size() == 0)
		this->push_back(node);
	this->push_back(node);
	index = this->size()-1;
	while(this->at(index/2) > node && index > 1){
		temp = &this->at(index/2);
		this->at(index/2) = node;
		this->at(index) = *temp;
		index = index/2;
	}
	return true;
}

template<class type> void Heap<type>::sort(){
	int x = 1;
}

template<class type> bool Heap<type>::remove(type node){
	return false;
}

template<class type> type Heap<type>::popQueue(){
	type * priority;
	type * temp;
	bool contDown = true;
	int index = 1;
	priority = &this->at(1);
	//this->erase(this->begin() + 1);
	this->at(1) = this->at(this->size()-1);
	this->pop_back();
	while(contDown == true && index < (this->size()-1)/2){
		contDown = false;
		if(this->at(index) > this->at(index*2) || this->at(index) > this->at(index*2+1)){
			contDown = true;
			if(this->at(index*2) > this->at(index*2+1)){
				temp = &this->at(index);
				this->at(index) = this->at(index*2+1);
				this->at(index*2+1) = *temp;
				index = index*2+1;
			}
			else{
				temp = &this->at(index);
				this->at(index) = this->at(index*2);
				this->at(index*2) = *temp;
				index = index*2;
			}
		}
			
	}
		
	return *priority;
}