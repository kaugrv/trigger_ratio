#include <iostream>
#include "Ratio.hpp"


int main() {

    Ratio<int> r1(15,3);
    Ratio<int> r2(15,3);

    std::cout << r1-r1 << std::endl;

    r1.setNum(0);
    std::cout << r1 << std::endl;
    r1.setNum(20);
    std::cout << r1 << std::endl;
    r1.setDen(-4);
    std::cout << r1 << std::endl;
    r1*=convertFloatToRatio<int>(2.5);
    std::cout << r1 << std::endl;


    return 0;
}
