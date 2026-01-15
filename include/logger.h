#pragma once
// logger.h

#include <memory>
#include <string>

#include "log_format.h"
#include "log_output.h"

enum class LogLevel
{
    DEBUG,
    INFO,
    WARN,
    ERROR,
    FATAL
};

/**
 * @brief 聚合类，委托 LogFormat 和 LogOutput
 */
class Logger
{
private:
    std::shared_ptr<LogFormat> format_;
    std::shared_ptr<LogOutput> output_;

    LogLevel min_level_{ LogLevel::DEBUG };

public:
    /**
     * @brief 设置日志格式化器
     * 
     * @param format LogFormat 指针
     */
    void set_format(LogFormat* format)
    {
        format_.reset(format);
    }

    /**
     * @brief 设置日志输出器
     * 
     * @param output LogOutput 指针
     */
    void set_output(LogOutput* output)
    {
        output_.reset(output);
    }

    /**
     * @brief 设置日志最低输出级别
     * 
     * @param level 日志级别
     */
    void set_min_level(LogLevel level)
    {
        min_level_ = level;
    }

    /**
     * @brief 格式化并写入日志
     * 
     * @param level 日志级别
     * @param log   日志内容
     * @param file  源码文件路径
     * @param line  代码行号
     */
    void write(
        LogLevel level,
        const std::string& log,
        const std::string& file,
        int line
    );
};