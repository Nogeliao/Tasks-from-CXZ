#include "../include/array.h"

using namespace cxz;

void cxz::random_array(int * const p, const size_t &number)
{
    size_t max_value = number;
    for(size_t i=0; i<number; i++)
        p[i] = rand() % max_value;
}

int cxz::test(const int * const p, const size_t &length, const size_t &width, const size_t &height)
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

int *** cxz::array_3d(const int * const p, const size_t &length, const size_t &width, const size_t &height)
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

void cxz::free_array_3d(int *** pp, const size_t &length, const size_t &width, const size_t &height)
{
    for(size_t i=0; i<length; i++)
        free(pp[i]);
    free(pp);
    pp = NULL;
}

void cxz::print_array_3d(int *** const pp, const size_t &length, const size_t &width, const size_t &height)
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

