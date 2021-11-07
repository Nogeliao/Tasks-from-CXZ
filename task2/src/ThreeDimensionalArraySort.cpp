#include "../include/ThreeDimensionalArraySort.h"

using namespace three_dimensional_array_sort;

void three_dimensional_array_sort::sort_array_3d(int *** const pp_, const size_t &length_, const size_t &width_, const size_t &height_, OneDimensionalSort &obj_){
    bool direction[3][3] = {{0,0,1},{0,1,0},{1,0,0}}; // describe the direction
    for(size_t iter=0; iter<3; iter++){
        bool length_flag = direction[iter][0];
        bool width_flag = direction[iter][1];
        bool height_flag = direction[iter][2];
        for(size_t i=0; i<=(length_-1)*(!length_flag); i++){
            for(size_t j=0; j<=(width_-1)*(!width_flag); j++){
                for(size_t k=0; k<=(height_-1)*(!height_flag); k++){
                    int* start_point = & pp_[i][j][k];
                    size_t len = length_ * length_flag + width_ * width_flag + height_ * height_flag;
                    size_t step = (int *)&pp_[length_flag][width_flag][height_flag] - (int *)&pp_[0][0][0];
                    obj_.sort_array_1d(start_point, len, step);
                }
            }
        }
    }
}

void three_dimensional_array_sort::BubbleSort::sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_){
    for(size_t i = 0; i<len_-1; i++){
        bool no_exchange = 1;
        for(size_t j = 0; j<len_-i-1; j++){
            if( *(p_ + j*unit_bias_) > *(p_ + (j+1)*unit_bias_) )
            {
                int temp = *(p_ + j*unit_bias_);
                *(p_ + j*unit_bias_) = *(p_ + (j+1)*unit_bias_);
                *(p_ + (j+1)*unit_bias_)=temp;
                no_exchange = 0;
            }
        }
        if(no_exchange) break;
    }
    std::cout<<"Bubble sort"<<std::endl;
    return;
}

void three_dimensional_array_sort::InsertionSort::sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_){
    for (size_t i = 1; i < len_; i++){
        int temp = *(p_+i*unit_bias_);
        size_t j = i;
        while ( (temp < *(p_+(j-1)*unit_bias_)) && (j>= 1))
        {
            *(p_+j*unit_bias_) = *(p_+(j-1)*unit_bias_);
            j--;
        }
        *(p_+j*unit_bias_) = temp;           
    }
    // std::cout<<"Insertion sort"<<std::endl;  
    return;
}

void three_dimensional_array_sort::SelectionSort::sort_array_1d(int* const p_, const size_t &len_, const size_t &unit_bias_){
    for (size_t i = 0; i < len_-1; i++)
    {
        size_t min = i;
        for (size_t j = i+1; j < len_; j++)
            if(*(p_+min*unit_bias_) > *(p_+j*unit_bias_))
                min = j;

        int temp = *(p_+i*unit_bias_);
        *(p_+i*unit_bias_) = *(p_+min*unit_bias_);
        *(p_+min*unit_bias_) = temp;      
    }
    // std::cout<<"Selection sort"<<std::endl;
    return;
}
