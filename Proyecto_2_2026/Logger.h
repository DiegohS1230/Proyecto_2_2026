#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "ClassExecption.h"
using namespace std;
class Logger
{
private:
    string logFileName;
    string reportFileName;
    ofstream logFile;
public:
    Logger(string logFileName = "output/log.txt",string reportFileName = "output/report.txt");
    ~Logger();
    void write(string message);
    void writeReport(string report);
};

