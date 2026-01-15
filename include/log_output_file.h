#pragma once
// log_output_file.h

#include <fstream>
#include <string>

#include "log_output.h"

class LogOutputFile : public LogOutput
{
private:
    std::ofstream ofs_;

public:
    /**
     * @brief 打开日志输出文件
     *
     * @param filePath 日志输出文件路径
     *
     * @return 文件是否成功打开
     */
    bool open(const std::string& filePath);

    /**
     * @brief 打印日志
     *
     * @param log 日志内容
     */
    void output(const std::string& log);
};

