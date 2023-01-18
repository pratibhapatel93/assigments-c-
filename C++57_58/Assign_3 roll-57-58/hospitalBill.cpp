#include<cstdio>
#include<iostream>
#include<string>
#include "PatientClass.h"
using namespace std;

float getHospitalExp(Patient &p){
	float exp;
	exp = p.getBillAmount();
	return exp;
}

int main(void){
	// declare vars
	int id,bedType,days,patientType;
	float bill;
	string name;
	
	// get patient data
	cout<<"Enter - Patient Id | Patient name | Bed Type | No Of Days ."<<endl;
	cin>>id>>name>>bedType>>days;
	cout<<"Press : \n 1 - Ordinary Patient \n 2 - Hospital Employee"<<endl;
	cin>>patientType;
	
	//creating an object
	if(patientType==1){	
		Patient p1(id,name,bedType,days);
		bill = p1.getBillAmount();
		cout<<"Bill for "<<p1.getPatientName()<<" patient : "<<bill<<endl;
		cout<<"Bill with GST : "<<getHospitalExp(p1)*1.05<<endl;
	}else{
		InHousePatient p1(id,name,bedType,days);
		int _discount;
		cout<<"Enter discount : ";
		cin>>_discount;
		p1.setDiscount(_discount);
		bill = p1.getBillAmount();
		cout<<"Bill for"<<p1.getPatientName()<<" patient : "<<bill<<endl;
		cout<<"Bill with GST : "<<getHospitalExp(p1)*1.05<<endl;
	}
	//get bill amount
		

}
