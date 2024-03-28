#include "ComplexNumber.hpp"
#include <iostream>



ComplexNumber::ComplexNumber(){
    real = 0;
    immaginary = 0;
}

ComplexNumber::ComplexNumber(double re){
    real = re;
    immaginary = 0;
}

ComplexNumber::ComplexNumber(double re, double imm){
    real = re;
    immaginary = imm;
}

ComplexNumber ComplexNumber::coniugate(){
    ComplexNumber z(real,-immaginary);
    return z;
}

double ComplexNumber::module(){
    return std::sqrt(real*real+immaginary*immaginary);
}

double ComplexNumber::theta(){
    return std::acos(real/module());
}

std::string ComplexNumber::trigonometric(){
    return std::to_string(module())+"*[cos("+std::to_string(theta())+")+i*sin("+std::to_string(theta())+")]";
}

std::string ComplexNumber::exponential(){
    return std::to_string(module())+"exp(i*"+std::to_string(theta())+")";
}




std::ostream& operator << (std::ostream& os, const ComplexNumber& r){
    if(fabs(r.real) > 1e-16)
        os << r.real;
    else
        os << "0";


    if(r.immaginary > 1e-16)
        os << "+" << r.immaginary << "i";
    else if(r.immaginary < -1e-16)
        os << "-" << -r.immaginary << "i";
    else
        os << "+0i";

    return os;
}

ComplexNumber operator +(const ComplexNumber &z1, const ComplexNumber &z2){
    ComplexNumber z(z1.real+z2.real, z1.immaginary+z2.immaginary);
    return z;
}

bool operator ==(const ComplexNumber &z1, const ComplexNumber &z2){
    bool res = ((z1.real-z2.real)*(z1.real-z2.real) +
                (z1.immaginary-z2.immaginary)*(z1.immaginary-z2.immaginary))<=1e-8;
    return res;
}

ComplexNumber operator -(const ComplexNumber &z1, const ComplexNumber &z2){
    ComplexNumber z(z1.real-z2.real, z1.immaginary-z2.immaginary);
    return z;
}
ComplexNumber operator -(const ComplexNumber &z1){
    ComplexNumber z(-z1.real, -z1.immaginary);
    return z;
}

ComplexNumber operator *(const ComplexNumber &z1, const ComplexNumber &z2){
    double rp = z1.real*z2.real - z1.immaginary*z2.immaginary;
    double ip = z1.real*z2.immaginary + z2.real*z1.immaginary;
    ComplexNumber z(rp,ip);
    return z;
}

ComplexNumber operator /(const ComplexNumber &z1, const ComplexNumber &z2){
    double den = (z2.real*z2.real + z2.immaginary*z2.immaginary);
    double rp = (z1.real*z2.real + z1.immaginary*z2.immaginary) / den;
    double ip = (z1.immaginary*z2.real - z1.real*z2.immaginary) / den;

    ComplexNumber z(rp,ip);
    return z;
}
