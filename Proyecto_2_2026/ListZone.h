#pragma once
#include "Zone.h"
#include "NodoTem.h"
#include <string>
#include <sstream>
#include "ClassExecption.h"
class ListZone{
	private:
	NodoTem<Zone>* head;
	NodoTem<Zone>* current;
public:
	ListZone(){
		head = nullptr;
		current = nullptr;
	}
	~ListZone() { //destructor de la lista, elimina todos los nodos y las zonas que contienen
		NodoTem<Zone>* current2 = head;
		while(current2){
			NodoTem<Zone>* next = current2->getNext();
			delete current2;
			current2 = next;
		}
	}
	void addZone(Zone* zone) { //agrega una nueva zona a la lista, creando un nuevo nodo con la zona.
		NodoTem<Zone>* newNode = new NodoTem<Zone>(zone);
		if(!head){
			head = newNode;
			current = newNode;
		}else{
			current->setNext(newNode);
			current = newNode;
		}
	}
	bool isEmpty() { return !head; } //verifica si la lista está vacía, es decir, si no hay nodos en la lista.
	bool removeZone(string name) { //elimina una zona de la lista buscando por su nombre. Recorre la lista para encontrar el nodo que contiene la zona con el nombre especificado, y si lo encuentra, lo elimina de la lista y libera la memoria asociada a ese nodo.
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
	Zone* findZone(string name) { //busca una zona en la lista por su nombre. Recorre la lista para encontrar el nodo que contiene la zona con el nombre especificado, y si lo encuentra, devuelve un puntero a esa zona. Si no encuentra la zona, devuelve nullptr.
		NodoTem<Zone>* current2 = head;
		while(current2){
			if(current2->getData()->getName() == name) return current2->getData();
			current2 = current2->getNext();
		}
		throw ClassExecption("Zone not found: " + name); // Si no se encuentra la zona, se lanza una excepción personalizada indicando que la zona no fue encontrada.
	}
	string toString(){ //Muestra la lista.
		stringstream ss;
		NodoTem<Zone>* current2 = head;
		while(current2){
			ss << current2->getData()->toString() << "\n";
			current2 = current2->getNext();
		}
		return ss.str();
	}
};