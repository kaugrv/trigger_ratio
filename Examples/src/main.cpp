#include <iostream>
#include "Ratio.hpp"
#include "operatorsMath.hpp"


int main() {
    Ratio<int> r;
    Ratio<int> r1(5,1);
    Ratio<int> r2(10,1);
    Ratio<int> r3(15,1);
    Ratio<int> r4(20,1);

    // std::cout<< average<int, double>(r,r1,r2,r3,r4) << std::endl;
    // r3+=4;
    // r1+=r1;
    // std::cout << r3 << std::endl;
    // std::cout << r1 << std::endl;
    // r1-=r2;
    // std::cout << r1 << std::endl;
    // Ratio<int> r5(8,3);
    // std::cout << floor(r5) << std::endl;

    r1*=convertFloatToRatio(0.5);

    // r1 = 5/2;
    std::cout << r1 << std::endl;
    std::cout << exp(r1)<< std::endl;
    std::cout << exp(convertRatioToFloat(r1)) << std::endl;
    std::cout << convertRatioToFloat(exp(r1)) - exp(convertRatioToFloat(r1)) << std::endl;


    std::cout << cos(r1)<< std::endl;
    return 0;
}
