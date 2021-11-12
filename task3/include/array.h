#include <stdlib.h>
#include <iostream>

#ifndef _CXZ_ARRAY_H_
#define _CXZ_ARRAY_H_

namespace cxz{
    void random_array(int * const p, const size_t &number);
    int test(const int * const p, const size_t &length, const size_t &width, const size_t &height);
    int *** array_3d(const int * const p, const size_t &length, const size_t &width, const size_t &height);
    void free_array_3d(int *** pp, const size_t &length, const size_t &width, const size_t &height);
    void print_array_3d(int *** const pp, const size_t &length, const size_t &width, const size_t &height);
}

#endif
