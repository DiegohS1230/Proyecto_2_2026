#include "Zone.h"
#include <sstream>
Zone::Zone(string name, int destruction, int corruption, int civilians){
    this->name = name;
    this->destruction = destruction;
    this->corruption = corruption;
    this->civilians = civilians;
}

Zone::~Zone(){ //void
}
//gets
string Zone::getName(){return name;}
int Zone::getDestruction(){return destruction;}
int Zone::getCorruption(){return corruption;}
int Zone::getCivilians(){return civilians;}
//sets
void Zone::setName(string name){this->name = name;}
void Zone::setDestruction(int destruction){this->destruction = destruction;}
void Zone::setCorruption(int corruption){this->corruption = corruption;}
void Zone::setCivilians(int civilians){
    if (civilians < 0) civilians = 0;
    this->civilians = civilians;
}
// Simulation behavior
void Zone::damage(int amount) {
    setDestruction(destruction + amount);
    setCivilians(civilians - amount * 3);
}
void Zone::heal(int amount){
    this->destruction -= amount;
    if (this->destruction < 0) this->destruction = 0;
	this->civilians += amount * 2;
}
void Zone::increaseCorruption(int amount){
    this->corruption += amount;
	if (this->corruption > 100) this->corruption = 100;
}
bool Zone::isCollapsed(){
    if(destruction >= 100 || corruption >= 100 || civilians <= 0) return true;
    return false;
}
//toString
string Zone::toString(){
    stringstream ss;
     ss << "Zone: " << name << "\n";
     ss << "Destruction: " << destruction << "\n";
     ss << "Corruption: " << corruption << "\n";
     ss << "Civilians: " << civilians << "\n";
	 return ss.str();
}
