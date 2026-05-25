#pragma once
#include <iostream>
#include <string>
using namespace std;
class Zone {
private:
     string name;
     int destruction;
     int corruption;
     int civilians;
public:
    Zone(string name = "", int destruction = 0, int corruption = 0, int civilians = 0);
	~Zone();
    //gets
    string getName();
	int getDestruction();
	int getCorruption();
	int getCivilians();
    //sets
	void setName(string name);
	void setDestruction(int destruction);
	void setCorruption(int corruption);
	void setCivilians(int civilians);
    // Simulation behavior
    void damage(int amount);
    void heal(int amount);
    void increaseCorruption(int amount);
    bool isCollapsed();
	string toString();
};

