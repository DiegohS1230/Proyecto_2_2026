#include "Logger.h"
Logger::Logger(string logFileName, string reportFileName) { // Constructor que inicializa los nombres de los archivos de log y reporte, y abre el archivo de log para escritura. Si no se puede abrir el archivo de log, lanza una excepción personalizada ClassExecption con un mensaje de error.
    this->logFileName = logFileName;
    this->reportFileName = reportFileName;
    logFile.open(this->logFileName, ios::out);
	if (!logFile.is_open()) throw ClassExecption("Error: could not open log file.");
}

Logger::~Logger() {if (logFile.is_open()) logFile.close();}

void Logger::write(string message) { // Escribe un mensaje en la consola y en el archivo de log. Si el archivo de log está abierto, también escribe el mensaje en el archivo.
    cout << message << endl;
    if (logFile.is_open())logFile << message << endl;
}

void Logger::writeReport(string report) { // Escribe un reporte en un archivo de reporte. Abre el archivo de reporte para escritura, escribe el reporte en el archivo, y luego cierra el archivo. Si no se puede abrir el archivo de reporte, lanza una excepción personalizada ClassExecption con un mensaje de error.
    ofstream reportFile(reportFileName, ios::out);
	if (!reportFile.is_open()) throw ClassExecption("Error: could not open report file.");
    reportFile << report << endl;
    reportFile.close();
}