#include <iostream>
#include <cmath>
#include "complex.h"

using namespace std;

int Complex_Num :: ObjectCount = 0;

Complex_Num::Complex_Num()
{
	
	real_part = new double;
	imaginary_part = new double;

	ObjectCount++;

}

void Complex_Num::setvalue()
{
	cout << "\tEnter real part     : ";
	cin >> *real_part;
	cout << "\tEnter imaginary part: ";
	cin >> *imaginary_part;
	cout << "\n";
}


Complex_Num:: ~Complex_Num(){
	
	  delete real_part;
      delete imaginary_part;

}

void Complex_Num:: print(){
	
        if(*imaginary_part >=0 ){
            cout <<"\t" << *real_part << " + " << *imaginary_part << "i" << endl;
        }
        
        else{ 
            cout <<"\t" << *real_part << " - " << abs(*imaginary_part) << "i" << endl;
        }
    }

 //complex number addition
Complex_Num Complex_Num :: operator + (const Complex_Num &complex){
        
		Complex_Num answer;
        *answer.real_part = *real_part + *complex.real_part;
        *answer.imaginary_part = *imaginary_part + *complex.imaginary_part;
        return answer;
    }
    
    //complex number substraction
Complex_Num Complex_Num :: operator - (const Complex_Num &complex){
        
		Complex_Num answer;
        *answer.real_part = *real_part - *complex.real_part;
        *answer.imaginary_part = *imaginary_part - *complex.imaginary_part;
        return answer;
    }
    
	//complex number multiplication
Complex_Num Complex_Num :: operator * (const Complex_Num &complex){
        
		Complex_Num answer;
        *answer.real_part =(*real_part * *complex.real_part)- (*imaginary_part * *complex.imaginary_part);
        *answer.imaginary_part=(*real_part * *complex.imaginary_part)+ (*imaginary_part * *complex.real_part);
         return answer;
    }
    
    //complex number division
Complex_Num Complex_Num :: operator / (const Complex_Num &complex){
        
		Complex_Num answer;
        *answer.real_part = (((*real_part)*(*complex.real_part))+((*imaginary_part)*(*complex.imaginary_part))) / (pow(*complex.real_part,2) + pow(*complex.imaginary_part,2));
        *answer.imaginary_part = (((*complex.real_part)*(*imaginary_part))-((*real_part)*(*complex.imaginary_part))) / (pow(*complex.real_part,2)+pow(*complex.imaginary_part,2));
        return answer;
            
    }

/************************************************************/
Complex_Num::Complex_Num(const Complex_Num &c)  
{  
    real_part = new double;
    *real_part = *c.real_part;
    imaginary_part = new double;
    *imaginary_part = *c.imaginary_part;
} 

Complex_Num& Complex_Num::operator = (const Complex_Num &c) 
{
    real_part = new double;
    *real_part = *c.real_part;
    imaginary_part = new double;
    *imaginary_part = *c.imaginary_part;
    return *this;
} 
/************************************************************/

//function to find conjugate of complex number
void conjugate(const Complex_Num &complex){
    *complex.imaginary_part = -*complex.imaginary_part;
 }

int main()
{
	
	cout << "\t\t\t=====C++ program to represent a Complex number using a Class=====" << endl; 
	cout<<"\n";
	
	Complex_Num c1,c2,c3;
	
	cout<<"(#)Enter values for complex number 1"<< endl;
	c1.setvalue();
	
	cout<<"(#)Enter values for complex number 2"<< endl;
    c2.setvalue();
	
	cout << "(#)The Complex numbers you have entered are as follows" << endl;
	
	c1.print();
	c2.print();
	
	cout<<"\n";
    
    cout<<"\t\t\t\t(~)The test scenarios are as follows(~)" << endl;
    cout<<"\n";
    
    //Addition of two complex numbers
	//c3 = c1 + c2;
    cout << "(#)Sum of the entered numbers " <<endl;
    cout<< "==>";
	(c1+c2).print();
    cout<<"\n";

    //substration of two complex numbers
    c3 = c1 - c2;
    cout<<"(#)substraction of the entered numbers(complex number 1 - complex number 2) "<<endl;
    cout<< "==>";
	c3.print();
	cout<<"\n";
    
	//multiplication of two complex numbers
    c3 = c1 * c2;
    cout<<"(#)Multiplication of the entered numbers" << endl;
    cout<< "==>";
	c3.print();
    cout<<"\n";
      
    //division of two complex numbers
    c3 = c1 / c2;
    cout<<"(#)Division of the entered numbers(complex number 1 / complex number 2)"<<endl;
    cout<< "==>";
	c3.print();
	cout<<"\n";
    
	//conjugate of c1
    conjugate(c1);
    cout<<"(#)conjugate of complex number 1  "<<endl;
    cout<< "==>";
    c1.print();

    cout <<"\n";
     
    cout << "(#)Total objects created are " << Complex_Num :: ObjectCount << endl; //c1,c2,c3,addition,substraction,multiplication,division,conjugate1,conjugate2 = 9
    
	return 0;
}








