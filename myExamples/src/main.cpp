#include <iostream>
#include "Ratio.hpp"

#include "plop.hpp"


int main() {

    // appel de plop
    plop();

    //Ratio<int> test(3,4);
    // Ratio<int> val; // default
    // std::cout << val << std::endl;

    // Ratio<int> val2(3.0); // with one number
    // std::cout << val2 << std::endl;

    // Ratio<int> val3(3.0,4.3); // with two numbers
    // std::cout << val3 << std::endl;

    // Ratio<int> val4 = convertFloatToRatio(10.3);
    // std::cout << val4 << std::endl;

    // std::cout << val4.invert() << std::endl;
    // std::cout << val2+val2.invert() << std::endl;


    float a = 1.5;
    double b  = 0.12;
    //std::cout << convertFloatToRatio(a) << std::endl;
    std::cout << b << std::endl;
    std::cout << convertFloatToRatio(b) << std::endl;

    return 0;
}
