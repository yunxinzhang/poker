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

int main(int argc, char** argv){
	if(argc!=2){
		exit(EXIT_FAILURE);
	}
	FILE * fp = fopen( argv[1], "r" );
	if(fp==NULL)	
		exit(EXIT_FAILURE);
	int c;
	char matrix[10][10];
	int cnt = 0;
	while( (c = fgetc(fp)) != EOF ){
		++cnt;
		if(cnt%11==0){
			if(c=='\n')continue;
			exit(EXIT_FAILURE);
		}
		if(c=='\n')exit(EXIT_FAILURE);
		matrix[cnt/11][cnt%11-1] = c;
		if(cnt>110)exit(EXIT_FAILURE);
	}
	rotate(matrix);
	for(int i=0; i<10; ++i){
		for(int j=0; j<10; ++j)
			printf("%c", matrix[i][j]);
		printf("\n");

	}
}

