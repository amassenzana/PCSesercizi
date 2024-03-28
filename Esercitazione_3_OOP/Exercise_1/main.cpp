#include <iostream>
#include "Rational.hpp"
#include "Utils.hpp"

using namespace Rationals;


int main(){

    int b = foo(1);
    Rational rtest1(3.,2.); // Chiamata a Rational(double,dobule)
    Rational rtest2{3,2};   // Caso particolare
    Rational rtest3;        // Chiamata a costruttore vuoto (=default)


    Rational r1(1,2);
    Rational r2(1,2);
    Rational somma = r1+r2;
    Rational prodotto = r1*r2;

    std::cout << "Somma: " << somma << std::endl;
    std::cout << "Prodotto: " << prodotto << std::endl;

    std::cout << r1 << " + 1.5 = " << r1.to_double() + 1.5 << std::endl;
    std::cout << "1.5 + " << r1 << " = " << 1.5 + r1 << std::endl;


    return 0;
}
