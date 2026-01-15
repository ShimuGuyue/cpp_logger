// log_output_console.cpp - log_output_console.h
#include "log_output_console.h"

#include <iostream>
#include <string>

void LogOutputConsole::output(const std::string& log)
{
    std::clog << log << std::endl;
}
