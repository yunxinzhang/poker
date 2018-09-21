#include <stdio.h>
#include <stdlib.h>


void rotate(char matrix[10][10]){
	char ch[100];
	for(int i=0; i<10; ++i){
		for(int j=0; j < 10; ++j){
			ch[i*10+j] = matrix[9-j][i];
		}
	}
	for(int i=0; i<10; ++i){
		for(int j=0; j<10; ++j){
			matrix[i][j] = ch[i*10+j];
		}
	}

}
