#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//This function is used to figure out the ordering
//of the strings in qsort.  You do not need
//to modify it.
int stringOrder(const void * vp1, const void * vp2) {
  const char * const * p1 = vp1;
  const char * const * p2 = vp2;
  return strcmp(*p1, *p2);
}
//This function will sort and print data (whose length is count).
void sortData(char ** data, size_t count) {
  qsort(data, count, sizeof(char *), stringOrder);
}
void copyStr(char ** strs, FILE * fp, size_t sz, size_t ssz){

  int c;
	strs = malloc(sz * sizeof(*strs)); 
 	for(int i=0; i<sz; ++i){
		strs[i] = malloc( ssz * sizeof(**strs));
		strs[i][0] = '\0';
	}	
	int i=0, j=0;
	while( (c = getc(fp))!= EOF ){
		strs[i] = realloc(strs[i], (j+10)*sizeof(**strs));
		if(c=='\n'){
			if(j>0)
				strs[i][j]='\0';
			++i; 
			j=0;
			if(i>=sz) {
				sz *= 2;
				strs = realloc(strs, sz*sizeof(*strs));
				for(int k=0; k<sz/2; ++k){
					strs[sz/2+k] = malloc(ssz * sizeof(**strs));
					strs[sz/2+k][0]='\0';
				}
			}
			continue;
		}
		strs[i][j++] = c;
	}
	sortData(strs, i+1);
  for(int i=0; i<sz; ++i){
	if(strlen(strs[i])>0)
	printf("%s\n", strs[i]);
  }
	for(int i=0; i<sz; ++i) free(strs[i]);
	free(strs);
} 

int main(int argc, char ** argv) {
  
  //WRITE YOUR CODE HERE!
  char ** strs = NULL;
  size_t sz=8, ssz=1024;
  if(argc==1)
  	copyStr(strs,stdin,sz,ssz);
  else{
	for(int i=1; i<argc; ++i){
		FILE *fp = fopen(argv[i], "r");
		if(fp==NULL)exit(EXIT_FAILURE);
		copyStr(strs, fp, sz, ssz);
		int  fc = fclose(fp);
 		if(fc!=0){
			perror("close file error");
			exit(EXIT_FAILURE);
		}
	}	
  }
  return EXIT_SUCCESS;
}
