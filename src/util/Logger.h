#ifndef UTIL_LOGGER_H
#define UTIL_LOGGER_H

#include <fstream>
#include <map>
#include <string>

using namespace std;

class Logger {
private:
    static Logger* instance;
    Logger() {
        logLevelString.insert(pair<LogLevel, string>(Logger::Info, "Info"));
        logLevelString.insert(pair<LogLevel, string>(Logger::Warning, "Warning"));
        logLevelString.insert(pair<LogLevel, string>(Logger::Error, "Error"));
    }
    ofstream file;
    enum LogLevel {
        Info,
        Warning,
        Error
    };
    map<LogLevel, string> logLevelString;
    void _log(LogLevel level, string text, int line, char* fileName);
public:
    ~Logger();
    static Logger* inst();
    void setFileName(string fileName);
    void logError(string text, int line, char* fileName);
    void logWarning(string text, int line, char* fileName);
    void logInfo(string text, int line, char* fileName);
};

#define LOG_INFO(info) Logger::inst()->logInfo(info, __LINE__, __FILE__);
#define LOG_WARNING(info) Logger::inst()->logWarning(info, __LINE__, __FILE__);
#define LOG_ERROR(info) Logger::inst()->logError(info, __LINE__, __FILE__);

#endif
