// log_output_file.cpp - log_output_file.h

#include "log_output_file.h"

#include <string>

bool LogOutputFile::open(const std::string& file_path)
{
    ofs_.open(file_path, std::ios::app);
    return ofs_.is_open();
}

void LogOutputFile::output(const std::string& log)
{
    ofs_ << log << '\n';
}
