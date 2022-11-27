#include <iostream>
#include "Ratio.hpp"

#include "plop.hpp"


int main() {

    //Ratio<int> test(3,4);
    Ratio<int> val;
    //std::cout << val;
    std::cout << val.den() << std::endl;

    std::cout << val << std::endl;
    
    return 0;
}
