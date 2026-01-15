// test.cpp
#include <iostream>

#include "x_log_format.h"

int main()
{
    XLogFormat xLogFormat;
    auto log = xLogFormat.format("INFO", "test XLogFormat::format()", __FILE__, __LINE__);
    std::cout << log << std::endl;
}
