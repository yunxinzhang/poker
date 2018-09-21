#include <stdio.h>
#include <stdlib.h>
size_t maxSeq(int * array, size_t n);
int main(void ){
    int arr1[1] = {0};
    if(maxSeq(arr1,1)!=1){
       return EXIT_FAILURE;
    }
    int arr2[10] = {10,9,8,7,6,5,4,3,2,1};
    if(maxSeq(arr2,10)!=1){
       return EXIT_FAILURE;
    }
    int arr3[8] = {2,1,-1,3,4,7,10,2};
    if(maxSeq(arr3,8)!=5){
       return EXIT_FAILURE;
    }
    int arr4[7] = {1,3,7,0, -8,-7,-5};
    if(maxSeq(arr4,7)!=3){
       return EXIT_FAILURE;
    }
    int arr5[7] = {1,3,7,7, -8,7,-5};
    if(maxSeq(arr5,7)!=3){
       return EXIT_FAILURE;
    }
    int arr6[10] = {1,3,7,7, -8,7,-5};
    if(maxSeq(arr6,10)!=3){
       return EXIT_FAILURE;
    }
    int * arr = NULL;
    if(maxSeq(arr,0)!=0){
       return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
