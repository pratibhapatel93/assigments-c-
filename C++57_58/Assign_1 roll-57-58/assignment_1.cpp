
#include<cstdio>
#include "investment.h"
int main(void){
	//vars
	double amount;
	int period;
	double interest;
	int getOption;

	puts("Enter amount and period :");
	scanf("%lf%d",&amount,&period);
	
	Investment i(amount,period);
	
	puts("Press : \n 1 - Simple Interest \n 2 - Compound Interest\n");
	scanf("%d",&getOption);
	if(getOption==1){
		interest = i.getInterest(false);
	}else if(getOption==2){
		interest = i.getInterest(true);
	}
	
	//create object
	
	printf("When invested amount is :%lf for period :%d\n interest is : %lf\n",i.getAmount(),i.getPeriod(),interest);
	


	return 0;
}
