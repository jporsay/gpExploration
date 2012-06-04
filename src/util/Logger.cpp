#include "Logger.h"

Logger* Logger::instance = NULL;

Logger* Logger::inst() {
    if (instance == NULL) {
        instance = new Logger();
    }
    return instance;
}

void Logger::setFileName(string fileName) {
    file.open(fileName.c_str());
}

void Logger::logInfo(string text, int line, char* fileName) {
    this->_log(Logger::Info, text, line, fileName);
}

void Logger::logWarning(string text, int line, char* fileName) {
    this->_log(Logger::Warning, text, line, fileName);
}

void Logger::logError(string text, int line, char* fileName) {
    this->_log(Logger::Error, text, line, fileName);
}

void Logger::_log(LogLevel level, string text, int line, char* fileName) {
    file << "[" << logLevelString[level] << "][ " << fileName << ":" << line << "]" << text << endl;
    file.flush();
}

Logger::~Logger() {
    file.close();
}
