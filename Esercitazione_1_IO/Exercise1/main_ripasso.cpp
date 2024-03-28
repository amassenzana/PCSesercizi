#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <sstream>


int main()
{
    /*
    int a = -5;
    double d = M_PI;  // Stands for pi greco
    // char c = ';';
    // bool b = false; // or true
    // unsigned int i = 2;
    std::string s = "Hello world";  // :: operatore di scope => il tipo string si trova nello scope std

    int a1 = 5;
    int a2 = 7;

    int sum = a1+a2;

    std::string s1 = "Hello ";
    std::string s2 = " world!";
    std::string conc = s1 + s2;

    std::cout << "sum: " << sum << std::endl;
    std::cout << "cons: " << conc << std::endl;

    std::cout << "size of int: " << sizeof(int) << std::endl;
    std::cout << "size of unsigned int: " << sizeof(unsigned int) << std::endl;

    // Fixed è l'intero + 6 cifre decimali
    std::cout << std::fixed << std::setprecision(0) <<  "interval for int: [" << -pow(2,31)
              << " , " << pow(2,31)-1 << "]" << std::endl;
    std::cout << "interval for int: [0, "
              << pow(2,32)-1 << "]" << std::endl;

    std::cout << "interval for int: [" << std::numeric_limits<int>::min()
              << " , " << std::numeric_limits<int>::max() << "]" << std::endl;

    std::cout << "a prima: " << a << std::endl;
    {
        int a=3;
        std::cout << "a dentro: " << a << std::endl;
    }
    std::cout << "a dopo: " << a << std::endl;

    // defaultfloat, setprecision(6) VALORI DI DEFAULT

    for(unsigned int a=0; a<3; a++){
        a++;
    }
    std::cout << "a dopo il ciclo: " << a << std::endl;

    std::cout << "double d:" << d << std::endl;

    int val = 0;
    std::cin >> val;
    std::cout << "valore: " << val << std::endl;
    std::string str;
    getline(std::cin, str);
    std::cout << "valore di str: " << str << std::endl;



    std::string nameFile = "data.csv";
    std::ifstream fstr;
    fstr.open(nameFile);

    if(fstr.fail()){
        std::cerr << "Errore nell'apertura del file" << std::endl;
        return 1;
    }

    // int val;

    int sumValues = 0;
    std::string header = "";
    fstr >> header;
    while(fstr >> val){
        sumValues += val*val;
        // std::cout << val << std::endl;
    }

    std::cout << "Somma dei valori: " << sumValues << std::endl;

    fstr.close(); */

    // int a = 2.9;
    double z{0}, a{1};
    std::cout << z/z << std::endl;



    return 0;
}
