// ReSharper disable CppNonInlineFunctionDefinitionInHeaderFile
#pragma once
#include "circular_buffer_signal.h"
#include "signal_view.h"

void print_sample(const signal_view& sv)
{
   std::cout << sv.get_sample() << std::endl;
}

void run_signal_view_example()
{
   CircularBufferSignal d_sensor_samples{};
   d_sensor_samples.write_sample(42);

   print_sample(signal_view{d_sensor_samples});
}