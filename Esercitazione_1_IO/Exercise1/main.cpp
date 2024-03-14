#include <fstream>
#include <sstream>
#include <iostream>

int formula(int N){
    int S = (N*(N+1)*(2*N+1))/6;
    return S;
}


int main()
{
    std::ifstream fstr;
    std::string filePath = "data.csv", linea = "";
    int value = 0, sumValues1 = 0, sumValues2 = 0;

    fstr.open(filePath);

    if(fstr.fail()){
        std::cerr << "Errore in apertura" << std::endl;
    }

    fstr >> linea;
    while(fstr >> value){
        // std::cout << value << std::endl;
        sumValues1 += value*value;
    }

    sumValues2 = formula(value);
    std::cout << "Formula1:\t" << sumValues1 << "\nFormula2:\t" << sumValues2 << std::endl;



    return 0;
}
