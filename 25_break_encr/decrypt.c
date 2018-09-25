#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int max_num( int * nums, int n){
   assert(n>0);
   int max = nums[0], idx = 0;
   for(size_t i=1; i<n ;++i){
	if(nums[i] > max){
  	   idx = i;
	   max = nums[i];
        }
   }
   return idx;
}
void decrypt(FILE * fp){
  int c;
  int chs[26] = {0};
  size_t idx = 0;
  while( (c = fgetc(fp))!=EOF){
// 	printf("%c", c);
   	idx = c - 'a';
	if(idx>=0 && idx<26)
		++chs[idx];
  }
//  printf("\n");
  printf("%d\n", max_num(chs, 26));
}

int main(int argc, char ** argv){
  if(argc!=2){
//	fprintf(stderr, "Usage: break inputFileName\n");
	return EXIT_FAILURE;
  }
//  printf("%s\n", argv[1]);
  FILE * fp = fopen(argv[1], "r");
  if(fp==NULL){
//	perror("Could not open file!");
	return EXIT_FAILURE;
  }
  decrypt(fp);
  if(fclose(fp) != 0){
//	perror("Failed to close the input file!");
	return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;

}
