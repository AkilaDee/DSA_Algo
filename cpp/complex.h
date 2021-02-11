
class Complex_Num
{
	
public:
	Complex_Num();

	void setvalue();
	
	~Complex_Num();

	void print();

	Complex_Num(const Complex_Num &c);
	Complex_Num& operator = (const Complex_Num &c);

	Complex_Num operator + (const Complex_Num &complex);

	Complex_Num operator - (const Complex_Num &complex);

	Complex_Num operator * (const Complex_Num &complex);

	Complex_Num operator / (const Complex_Num &complex);

	friend void conjugate (const Complex_Num &Complex);
	
	static int ObjectCount;

private:
	double* real_part ;
	double* imaginary_part ;
  	
};



