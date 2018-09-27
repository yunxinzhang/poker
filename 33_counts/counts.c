#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"
counts_t * createCounts(void) {
  //WRITE ME
  counts_t * cntnames = malloc( sizeof(*cntnames));
  cntnames->sz = 0;
  cntnames->undef = 0;
  cntnames->cnts = NULL;
  return cntnames;
}
void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if(name==NULL){
	c->undef++;
	return;
  }
  for(int i=0; i<c->sz; ++i){
	if(strcmp(name, c->cnts[i].name)==0){
		c->cnts[i].cname++;
		return;
   	}
  }
  c->cnts = realloc( c->cnts , (++c->sz)*sizeof( *(c->cnts)));
  c->cnts[c->sz-1].name = malloc( strlen(name) +1 );
  strcpy(c->cnts[c->sz-1].name, name);
  c->cnts[c->sz-1].cname = 1; 
}
void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(int i=0; i<c->sz; ++i){
	fprintf(outFile, "%s: %d\n", c->cnts[i].name, c->cnts[i].cname);
  }
  if(c->undef>0)
  	fprintf(outFile, "<unknown> : %d\n", c->undef);
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(int i=0; i<c->sz; ++i){
	free(c->cnts[i].name);
  }
  free(c->cnts);
  free(c);
}
