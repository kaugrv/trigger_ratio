#include <iostream>
#include "Ratio.hpp"
#include "operatorsMath.hpp"


int main() {
    long long int a = 3;
    long long int b = 2;
    
    Ratio<long long int> r1(a,b);

    std::cout<< r1 << std::endl;
    //25
    std::cout << exp(r1)<< std::endl;

    std::cout << sqrt(r1) << std::endl;
    //r1*=convertFloatToRatio<long long int>(0.5);
    
    //5
    std::cout << cos(r1) << std::endl;
    std::cout << acos(r1) << std::endl;
    std::cout << pow(r1,2.5) << std::endl;

 //std::cout << "teste wendy : " << convertFloatToRatio<long long int>(72004899337.4) << std::endl;

    //Ratio<long int>
    return 0;
}
