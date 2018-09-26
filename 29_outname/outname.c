#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  char * new_name = malloc((strlen(inputName)+10)* sizeof(*new_name));	
  strcpy( new_name , inputName );
  strcat( new_name , ".counts" );
  return new_name;
}
