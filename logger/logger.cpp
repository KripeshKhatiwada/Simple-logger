#include "Logger.h"
#include <iostream>
#include <sstream>
#include <ctime>

std::string LogEntry::format() const {
    std::ostringstream oss;
    oss << "[" << timestamp << "] " << logLevelToString(level) << ": " << message;
    return oss.str();
}

std::string LogEntry::logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        default: return "UNKNOWN";
    }
}

Logger::Logger(const std::string& filename) {
    logFile.open(filename, std::ios::app);
    if (!logFile) {
        std::cerr << "Error: Could not open log file!" << std::endl;
    }
}

Logger::~Logger() {
    if (logFile.is_open()) logFile.close();
}

std::string Logger::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    std::tm* timeInfo = std::localtime(&now);
    std::ostringstream oss;
    oss << (timeInfo->tm_year + 1900) << "-"
        << (timeInfo->tm_mon + 1) << "-"
        << timeInfo->tm_mday << " "
        << timeInfo->tm_hour << ":"
        << timeInfo->tm_min << ":"
        << timeInfo->tm_sec;
    return oss.str();
}

void Logger::log(LogLevel level, const std::string& message) {
    LogEntry entry{level, message, getCurrentTime()};
    std::cout << entry.format() << std::endl;
    if (logFile) logFile << entry.format() << std::endl;
}
