#pragma once
#include "Zone.h"
#include "NodoTem.h"
#include <string>
#include <sstream>
class ListZone{
	private:
	NodoTem<Zone>* head;
	NodoTem<Zone>* current;
public:
	ListZone(){
		head = nullptr;
		current = nullptr;
	}
	~ListZone(){
		NodoTem<Zone>* current2 = head;
		while(current2){
			NodoTem<Zone>* next = current2->getNext();
			delete current2;
			current2 = next;
		}
	}
	void addZone(Zone* zone){
		NodoTem<Zone>* newNode = new NodoTem<Zone>(zone);
		if(!head){
			head = newNode;
			current = newNode;
		}else{
			current->setNext(newNode);
			current = newNode;
		}
	}
	bool isEmpty(){return !head;}
	bool removeZone(string name) {
		NodoTem<Zone>* current2 = head;
		NodoTem<Zone>* previous = nullptr;
		while (current2) {
			if (current2->getData()->getName() == name) {
				if (previous) {
					previous->setNext(current2->getNext());
				}
				else {
					head = current2->getNext();
				}
				if (current2 == current) {
					current = previous;
				}
				current2->setNext(nullptr);
				delete current2;
				return true;
			}
			previous = current2;
			current2 = current2->getNext();
		}
		return false;
	}
	Zone* findZone(string name){
		NodoTem<Zone>* current2 = head;
		while(current2){
			if(current2->getData()->getName() == name) return current2->getData();
			current2 = current2->getNext();
		}
		return nullptr;
	}
	string toString(){
		stringstream ss;
		NodoTem<Zone>* current2 = head;
		while(current2){
			ss << current2->getData()->toString() << "\n";
			current2 = current2->getNext();
		}
		return ss.str();
	}
};