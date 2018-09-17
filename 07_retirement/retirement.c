#include <stdio.h>
#include <stdlib.h>
struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;
double get_money_by_saving(retire_info re, int ag, double ini){
	double sum = ini;
	double rate = re.rate_of_return/12.0;
	for(int i=0; i<re.months; ++i){
	printf("Age %3d month %2d you have $%.2lf\n", (ag+i)/12,(ag+i)%12 , sum );
		sum += sum*rate+re.contribution;
	}
	return sum;
}
void retirement(int startAge,
	double initial,
	retire_info working,
	retire_info retired){
	double sum = get_money_by_saving(working, startAge, initial);
	sum = get_money_by_saving(retired,startAge+working.months,sum);

}
int main(void){
  retire_info w;
  w.months = 489;
  w.contribution = 1000;
  w.rate_of_return = 0.045;
  retire_info r;
  r.months = 384;
  r.contribution = -4000;
  r.rate_of_return = 0.01;
  int age = 327;
  double save = 21345;
  retirement(age,save,w,r);
  return EXIT_SUCCESS;
}
