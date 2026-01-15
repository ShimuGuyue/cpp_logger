#pragma once
// log_format.h

#include <string>

/**
 * @brief LogFormat 日志格式化接口类
 */
class LogFormat
{
public:
    /**
     * @brief 格式化日志内容为字符串
     *
     * @param level 日志级别
     * @param log   日志内容
     * @param file  源码文件路径
     * @param line  代码行号
     *
     * @return 格式化后的日志字符串
     */
    virtual std::string format(
        const std::string& level,
        const std::string& log,
        const std::string& file,
        int line
    ) = 0;
};

