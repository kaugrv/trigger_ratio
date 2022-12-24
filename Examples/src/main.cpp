#include <iostream>
#include "Ratio.hpp"


int main() {

    Ratio<int> r1(50,2);

    std::cout << r1 << std::endl;
    std::cout << sqrt(r1) << std::endl;

    return 0;
}
