// #include <stdlib.h>
// #include <iostream>
#include <time.h>
#include <string.h>
#include "../include/ThreeDimensionalArraySort.h"
using namespace three_dimensional_array_sort;

void random_array(int * const p, const size_t &number)
{
    size_t max_value = number;
    for(size_t i=0; i<number; i++)
        p[i] = rand() % max_value;
}

int test(const int * const p, const size_t &length, const size_t &width, const size_t &height)
{
    size_t error = 0;
    for(size_t i=0; i<length-1; i++)
        for(size_t j=0; j<width-1; j++)
            for(size_t k=0; k<height-1; k++){
                size_t temp_index = i * width * height + j * height + k;
                if((p[temp_index] > p[temp_index+1]) || (p[temp_index] > p[temp_index+height]) || (p[temp_index] > p[temp_index+width*height])){
                    error++;
                    std::cout<<"----------find the error "<< error <<"-------------"<<std::endl;
                    std::cout<<"p["<<i<<"]"<<"["<<j<<"]"<<"["<<k<<"] = "<< p[temp_index] <<std::endl;
                    std::cout<<"p["<<i<<"]"<<"["<<j<<"]"<<"["<<k+1<<"] = "<< p[temp_index+1] <<std::endl;
                    std::cout<<"p["<<i<<"]"<<"["<<j+1<<"]"<<"["<<k<<"] = "<< p[temp_index+height] <<std::endl;
                    std::cout<<"p["<<i+1<<"]"<<"["<<j<<"]"<<"["<<k<<"] = "<< p[temp_index+width*height] <<std::endl;
                }
            }
    return error;
}

int *** array_3d(const int * const p, const size_t &length, const size_t &width, const size_t &height)
{
    int ***pp = NULL;
    pp = (int ***) malloc(sizeof(int**)*length);
    for(size_t i = 0; i < length; i++){
        pp[i] = (int **)malloc(sizeof(int*)*width);
        for (size_t j = 0; j < width; j++){
            pp[i][j] = (int*)(p+i*width*height+j*height);
        }
    }
    return pp;
}

void free_array_3d(int *** pp, const size_t &length, const size_t &width, const size_t &height)
{
    for(size_t i=0; i<length; i++)
        free(pp[i]);
    free(pp);
    pp = NULL;
}

void print_array_3d(int *** const pp, const size_t &length, const size_t &width, const size_t &height)
{
    std::cout<<"--------print the array----------"<<std::endl;
    for(size_t i = 0; i<length;i++){
        for(size_t j = 0; j < width; j++){
            for(size_t k = 0; k<height; k++){
                std::cout<<pp[i][j][k]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
    }   
}

void bubble_sort(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1){
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
    return;
}

void insertion_sort(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1){
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
    return;
}

void selection_sort(int* const p_, const size_t &len_, const size_t &unit_bias_ = 1)
{
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
    
    return;
}

void sort_array_3d(int *** const pp, const size_t &length, const size_t &width, const size_t &height, char* const sort_method)
{
    bool direction[3][3] = {{0,0,1},{0,1,0},{1,0,0}}; // describe the direction
    for(size_t iter=0; iter<3; iter++){
        bool length_flag = direction[iter][0];
        bool width_flag = direction[iter][1];
        bool height_flag = direction[iter][2];
        for(size_t i=0; i<=(length-1)*(!length_flag); i++){
            for(size_t j=0; j<=(width-1)*(!width_flag); j++){
                for(size_t k=0; k<=(height-1)*(!height_flag); k++){
                    int* start_point = & pp[i][j][k];
                    size_t len = length * length_flag + width * width_flag + height * height_flag;
                    size_t step = (int *)&pp[length_flag][width_flag][height_flag] - (int *)&pp[0][0][0];
                    if( strcmp(sort_method, "selection_sort") == 0 ){
                        selection_sort(start_point, len, step);
                        // std::cout<<"selection_sort"<<std::endl;
                    }   
                    else if( strcmp(sort_method, "insertion_sort") == 0 ){
                        insertion_sort(start_point, len, step);
                        // std::cout<<"insertion_sort"<<std::endl;
                    }     
                    else if( strcmp(sort_method, "bubble_sort") == 0 ){
                        bubble_sort(start_point, len, step);
                        // std::cout<<"bubble_sort"<<std::endl;
                    }
                        
                }
            }
        }
        
    }
    return;
}

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
    // sort_array_3d(pp,length,width,height,argv[4]);
    OneDimensionalSort *ps;
    if( strcmp(argv[4], "selection_sort") == 0 ){
        SelectionSort sel_sort;
        ps = &sel_sort;
    }   
    else if( strcmp(argv[4], "insertion_sort") == 0 ){
        InsertionSort ins_sort;
        ps = &ins_sort;
    }     
    else if( strcmp(argv[4], "bubble_sort") == 0 ){
        BubbleSort bub_sort;
        ps = &bub_sort;
    }
    three_dimensional_array_sort::sort_array_3d(pp, length, width, height, *ps);
    print_array_3d(pp,length,width,height);

    //// test
    std::cout<<"error number: "<<test(p,length,width,height)<<std::endl;

    // free
    free_array_3d(pp,length,width,height);
    free(p);
    return 0;
}