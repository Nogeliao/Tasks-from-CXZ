#include <stdlib.h>
#include <iostream>
#include <time.h>

void bubble_sort(int *p_, int len_, int unit_bias_=1);
// void bubble_sort_3d(int *p_, int length_, int width_, int height_ );
void insertion_sort(int *p_, int len_, int unit_bias_=1);
// void insertion_sort_3d(int *p_, int length_, int width_, int height_);
void sort_1d(int *p_, int len_, int unit_bias_=1, int type_=0);
void sort_3d(int *p_, int length_, int width_, int height_, int type_=0);

int main(int argc, char *argv[])
{
    //// input
    // dynamic input
    // const size_t length = atoi(argv[1]);
    // const size_t width = atoi(argv[2]);
    // const size_t height = atoi(argv[3]);
    // static input
    const size_t length = 4;
    const size_t width = 5;
    const size_t height = 6;

    //// allocate memory
    size_t number = length*width*height;
    int *p = (int *)malloc(sizeof(int)*number);
    srand((unsigned)time(NULL));
    for(size_t i=0;i<number;i++){
        p[i] = rand()%100;
        std::cout<<p[i]<<' ';
    }
    std::cout<<'\n';
    std::cout<<std::endl;

    ////create an array pointer , an pointer array , a 3-dimension pointer 
    // pp is an array pointer
    // int (*pp)[width][height] = (int(*)[width][height])p;
    // pp is an pointer array

        // int **pp[length];
        // // write your code here
        // for(size_t i=0;i<length;i++){
        //     pp[i] = (int **)malloc(sizeof(int*)*width);
        //     for(size_t j=0;j<width;j++){
        //         pp[i][j] = (int*)(p+i*width*height+j*height);
        //     }
        // }

    // 3-dimension pointer
    
        int ***pp = NULL;
        // write your code here
        pp = (int ***) malloc(sizeof(int**)*length);
        for(size_t i = 0; i < length; i++){
            pp[i] = (int **)malloc(sizeof(int*)*width);
            for (size_t j = 0; j < width; j++){
                pp[i][j] = (int*)(p+i*width*height+j*height);
                // pp[i][j] = (int *)malloc(sizeof(int)*height);
            }
        }


    for(size_t i = 0; i<length;i++){
        for(size_t j = 0; j < width; j++){
            for(size_t k = 0; k<height; k++){
                std::cout<<pp[i][j][k]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    // for(size_t i = 0; i<length; i++){
    //     for(size_t j = 0; j<width; j++){
    //         std::cout<<*(p+i*width*height+j*height)<<' '<<p+i*width*height+j*height<<' ';
    //         std::cout<<*((int*)pp+i*width*height+j*height)<<' '<<pp+i*width*height+j*height<<' ';
    //     }
    //     std::cout<<std::endl;
    // }

    
    // insertion_sort

    // int a[5] = {23,76,12,65,89};
    // insertion_sort(a,5,1);
    // for (size_t i = 0; i < 5; i++)
    // {
    //     std::cout<<a[i]<<' ';
    // }
    // std::cout<<std::endl<<std::endl;
    
    // insertion_sort_3d(p, length, width, height);
    sort_3d(p, length, width, height);

    // bubble sort

    // for(size_t i = 0; i<length; i++){
    //     for(size_t j = 0; j<width; j++){
    //         bool no_exchange = 1;
    //         for(size_t k = 0; k<height-1; k++){
    //             for(size_t kt = 0; kt<height-k-1; kt++){
    //                 if(pp[i][j][kt]>pp[i][j][kt+1]){
    //                     int temp = pp[i][j][kt];
    //                     pp[i][j][kt] = pp[i][j][kt+1];
    //                     pp[i][j][kt+1]=temp;
    //                     no_exchange = 0;
    //                 }
    //             }
    //             if(no_exchange) break;
    //         }
    //     }
    // }

    // for(size_t i = 0; i<length; i++){
    //     for(size_t k = 0; k<height; k++){
    //         bool no_exchange = 1;
    //         for(size_t j = 0; j<width-1; j++){
    //             for(size_t jt = 0; jt<width-j-1; jt++){
    //                 if(pp[i][jt][k]>pp[i][jt+1][k]){
    //                     int temp = pp[i][jt][k];
    //                     pp[i][jt][k] = pp[i][jt+1][k];
    //                     pp[i][jt+1][k]=temp;
    //                     no_exchange = 0;
    //                 }
    //             }
    //             if(no_exchange) break;
    //         }
    //     }
    // }

    // for(size_t j = 0; j<width; j++){
    //     for(size_t k = 0; k<height; k++){
    //         bool no_exchange = 1;
    //         for(size_t i = 0; i<length-1; i++){
    //             for(size_t it = 0; it<length-i-1; it++){
    //                 if(pp[it][j][k]>pp[it+1][j][k]){
    //                     int temp = pp[it][j][k];
    //                     pp[it][j][k] = pp[it+1][j][k];
    //                     pp[it+1][j][k]=temp;
    //                     no_exchange = 0;
    //                 }
    //             }
    //             if(no_exchange) break;
    //         }
    //     }
    // }

    // output
    for(size_t i = 0; i<length;i++){
        for(size_t j = 0; j < width; j++){
            for(size_t k = 0; k<height; k++){
                std::cout<<pp[i][j][k]<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
        std::cout<<std::endl;
        free(pp[i]);
    }
        
    std::cout<<std::endl;
    free(p);
    free(pp);
    return 0;
}


void bubble_sort(int *p_, int len_, int unit_bias_){
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
}

// void bubble_sort_3d(int *p_, int length_, int width_, int height_){
//     for(size_t i = 0; i<length_; i++){
//         for(size_t j = 0; j<width_; j++){
//             bubble_sort(p_+i*width_*height_+j*height_, height_, 1);
//         }
//     }
//     for(size_t i = 0; i<length_; i++){
//         for(size_t j = 0; j<height_; j++){
//             bubble_sort(p_+i*width_*height_+j, width_, height_);
//         }
//     }
//     for(size_t i = 0; i<width_; i++){
//         for(size_t j = 0; j<height_; j++){
//             bubble_sort(p_+i*height_+j, length_, width_*height_);
//         }
//     }
// }

void insertion_sort(int *p_, int len_, int unit_bias_){
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
}

// void insertion_sort_3d(int *p_, int length_, int width_, int height_){
//     for(size_t i = 0; i<length_; i++){
//         for(size_t j = 0; j<width_; j++){
//             insertion_sort(p_+i*width_*height_+j*height_, height_, 1);
//         }
//     }
//     for(size_t i = 0; i<length_; i++){
//         for(size_t j = 0; j<height_; j++){
//             insertion_sort(p_+i*width_*height_+j, width_, height_);
//         }
//     }
//     for(size_t i = 0; i<width_; i++){
//         for(size_t j = 0; j<height_; j++){
//             insertion_sort(p_+i*height_+j, length_, width_*height_);
//         }
//     }
// }

void sort_1d(int *p_, int len_, int unit_bias_, int type_){
    switch (type_)
    {
    case 0:
        bubble_sort(p_, len_, unit_bias_);
        break;
    case 1:
        insertion_sort(p_, len_, unit_bias_);
        break;
    default:
        break;
    }
}

void sort_3d(int *p_, int length_, int width_, int height_, int type_){
    int len[3] = {height_, width_, length_};
    int len1[3] = {length_, length_, width_};
    int len2[3] = {width_, height_, height_};
    int unit_bias[3] = {1, height_, width_*height_};
    int i_parameter[3] = {width_*height_, width_*height_, height_};
    int j_parameter[3] = {height_, 1, 1};
    for (size_t iter = 0; iter < 3; iter++)
    {
        for(size_t i = 0; i<len1[iter]; i++){
            for(size_t j = 0; j<len2[iter]; j++){
                sort_1d(p_+i*i_parameter[iter]+j*j_parameter[iter], len[iter], unit_bias[iter], type_);
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
}