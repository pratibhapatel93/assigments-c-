#include<iostream>
#include<cstdio>
#include "bank.h"

using namespace std;

void showEMI(Loan& obj,double principle,float period){
	float emi;
	obj.SetPrinciple(principle);
	obj.SetPeriod(period);
	emi = obj.GetEMI();
	cout<<"EMI for Personal Loan : "<<emi<<endl;
}


int main(void){
	//vars
	double principle;
	float period,emi;
	int option;
	
	cout<<"Enter Principle and Period :";
	cin>>principle>>period;
	
	cout<<"Enter \n 1 - Personal Loan\n 2 - Home Loan"<<endl;
	cin>>option;
	
	if(option == 1){	
		PersonalLoan l;
		showEMI(l,principle,period);
	}else if(option == 2){
		HomeLoan l;
		showEMI(l,principle,period);
	}else{
		cout<<"Invalid Option Selected..."<<endl;
	}
}
