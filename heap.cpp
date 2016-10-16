#include <vector>

template <class type> class Heap{
	public:
		bool add(type node);
		void sort();
		bool remove(type node);
		type popQueue();
};

template<class type> bool Heap<type>::add(type node){
	return false;
}

template<class type> void Heap<type>::sort(){
	int x = 1;
}

template<class type> bool Heap<type>::remove(type node){
	return false;
}

template<class type> type Heap<type>::popQueue(){
	int x = 1;
	return x;
}