#include<cmath>
class Investment{
public:
	//constructos
	Investment(double _amount=100,int _period=1 ){
		amount=_amount;
		period=_period;
	}

	//getter setter
	double getAmount(){return amount;}
	void setAmount(double _amount){amount = _amount;}
	
	int getPeriod(){return period;}
	void setAmount(int _period){period = _period;}

	//get rate 
	double getRate(){
		float rate;
		//cal of rate
		if(amount<10000){
			rate = 8;
		}else if(amount >= 10000 && amount <50000){
			rate = 9;
		}else if(amount>=50000){
			rate = 10;
		}
		
		//+1% if perio>5years
		rate = period > 5 ? rate+1 : rate;
		return rate;
	}	
	//interest rate calculation
	double getInterest(bool isCompoundInterest=true){
		float rate = getRate();

		if(isCompoundInterest){
			float a = amount * pow(1+(rate/100), period);
			return a-amount;
		}else{
			return amount*rate*period/100;
			}
		
	}

private:
	double amount;
	int period;
};
