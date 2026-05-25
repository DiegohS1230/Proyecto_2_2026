#pragma once
template <typename T>
class NodoTem{
	private:
	T* data;
	NodoTem<T>* next;
public:
	NodoTem(T* data){
		this->data = data;
		this->next = nullptr;
	}
	~NodoTem(){
	}
	T* getData(){
		return data;
	}
	NodoTem<T>* getNext(){
		return next;
	}
	void setData(T* data){
		this->data = data;
	}
	void setNext(NodoTem<T>* next){
		this->next = next;
	}
};

