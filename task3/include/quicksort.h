#include <stdlib.h>
#include <iostream>
#include "../include/sort.h"

#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

namespace cxz{
    class QuickSort: public OneDimensionalSort{
        public: 
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
            void swap(int* const x, int* const y);
            void quick_sort(int* const p_, const size_t &start, const size_t &end, const size_t &unit_bias_ = 1);
    };
}

#endif