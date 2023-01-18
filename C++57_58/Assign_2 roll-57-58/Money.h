#include<cstdio>
class Money{
public:
	//param constructos
	Money(int _rupees,int _paise){
		rupees = _rupees+_paise/100;
		paise = _paise%100;	
		#ifdef TESTING
		puts("constructor");
		#endif
	}
	//copy constructor
	Money(const Money& source){
		rupees = source.rupees;
		paise = source.paise;
		#ifdef TESTING
		puts("copy constructor");
		#endif
	}
	//def const
	Money(){
		rupees = 10;
		paise = 20;	
	}
	//overloading operator
	Money operator+(const Money &rhs) const
	{
		return Money(this->rupees+rhs.rupees,this->paise+rhs.paise);
	}
	//overloading operator
	Money operator-(const Money &rhs) const
	{	
		float r2 = (rhs.rupees)*100; 
		float r1 = (this->rupees)*100;
		float p2 = rhs.paise;  
		float p1 = this->paise;
		
		float total;
		total = r1-r2+p1-p2;
		printf("%f|%f|%f|%f|%f|\n",r1,r2,p1,p2,total);	
		return Money(0,total);
	}
	~Money(){
		#ifdef TESTING
		puts("Destructor");
		#endif
	}

	// getting total money
	float getTotalMoney() const
	{
		return 100*rupees+paise;
	}
	void printTotalMoney() const{
		printf("%d Rs : %02d paise\n",rupees,paise);
	}
private:
int rupees;
int paise;
};
