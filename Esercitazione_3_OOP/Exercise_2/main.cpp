#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber z1(1,0), z2(1,-2);
    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "z2 = " << z2 << std::endl;

    std::cout << "z1+z2 = " << z1 + z2 << std::endl;

    if(z1==z2)
        std::cout << "z1 = z2" << std::endl;
    else
        std::cout << "z1 != z2" << std::endl;

    ComplexNumber z1bar(1,2.00001);
    if(z1==z1bar)
        std::cout << "z1 = z1bar" << std::endl;

    std::cout << "z1 coniugate = " << z1.coniugate() << std::endl;

    std::cout << "z1 - z1 = " << z1-z1 << std::endl;

    std::cout << "-z1 = " << -z1 << std::endl;

    std::cout << "z1 * z1 = " << z1*z1 << std::endl;
    std::cout << "z1 / z2 = " << z1/z2 << std::endl;

    std::cout << "z1 in forma trigonometrica: z1 = " << z1.trigonometric() << std::endl;

    std::cout << "z1 in forma esponenziale: z1 = " << z1.exponential() << std::endl;

    return 0;
}
