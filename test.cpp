// test.cpp
#include <iostream>

#include "x_log_format.h"
#include "log_output_console.h"
#include "log_output_file.h"
#include "logger.h"

int main()
{
    XLogFormat xLogFormat;
    auto log = xLogFormat.format("INFO", "test XLogFormat::format()", __FILE__, __LINE__);
    std::cout << log;

    LogOutputConsole consoleOutput;
    consoleOutput.output("test LogOutputConsole::output()");

    LogOutputFile fileOutput;
    fileOutput.open("test.log");
    fileOutput.output("test LogOutputFile::output()");

    Logger logger;
    logger.set_format(new XLogFormat);
    logger.set_output(new LogOutputConsole);
    //auto fileOutput_ptr = new LogOutputFile;
    //fileOutput_ptr->open("test1.log");
    //logger.set_output(fileOutput_ptr);
    for (auto level : { LogLevel::DEBUG, LogLevel::INFO, LogLevel::WARN, LogLevel::ERROR, LogLevel::FATAL })
    {
        logger.set_min_level(level);
        logger.write(LogLevel::DEBUG, "test Logger::write()", __FILE__, __LINE__);
        logger.write(LogLevel::INFO, "test Logger::write()", __FILE__, __LINE__);
        logger.write(LogLevel::WARN, "test Logger::write()", __FILE__, __LINE__);
        logger.write(LogLevel::ERROR, "test Logger::write()", __FILE__, __LINE__);
        logger.write(LogLevel::FATAL, "test Logger::write()", __FILE__, __LINE__);
        std::cout << std::endl;
    }
}
