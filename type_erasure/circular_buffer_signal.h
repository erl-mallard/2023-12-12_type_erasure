#pragma once
#include "types.h"

class CircularBufferSignal
{
public:
   Sample_Type get_sample() const { return sample_; }
   void write_sample(Sample_Type s) { sample_ = s; }

private:
   Sample_Type sample_{};
};