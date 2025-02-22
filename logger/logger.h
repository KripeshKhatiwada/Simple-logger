#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

enum LogLevel { INFO, WARNING, ERROR };

struct LogEntry {
    LogLevel level;
    std::string message;
    std::string timestamp;

    std::string format() const;
    static std::string logLevelToString(LogLevel level);
};

class Logger {
private:
    std::ofstream logFile;

    std::string getCurrentTime();

public:
    Logger(const std::string& filename);
    ~Logger();

    void log(LogLevel level, const std::string& message);
};

#endif
