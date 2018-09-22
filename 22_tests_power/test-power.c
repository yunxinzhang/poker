#include <stdio.h>
#include <stdlib.h>
unsigned power (unsigned x, unsigned y);
void run_check(unsigned x, unsigned y, unsigned expected_ans){
	if(power(x,y)!=expected_ans)
		exit(EXIT_FAILURE);
}
int  main(){
  run_check(0,0,1);
  run_check(0,1,0);
  run_check(2,1,2);
  run_check(2,10,1024);
  run_check(1024,0,1);
  run_check(1,1024,1);
  run_check(1000,3,1000000000);
  if(power(1000,3)*2+147483647!=2147483647)exit(EXIT_FAILURE);
  return EXIT_SUCCESS;

}
