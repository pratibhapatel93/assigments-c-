class Loan{

public:
	//constructos
	Loan(double _principle,float _period){
		principle = _principle;
		period = _period;
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
//----------------------------------
class Taxable{
public:
	virtual double getTax()=0;
private:
};
//--------------------------------
class Discountable{
public:
	virtual double getDiscount()=0;
private:
};
//----------------------------
class PersonalLoan:public Loan,public Taxable{
public:	
	//constructor
	PersonalLoan(double _principle,float _period):Loan(_principle,_period){
	}
	
	double getTax(){
		return Loan::GetEMI()*1.05;
	}

	float GetRate(){
		float rate;
		if(Loan::GetPrinciple()<=500000){
			rate = 15;
		}else{
			rate = 16;
		}
		return rate;
	}
private:
};
//---------------------------
class HomeLoan:public Loan,public Discountable{
	
public:
	//constructor
	HomeLoan(double _principle,float _period):Loan(_principle,_period){
		
	}

	double getDiscount(){
		return Loan::GetEMI()*0.95;
	}


	float GetRate(){
		float rate;
		if(Loan::GetPrinciple()<=2000000){
			rate = 10;
		}else{
			rate = 11;
		}
		//rate +1% if princ > 250000
		if(Loan::GetPrinciple()>25000){
			rate = rate+1;
		}

		return rate;
	}
private:
	double limit;
};
