// #include <stdlib.h>
// #include <iostream>
#include <time.h>
#include <string.h>
#include "../include/sort.h"
#include "../include/array.h"
#include "../include/quicksort.h"
using namespace cxz;

int main(int argc, char *argv[])
{
    //// input
    //   dynamic input
    const size_t length = atoi(argv[1]);
    const size_t width = atoi(argv[2]);
    const size_t height = atoi(argv[3]);

    //// allocate memory
    size_t number = length*width*height;
    int *p = (int *)malloc(sizeof(int)*number);
    srand((unsigned)time(NULL));
    random_array(p,number);

    //// form 3d array
    int *** pp =  array_3d(p,length,width,height);
    print_array_3d(pp,length,width,height);

    //// sort the ed array
    OneDimensionalSort *ps = new QuickSort();
    cxz::sort_array_3d(pp, length, width, height, *ps);
    print_array_3d(pp,length,width,height);

    //// test
    std::cout<<"error number: "<<test(p,length,width,height)<<std::endl;

    // free
    free_array_3d(pp,length,width,height);
    free(p);
    return 0;
}