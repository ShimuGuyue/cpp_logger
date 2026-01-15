#pragma once
// log_output_console.h

#include <string>

#include "log_output.h"

class LogOutputConsole : public LogOutput
{
public:
    /**
     * @brief 打印日志
     *
     * @param log 日志内容
     */
    void output(const std::string& log);
};

