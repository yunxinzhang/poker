#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"



kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE *fp = fopen(fname ,"r");
  if(fp==NULL){
	perror("Open file error!");
	exit(EXIT_FAILURE);
  }
  int nkv = 128;
  kvarray_t * arrp = malloc(sizeof(*arrp));
  arrp->npair = 0;
  arrp->kvarr = malloc(nkv*sizeof(*(arrp->kvarr)));
  char * line = NULL;
  size_t sz = 0;
  int used_kv = 0;  
  while(getline(&line, &sz, fp)!=-1){
	if( strchr(line, '=') == NULL) continue;
	int len = strchr(line, '=') - line;
	if(used_kv>=nkv){
		nkv *= 2;
		arrp->kvarr = realloc(arrp->kvarr, nkv*sizeof(*(arrp->kvarr)));
 	}	
	arrp->kvarr[used_kv].key = malloc(strlen(line));
	strncpy(arrp->kvarr[used_kv].key, line, len);
 	arrp->kvarr[used_kv].key[len] = '\0';
	arrp->kvarr[used_kv].value = malloc(strlen(line));
	strcpy(arrp->kvarr[used_kv].value, strchr(line,'=')+1);
	strchr(arrp->kvarr[used_kv].value,'\n')[0] = '\0';
	++used_kv;
  }
  arrp->npair = used_kv;
  int cls = fclose(fp);
  if(cls!=0){
	perror("Close file failed!");
 	exit(EXIT_FAILURE);
  }
  free(line);
  return arrp;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i< pairs->npair; ++i){
	free(pairs->kvarr[i].key);
	free(pairs->kvarr[i].value);
  }
  free(pairs->kvarr);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(int i=0; i< pairs->npair; ++i){
	printf("key = '%s' value = '%s'\n", pairs->kvarr[i].key, pairs->kvarr[i].value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(int i=0; i<pairs->npair; ++i){
	if(strcmp(key, pairs->kvarr[i].key)==0)return pairs->kvarr[i].value;
  }
  return NULL;
}
