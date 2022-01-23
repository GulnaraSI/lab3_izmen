/*Fail s opisaniem metodov klassa Complex*/
#include <iostream>
#include <cmath>
#include "mycomplex.h"

using namespace std;

  Complex :: Complex (double aRe , double aIm)    //Konstruktor klassa
{
    Re = aRe;                                   //aRe - deystvitelnaya chact'
    Im = aIm;                                   //aIm - mnimaya chact'
}

Complex :: Complex (const Complex & aRval)       //Konstruktor klassa
{
    Re = aRval.Re;                              //aRval - kompleksnoe chislo , aRval.Re - deystvitelnaya chact'
    Im = aRval.Im;                              //aRval - kompleksnoe chislo , aRval.Im - mnimaya chact'
}

Complex :: ~Complex ()                          //Destruktor klassa
{
    Re = 0.0;
    Im = 0.0;
}

void Complex :: Set (double aRe , double aIm)           //Ustanovka deystvitelnoy i mnimoy chacti
{
    Re = aRe;
    Im = aIm;
}

Complex :: operator double ()                           //Vozvraschaet modul' kompleksnogo chisla
{
    return abs ();                                      //Modul' koplesnogo chisla
}

double Complex :: abs ()                                //Vozvraschaet modul' vyrazheniya kompleksnogo chisla
{
    return sqrt(Re * Re + Im * Im);                         //Modul' vyrazheniya koplesnogo chisla
}

Complex Complex :: operator + (const Complex & aRval)       //Vozvraschaet rezultat slozheniya kompleksnogo chisla
{
    Complex Result;
    Result.Re = Re + aRval.Re;
    Result.Im = Im + aRval.Im;
    return Result;                                          //Rezultat
}

Complex Complex :: operator - (const Complex & aRval)           //Vozvraschaet rezultat vychitaniya kompleksnogo chisla
{
    Complex Result;
    Result.Re = Re-aRval.Re;
    Result.Im = Im-aRval.Im;
    return Result;                                              //Rezultat
}

Complex Complex :: operator + (const double & aRval)             //Vozvraschaet rezultat slozheniya deystvitelnogo chisla
{
    Complex result;
    result.Re = Re + aRval;
    result.Im = Im;
    return result;                                              //Rezultat
}

Complex Complex :: operator - (const  double & aRval)           //Vozvraschaet rezultat vychitaniya deystvitelnogo chisla
{
    Complex Result(* this);
    Result.Re = Re - aRval;
    return Result;                                              //Rezultat
}

Complex Complex :: operator * (const Complex & aRval)           //Vozvraschaet rezultat umnozheniya kompleksnogo chisla
{
    Complex Result;
    Result.Re = Re * aRval.Re - Im * aRval.Im;
    Result.Im = Re * aRval.Im + Im * aRval.Re;
    return Result;                                              //Rezultat
}

Complex Complex :: operator * (const double & aRval)            //Vozvraschaet rezultat umnozheniya deystvitelnogo chisla
{
    Complex Result;
    Result.Re = Re * aRval;
    Result.Im = Im * aRval;
    return Result;                                              //Rezultat
}
Complex Complex :: operator / (const double & aRval)            //Vozvraschaet rezultat deleniya deystvitelnogo chisla
{
    Complex Result;
    Result.Re = Re / aRval;
    Result.Im = Im / aRval;
    return Result;                                              //Rezultat
}

Complex & Complex :: operator += (const Complex & aRval)        //Ssylaetcya na rezultat slozheniya kompleksnogo chisla
{
    Re += aRval.Re;
    Im += aRval.Im;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator -= (const Complex & aRval)        //Ssylaetcya na rezultat vychitaniya kompleksnogo chisla
{
    Re -= aRval.Re;
    Im -= aRval.Im;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator *= (const Complex & aRval)        //Ssylaetcya na rezultat umnozheniya kompleksnogo chisla
{
    double tmpRe = Re;
    Re = Re * aRval.Re - Im * aRval.Im;
    Im = Im * aRval.Re + tmpRe * aRval.Im;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator += (const double & aRval)         //Ssylaetcya na rezultat slozheniya deystvitelnogo chisla
{
    Re += aRval;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator -= (const double & aRval)         //Ssylaetcya na rezultat vychitaniya deystvitelnogo chisla
{
    Re -= aRval;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator *= (const double & aRval)         //Ssylaetcya na rezultat umnozheniya deystvitelnogo chisla
{
    Re *= aRval;
    Im *= aRval;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator /= (const double & aRval)         //Ssylaetcya na rezultat deleniya deystvitelnogo chisla
{
    Re /= aRval;
    Im /= aRval;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator = (const Complex & aRval)         //Ssylaetcya na rezultat ravenstva kompleksnogo chisla
{
    Re = aRval.Re;
    Im = aRval.Im;
    return * this;                                              //Vozvrat po znacheniu
}

Complex & Complex :: operator = (const double & aRval)          //Ssylaetcya na rezultat ravenstva deystvitelnogo chisla
{
    Re = aRval;
    Im = 0.0;
    return * this;                                              //Vozvrat po znacheniu
}

istream & operator >> (istream & stream , Complex & aRval)      //Izvlechenie deystvitelnoy i mnimoy chasti
{
    char tmp[256];
    stream >> aRval.Re >> aRval.Im >> tmp;
    return stream;                                              //Izvlechenie
}

ostream & operator << (ostream & stream , Complex & aRval)      //Vstavlyaem deystvitelnuu i mnimuu chasti
{
    stream << aRval.Re;
    if( ! (aRval.Im < 0) )
        stream << '+';
    stream << aRval.Im << 'i';
    return stream;                                              //Vstavka
}

Complex operator + (const double & aRval , const Complex & aRval)       //Vozvraschaet rezultat slozheniya deystvitelnogo i komplesnogo chisla
{
    Complex Result;
    Result.Re = aRval + aRval.Re;                                       //aLval - deystvitelnoe chislo
    Result.Im = aRval.Im;
    return Result;                                                      //Rezultat
}

Complex operator - (const double & aRval , const Complex & aRval)       //Vozvraschaet rezultat vychitaniya deystvitelnogo i komplesnogo chisla
{
    Complex Result;
    Result.Re = aRval - aRval.Re;
    Result.Im =- aRval.Im;
    return Result;                                                      //Rezultat
}

Complex operator * (const double & aRval , const Complex & aRval)       //Vozvraschaet rezultat umnozheniya deystvitelnogo i komplesnogo chisla
{
    Complex Result;
    r.Re = aRval * aRval.Re;
    r.Im = aRval * aRval.Im;
    return Result;                                                      //Rezultat
}

