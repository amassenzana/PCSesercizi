#ifndef __RATIONAL_H
#define __RATIONAL_H

// Alternativa a ifndef etc... -> #pragma once

#include <iostream>
#include <cmath>

namespace Rationals{

struct Rational{
    // Attributi
    int numerator;
    int denominator;

    // Metodi

    Rational() = default;
    Rational(int a, int b);

    // Quando chiamo dal main viene chiamato il costruttore
    // Che fa match coi parametri che ho passato
    Rational(double a, double b);
    double to_double();
};



std::ostream& operator << (std::ostream& os, const Rational& r);
Rational operator + (const Rational& r1, const Rational& r2);
Rational operator * (const Rational& r1, const Rational& r2);
double operator + (const double& d, const Rational& r);

}

#endif
