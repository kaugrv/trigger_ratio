#include <iostream>
#include "Ratio.hpp"


int main() {
    Ratio<int> r;
    Ratio<int> r1(5,1);
    Ratio<int> r2(10,1);
    Ratio<int> r3(15,1);
    Ratio<int> r4(20,1);

    std::cout<< moy<int, double>(r,r1,r2,r3,r4) << std::endl;


    return 0;
}
