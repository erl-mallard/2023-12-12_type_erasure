#pragma once

#include "types.h"

class signal_view
{
public:
   template <typename Signal>
   explicit signal_view(const Signal& signal) :
      object{ &signal },
      get_samples_impl {
          [](const void* obj) {
             return static_cast<const Signal*>(obj)->get_sample();
          }
      } {}

   Sample_Type get_sample() const { return get_samples_impl(object); }

private:
   const void* object;
   Sample_Type (*get_samples_impl)(const void*);
};
