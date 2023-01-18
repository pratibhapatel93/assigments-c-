class Loan{

public:
	//constructos
	Loan(){
	
	}
	
	//getter setter
	double GetPrinciple(){return principle;}
	void SetPrinciple(double _principle){principle = _principle;}
	float GetPeriod(){return period;}
	void SetPeriod(float _period){period = _period;}
	
	//methods
	virtual float GetRate() = 0;

	double GetEMI(){
		double emi;
		emi = principle*(1+GetRate()*period/100)/(12*period);
		return emi;
	}
	
private:
	double principle;
	float period;
};

//----------------------------
class PersonalLoan:public Loan{
	float GetRate(){
		float rate;
		if(Loan::GetPrinciple()<=500000){
			rate = 15;
		}else{
			rate = 16;
		}
		return rate;
	}
};
//---------------------------
class HomeLoan:public Loan{
	float GetRate(){
		float rate;
		if(Loan::GetPrinciple()<=2000000){
			rate = 10;
		}else{
			rate = 11;
		}
		return rate;
	}

};
