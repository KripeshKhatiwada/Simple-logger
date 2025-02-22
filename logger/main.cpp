#include "Logger.h"

int main() {
    Logger logger("log.txt");

    logger.log(LogLevel::INFO, "System initialized.");
    logger.log(LogLevel::WARNING, "Low battery detected.");
    logger.log(LogLevel::ERROR, "Critical failure: Overheating!");

    return 0;
}
