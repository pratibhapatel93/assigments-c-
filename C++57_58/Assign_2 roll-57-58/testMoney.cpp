#include<cstdio>
#include "Money.h"

int main(void){
	//getting m1
	printf("Enter Rupee and paise for object 1 : ");
	int m,p;
	scanf("%d%d",&m,&p);
	Money m1(m,p);
	printf("Money in obj 1 (paise) : %.02f\n",m1.getTotalMoney());
	
	//getting m2
	printf("Enter Rupee and paise for object 2 : ");
	scanf("%d%d",&m,&p);
	Money m2(m,p);
	printf("Money in obj 1 (paise) : %.02f\n",m2.getTotalMoney());
	
	//adding m1 and m2
	Money m3 = m1+m2;
	m3.printTotalMoney();

	Money m4 = m1-m2;
	m4.printTotalMoney();
	return 0;
}
