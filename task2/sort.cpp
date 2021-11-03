#include <stdlib.h>
#include <iostream>
#include <time.h>

void random_array(int * const p, const size_t &number)
{
    size_t max_value = number;
    for(size_t i=0; i<number; i++)
        p[i] = rand()%max_value;
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

void bubble_sort(int* const p_, const size_t &len_, const size_t &unit_bias_=1){
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

void insertion_sort(int* const p_, const size_t &len_, const size_t &unit_bias_=1){
    for (size_t i = 1; i < len_; i++){
        int temp = *(p_+i*unit_bias_);

        // int j = i-1;
        // while ( (temp < *(p_+j*unit_bias_)) && (j>= 0))
        // {
        //     *(p_+(j+1)*unit_bias_) = *(p_+j*unit_bias_);
        //     j--;
        // }
        // *(p_+(j+1)*unit_bias_) = temp;

        size_t j = i;
        while ( (temp < *(p_+(j-1)*unit_bias_)) && (j>= 1))
        {
            *(p_+j*unit_bias_) = *(p_+(j-1)*unit_bias_);
            j--;
        }
        *(p_+j*unit_bias_) = temp;
        
        // for (size_t ind = 0; ind < len_; ind++){
        //     std::cout<<*(p_+ind*unit_bias_)<<' ';
        // }
        // std::cout<<std::endl;            
    }  
    return;
}

void selection_sort(int* const p_, const size_t &len_, const size_t &unit_bias_=1)
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


void sort_array_3d(int *** const pp_, const size_t &length_, const size_t &width_, const size_t &height_){
    size_t len[3] = {height_, width_, length_};
    size_t len1[3] = {length_, length_, width_};
    size_t len2[3] = {width_, height_, height_};
    size_t unit_bias[3] = {1, height_, width_*height_};
    size_t i_parameter[3] = {width_*height_, width_*height_, height_};
    size_t j_parameter[3] = {height_, 1, 1};
    for (size_t iter = 0; iter < 3; iter++)
    {
        for(size_t i = 0; i<len1[iter]; i++){
            for(size_t j = 0; j<len2[iter]; j++){
                // insertion_sort((int*)pp_[0][0]+i*i_parameter[iter]+j*j_parameter[iter], len[iter], unit_bias[iter]);
                // bubble_sort((int*)pp_[0][0]+i*i_parameter[iter]+j*j_parameter[iter], len[iter], unit_bias[iter]);
                selection_sort((int*)pp_[0][0]+i*i_parameter[iter]+j*j_parameter[iter], len[iter], unit_bias[iter]);
            }
        }
    }

    // for(size_t i = 0; i<length_; i++){
    //     for(size_t j = 0; j<width_; j++){
    //         sort_1d(p_+i*width_*height_+j*height_, height_, 1, type_);
    //     }
    // }
    // for(size_t i = 0; i<length_; i++){
    //     for(size_t j = 0; j<height_; j++){
    //         sort_1d(p_+i*width_*height_+j, width_, height_, type_);
    //     }
    // }
    // for(size_t i = 0; i<width_; i++){
    //     for(size_t j = 0; j<height_; j++){
    //         sort_1d(p_+i*height_+j, length_, width_*height_, type_);
    //     }
    // }
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
    sort_array_3d(pp,length,width,height);
    // print_array_3d(pp,length,width,height);

    //// test
    std::cout<<"error number: "<<test(p,length,width,height)<<std::endl;

    // free
    free_array_3d(pp,length,width,height);
    free(p);
    return 0;
}