#include "../include/quicksort.h"
using namespace cxz;

void cxz::QuickSort::swap(int* const x, int* const y){
    int t = *x;
    *x = *y;
    *y = t;
    return;
}

void cxz::QuickSort::quick_sort(int* const p_, const size_t &start, const size_t &end, const size_t &unit_bias_){
    if(start >= end) return;
    int ref = p_[end*unit_bias_];
    int left = start;
    int right = end-1;
    while(left < right){
        while ( p_[left*unit_bias_] < ref && left < right ) 
            left++;
        while ( p_[right*unit_bias_] >= ref && left < right ) 
            right--;
        swap(&p_[left*unit_bias_], &p_[right*unit_bias_]);     
    }
    if(p_[end*unit_bias_] <= p_[left*unit_bias_])
        swap(&p_[end*unit_bias_], &p_[left*unit_bias_]);
    else
        left++;
    if(left) quick_sort(p_, start, left-1, unit_bias_);
    quick_sort(p_, left+1, end, unit_bias_);
}

void cxz::QuickSort::sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_){
    quick_sort(p_, 0, len_-1, unit_bias_);
    std::cout<<"Quick sort"<<std::endl;
    return;
}