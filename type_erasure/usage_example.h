// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once
#include <string_view>
#include <functional>
#include <iostream>
#include <cstdio>

using logger_type = std::function<void(std::string_view)>;

void log_dispatch(const logger_type& log_fn, std::string_view message)
{
   log_fn(message);
}

void my_logger(std::string_view s)
{
   std::puts(s.data());
}

void run_usage_example()
{
   auto lambda_printer = [=](std::string_view s) {std::cout << s << "\n"; };
   log_dispatch(lambda_printer, "Hello Lambda!");

   auto function_pointer_printer = my_logger;
   log_dispatch(function_pointer_printer, "Hello Function Pointer");
}