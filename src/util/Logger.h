#ifndef LOGGER_H_
#define LOGGER_H_

#include <fstream>
#include <map>

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
    void _log(LogLevel level, string text);
public:
    ~Logger();
    static Logger* inst();
    void setFileName(string fileName);
    void logError(string text);
    void logWarning(string text);
    void logInfo(string text);
};

#define LOG_INFO(info) Logger::inst()->logInfo(info)
#define LOG_WARNING(info) Logger::inst()->logWarning(info)
#define LOG_ERROR(info) Logger::inst()->logError(info)

#endif
