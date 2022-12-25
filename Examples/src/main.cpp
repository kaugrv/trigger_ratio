#include <iostream>
#include "Ratio.hpp"
#include "operatorsMath.hpp"


int main() {
    long int a = 5;
    long int b = 1;
    
    Ratio<long int> r1(a,b);

    std::cout<< r1 << std::endl;

    std::cout << exp(r1)<< std::endl;
    
    return 0;
}
