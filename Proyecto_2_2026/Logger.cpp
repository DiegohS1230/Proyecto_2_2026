#include "Logger.h"
Logger::Logger(string logFileName, string reportFileName) {
    this->logFileName = logFileName;
    this->reportFileName = reportFileName;
    logFile.open(this->logFileName, ios::out);
	if (!logFile.is_open()) throw ClassExecption("Error: could not open log file.");
}

Logger::~Logger() {if (logFile.is_open()) logFile.close();}

void Logger::write(string message) {
    cout << message << endl;
    if (logFile.is_open())logFile << message << endl;
}

void Logger::writeReport(string report) {
    ofstream reportFile(reportFileName, ios::out);
	if (!reportFile.is_open()) throw ClassExecption("Error: could not open report file.");
    reportFile << report << endl;
    reportFile.close();
}