// logger.cpp - logger.h
#include "logger.h"

#include <string>

void Logger::write(
    LogLevel level,
    const std::string& log,
    const std::string& file,
    int line)
{
    if (level < min_level_)
        return;

    // 日志级别转换为字符串
    std::string level_str;
    switch (level)
    {
    case LogLevel::DEBUG:
        level_str = "DEBUG";
        break;
    case LogLevel::INFO:
        level_str = "INFO";
        break;
    case LogLevel::WARN:
        level_str = "WARN";
        break;
    case LogLevel::ERROR:
        level_str = "ERROR";
        break;
    case LogLevel::FATAL:
        level_str = "FATAL";
        break;
    }

    // 格式化日志并打印
    auto str = format_->format(level_str, log, file, line);
    output_->output(str);
}