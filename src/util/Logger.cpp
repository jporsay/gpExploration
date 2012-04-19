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

void Logger::logInfo(string text) {
    this->_log(Logger::Info, text);
}

void Logger::logWarning(string text) {
    this->_log(Logger::Warning, text);
}

void Logger::logError(string text) {
    this->_log(Logger::Error, text);
}

void Logger::_log(LogLevel level, string text) {
    file << "[" << logLevelString[level] << "] " <<text << endl;
}

Logger::~Logger() {
    file.close();
}
