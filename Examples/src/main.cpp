#include <iostream>
#include "Ratio.hpp"

#include "plop.hpp"


int main() {

    //Ratio<int> r1(3);
    Ratio<int> r2(3,2);
    std::cout << r2*3;
    Ratio<int> r3 = convertPosFloatToRatio(3.5);
    Ratio<int> r4 = convertFloatToRatio(-3.5);

    //Ratio<int> r3(3.2);

    std::cout << r3 << std::endl;
    std::cout << r4 << std::endl;

    //Ratio<int> r3 = r1*r2;
    //std::cout << r2 << std::endl;
    
    return 0;
}
