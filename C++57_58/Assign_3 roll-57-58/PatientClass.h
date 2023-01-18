--#include<string>
using namespace std;

class Patient{

public:
/*	Patient(){
		patientId = 100;
		patientName = "sanket";
		bedType = 1;
		noOfDays = 50;	
	}
	//copy const
	Patient(const Patient& source){

		cout<<"aaaaa"<<endl;
		patientId = source.patientId;
		patientName = source.patientName;
		bedType = source.bedType;
		noOfDays = source.noOfDays;	
	}
*/	//const
	Patient(int _id,string _name,int _bedType,int _days){
		cout<<"param const"<<endl;
		patientId = _id;
		patientName = _name;
		bedType = _bedType;
		noOfDays = _days;
	}		
	// getter setters
	int getPatientId(){return patientId;}
	string getPatientName(){return patientName;}
	int getBedType(){return bedType;}
	int getNoOfDays(){return noOfDays;}

	void setPatientId(int _patientId){patientId = _patientId;}
	void setPatientName(string _patientName){patientName = _patientName;}
	void setBedType(int _bedType){bedType = _bedType;}
	void setNoOfDays(int _noOfDays){noOfDays = _noOfDays;}
	
	virtual float getBillAmount(){
		int price;
		int amount;
		
		switch(bedType){
		case 1:
			price = 500;
			break;
		case 2:
			price = 350;
			break;
		case 3:
			price = 200;
			break;
		default:
			price = 100;
		}

		amount = noOfDays*price;

		return amount;
	}
	
private:
	int patientId;
	string patientName;
	int bedType;
	int noOfDays;
};



class InHousePatient:public Patient{

public:
	InHousePatient(int _id,string _name,int _bedType,int _days):Patient(_id,_name,_bedType,_days){
		discount = 5;
	}
	
	int getDiscount(){return discount;}
	void setDiscount(int _discount){discount = _discount;}
	
	float getBillAmount(){
		int normalBill = Patient::getBillAmount();
		if(normalBill>5000){			
			return normalBill*(100-discount)/100;
		}
		return normalBill*0.95;
	}
private:
	int discount;
};
