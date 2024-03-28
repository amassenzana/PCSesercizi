#include "Rational.hpp"
#include <iostream>

namespace Rationals{


Rational::Rational(int a, int b){
    numerator = a;
    denominator = b;
}

Rational::Rational(double a, double b){
    numerator = a;
    denominator = b;
}

double Rational::to_double(){
    return double(numerator)/denominator;
}



std::ostream& operator << (std::ostream& os, const Rational& r){
    if (r.denominator == 0 && r.numerator == 0)
        os << NAN;
    else if (r.denominator == 0)
        os << INFINITY;
    else
        os << r.numerator << "/" << r.denominator;

    return os;
}

Rational operator + (const Rational& r1, const Rational& r2){
    int num = r1.numerator * r2.denominator
              + r2.numerator * r1.denominator;
    int den = r1.denominator * r2.denominator;

    Rational r(num,den);
    return r;
}

double operator + (const double& d, const Rational& r){
    double sum = d + double(r.numerator)/double(r.denominator);
    return sum;
}


Rational operator * (const Rational& r1, const Rational& r2){
    int den = r1.denominator * r2.denominator;
    int num = r1.numerator * r2.numerator;

    Rational r(num,den);
    return r;
}


}
