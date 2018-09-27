#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"
#include "counts.h"
#include "outname.h"

counts_t * countFile(const char * filename, kvarray_t * kvPairs) {
  //WRITE ME
  FILE *fp = fopen(filename, "r");
  if(fp==NULL){
	//printf("-->>%s<<--\n", filename);
	perror("Open file failed 1k");
	exit(EXIT_FAILURE);
  }
  counts_t * cs = createCounts();
  char * buff = NULL;
  size_t sz = 256;
  char * val;
  while(getline(&buff,&sz,fp)!=-1){
	strchr(buff,'\n')[0]='\0';
	val = lookupValue(kvPairs, buff);
	//printf("buff >> %s, val >> %s \n",buff, val);
	addCount(cs, val);
  }
  //printf("cf\n");
  free(buff);
  int fc = fclose(fp);
  if(fc!=0){
	perror("Close file failed");
	exit(EXIT_FAILURE);
  }
  //printf("ex\n");
  printCounts(cs, stdout);
  return cs;
}

int main(int argc, char ** argv) {
  //WRITE ME (plus add appropriate error checking!)
   if(argc<3){
	perror("valid input");
	exit(EXIT_FAILURE);
   }
 //read the key/value pairs from the file named by argv[1] (call the result kv)
   kvarray_t * kv = readKVs(argv[1]);
   printKVs(kv);
 //count from 2 to argc (call the number you count i)
   for( int i= 2; i< argc; ++i){
    //count the values that appear in the file named by argv[i], using kv as the key/value pair
    //   (call this result c)

	//printf("countFile start %s\n", argv[i]);
        counts_t *c = countFile(argv[i], kv);
	//printf("countFile over");
    //compute the output file name from argv[i] (call this outName)
        char *outName = malloc( strlen(argv[i]) + 8 );
	strcpy(outName, argv[i]);
        outName = strcat(outName, ".counts"); 

    //open the file named by outName (call that f)
	FILE *f = fopen(outName, "w");
  	if(f==NULL){
		perror("Open file failed 2s");
		exit(EXIT_FAILURE);
	}
    //print the counts from c into the FILE f
	printCounts(c,f);
    //close f
	fclose(f);
    //free the memory for outName and c
	free(outName);
	freeCounts(c);

   }
 //free the memory for kv
  freeKVs(kv);
  return EXIT_SUCCESS;
}
