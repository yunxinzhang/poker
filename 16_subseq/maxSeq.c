#include <stdlib.h>
size_t maxSeq(int * array, size_t n){
    if(n==0)return 0;
    int maxlen = 1;
    int start = 0;
    int len = 1;
    for(int i=0; i<n-1; ++i){
        if(array[i+1]>array[i]){
           ++len;
           if(len>maxlen){
    		maxlen = len ;
           }
        }else{
           start = i+1;
	   len = 1;
        }
    }
    return maxlen;
}


