#include<iostream>
#include<cstdio>
#include "bank.h"

using namespace std;

void showEMI(Loan* obj){
	float emi;
	emi = obj->GetEMI();
	//casting
	auto tx = dynamic_cast<Taxable*>(obj);	//auto = Taxable
	if(tx){
		emi = tx->getTax();
	}else{
		auto di = dynamic_cast<Discountable*>(obj);
		emi = di->getDiscount();
	}
	/*auto rs = dynamic_cast<Resetable*>(seq); //auto = Resetable*
	if(rs) //rs will be nullptr(zero) if casting fails
		rs->Reset();
	return seq->Sum(count) / count;*/
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
		PersonalLoan l(principle,period);
		showEMI(&l);
	}else if(option == 2){
		HomeLoan l(principle,period);
		showEMI(&l);
	}else{
		cout<<"Invalid Option Selected..."<<endl;
	}
}
