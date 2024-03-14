#include <fstream>
#include <iostream>
#include <iomanip>

double mapping(double d){
    // la mia trasformazione è:  (d-1) intervallo 0,4; /4 intervallo 0,1; *3 intervallo 0,3; -1 intervallo [-1,2]
    return 3*((d-1)/4) - 1;
}

int main()
{
    // Dichiaro e apro i file come oggetti ifstream (input) e ofstream(output).
    // Faccio il controllo sugli errori

    std::ifstream data("data.csv");
    if(data.fail()){
        std::cerr << "Errore in apertura del file data.csv" << std::endl;
        return 1;
    }

    std::ofstream result("result.csv");
    if(result.fail()){
        std::cerr << "Errore in apertura del file result.csv" << std::endl;
        return 1;
    }

    // Setup file setting: Intestazione + prima riga
    double d = 0, sum = 0, media;

    data >> d;
    sum = mapping(d);
    result << std::scientific << std::setprecision(16) << "# N Mean\n"
           << "1 " << sum << std::endl;



    // Ciclo per il calcolo delle medie
    unsigned int i = 1;
    while(data >> d){
        i++;
        sum+=mapping(d);
        result << i << " " << sum/i << std::endl;
    }

    data.close();
    result.close();
    return 0;
}
