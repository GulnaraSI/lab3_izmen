/*Fail s zagolovochnym failom klassa Complex*/

#ifndef _MY_COMPLEX_H_
#define _MY_COMPLEX_H_
#include <iostream>

using namespace std;

class Complex  						                //Klass kompleksnogo chisla
{
  double Re;     						                //Deistvitelnaya chast'
  double Im; 						                    //mnimaya chast'
  public:							                    //Spisok chlenov klassov
	Complex(double aRe = 0, double aIm = 0);		//Konstruktor mnimoy i deystvitelnaoi chacti
	Complex(const Complex &);			            //Konstruktor kompleksnogo chisla
    ~Complex ();						            //Destruktor
    void Set(double aRe, double aIm = 0);			    //Ustanovka deystvitelnoy i mnimoy chacti
    operator double ();					                //Vozvraschaet modul' kompleksnogo chisla
    double abs ();						            //Modul' koplesnogo chisla
    friend istream& operator >> (istream & , Complex &) ; 	// Druzhestvennyi metod operacii perezagruzki vvoda
    friend ostream& operator << (ostream & , Complex & );	// Druzhestvennyi metod operacii perezagruzki vyvoda
    Complex operator + (const Complex &);			//Operaciya slozheniya mnimoy chasti
    Complex operator - (const Complex &);			//Operaciya vychitaniya mnimoy chasti
    Complex operator + (const double &);			//Operaciya slozheniya deystvitelnogo chasti
    Complex operator - (const double &);			//Operaciya vychitaniya deystvitelnogo chasti
    Complex operator * (const Complex &);			//Operaciya umnozheniya mnimoy chasti
    Complex operator * (const double &);			//Operaciya umnozheniya deystvitelnogo chasti
    Complex operator / (const double &);			//Operaciya deleniya deystvitelnogo chasti
    friend Complex operator + (const double & , const Complex &);		//Druzhestvennyi metod operacii slozheniya
    friend Complex operator - (const double & , const Complex &);		//Druzhestvennyi metod operacii vychitaniya
    friend Complex operator * (const double & , const Complex &);		//Druzhestvennyi metod operacii umnozheniya
    Complex & operator += (const Complex &);				//Perezagruzka operaciya slozheniya kopleksnogo chisla
    Complex & operator -= (const Complex &);				//Perezagruzka operaciya vychitaniya kopleksnogo chisla
    Complex & operator *= (const Complex &); 				//Perezagruzka operaciya umnozheniya kopleksnogo chisla
    Complex & operator += (const double &);					//Perezagruzka operaciya slozheniya deystvitelnogo chisla
    Complex & operator -= (const double &);					//Perezagruzka operaciya vychitaniya deystvitelnogo chisla
    Complex & operator *= (const double &);					//Perezagruzka operaciya umnozheniya deystvitelnogo chisla
    Complex & operator /= (const double &);					//Perezagruzka operaciya deleniya deystvitelnogo chisla
    Complex & operator = (const Complex &);					//Perezagruzka operaciya ravenstva kopleksnogo chisla
    Complex & operator = (const double &);					//Perezagruzka operaciya ravenstva deystvitelnogo chisla
};
#endif
