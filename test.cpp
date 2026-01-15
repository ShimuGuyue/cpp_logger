// test.cpp
#include <iostream>

#include "x_log_format.h"
#include "log_output_console.h"
#include "log_output_file.h"

int main()
{
    XLogFormat xLogFormat;
    auto log = xLogFormat.format("INFO", "test XLogFormat::format()", __FILE__, __LINE__);
    std::cout << log << std::endl;

    LogOutputConsole consoleOutput;
    consoleOutput.output("test LogOutputConsole::output()");

    LogOutputFile fileOutput;
    fileOutput.open("test.log");
    fileOutput.output("test LogOutputFile::output()");
}
