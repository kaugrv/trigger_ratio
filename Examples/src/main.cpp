#include <iostream>
#include "Ratio.hpp"

#include "plop.hpp"


int main() {

    Ratio<int> r1(3,4);
    Ratio<int> r2;

    std::cout << r1 << std::endl;
    std::cout << r2 << std::endl;

    Ratio<int> r3 = r1*r2;
    std::cout << (r3 == r1*r2) << std::endl;
    
    return 0;
}
