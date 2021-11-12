#include <stdlib.h>
#include <iostream>

#ifndef _THREE_DIMENSIONAL_ARRAY_SORT_H_
#define _THREE_DIMENSIONAL_ARRAY_SORT_H_

namespace cxz{
    class OneDimensionalSort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1) = 0;
    };

    class BubbleSort: public OneDimensionalSort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

    class InsertionSort: public OneDimensionalSort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

    class SelectionSort: public OneDimensionalSort{
        public: 
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

    void sort_array_3d(int *** const pp_, const size_t &length_, const size_t &width_, const size_t &height_, OneDimensionalSort &obj_);
}

#endif