// x_log_format.cpp - x_log_format.h
#include "x_log_format.h"

#include <chrono>
#include <format>
#include <sstream>
#include <string>

/**
 * @brief   获取当前时间字符串
 *
 * @return  当前时间字符串，格式为 "YYYY-MM-DD HH:MM:SS"
 */
static std::string get_time()
{
    auto time{ std::chrono::system_clock::now() };
    auto local_time{ std::chrono::zoned_time{ std::chrono::current_zone(), time } };
    return std::format("{:%F %T}", local_time);
}

std::string XLogFormat::format(
    const std::string& level,
    const std::string& log,
    const std::string& file,
    int line)
{
    std::stringstream ss;
    ss << get_time() << " [" << level << "] " << file << ":" << line << ' ' << log << '\n';
    return ss.str();
}
