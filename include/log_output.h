#pragma once
// log_output.h

#include <string>

/**
 * @brief 日志打印接口类
 */
class LogOutput
{
public:
    /**
     * @brief 打印日志
     *
     * @param log 日志内容
     */
    virtual void output(const std::string& log) = 0;
};
