#include <stdlib.h>
#include <iostream>

#ifndef _THREE_DIMENSIONAL_ARRAY_SORT_H_
#define _THREE_DIMENSIONAL_ARRAY_SORT_H_

#endif

namespace three_dimensional_array_sort{
    class ThreeDimensionalArraySort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1) = 0;
            void sort_array_3d(int *** const pp_, const size_t &length_, const size_t &width_, const size_t &height_);
    };

    class BubbleSort: public ThreeDimensionalArraySort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

    class InsertionSort: public ThreeDimensionalArraySort{
        public:
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

    class SelectionSort: public ThreeDimensionalArraySort{
        public: 
            virtual void sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1);
    };

}