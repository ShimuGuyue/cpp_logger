
cmake_minimum_required (VERSION 3.10)

# 如果支持，为 MSVC 编译器启用热重载。
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("cpp_logger")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable (test
	"test.cpp"
	"src/x_log_format.cpp"
	"src/log_output_console.cpp"
	"src/log_output_file.cpp"
	"src/logger.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET test PROPERTY CXX_STANDARD 20)
endif()

