#include <iostream>
#include "Ratio.hpp"
#include "operatorsMath.hpp"


int main() {
    Ratio<int> r1; //default constructor
    Ratio<int> r2(-5); //parametrized constructor (1)
    Ratio<int> r3(50,2); //parametrized constructor (2)

    long int a = 3;
    long int b = 2;
    Ratio<long int> r4(a,b); //Ratio can be int, long int, long long int

    Ratio<long int>r5=r4; //copy constructor

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    std::cout << "r4 = " << r4 << std::endl;
    std::cout << "r5 = " << r5 << std::endl <<  std::endl;

    std::cout << "Operations with Ratio : " << std::endl;
    std::cout << "r2+r3 = " << r2+r3 << std::endl;
    std::cout << "r2-r3 = " << r2-r3 << std::endl;



    std::cout << "Math Operators on Ratio : " << std::endl;

    std::cout << "Square Root of 3/2 = " << sqrt(r5)<< std::endl;
    std::cout << "Exponential of 3/2 = " << exp(r5) << std::endl;
    std::cout << "Log of 3/2 = " << log(r5)<< std::endl;
    std::cout << "Cosine of 3/2 = " << cos(r5)<< std::endl;
    std::cout << "Sine of 3/2 = " << sin(r5)<< std::endl;
    std::cout << "3/2 pow. 2 = " << pow(r5,2)<< std::endl << std::endl;


    std::cout << "Infinite : " << std::endl;

    Ratio<int> ri(0,1);
    std::cout<<"ri = "<< ri.invert() << std::endl;

    return 0;
}
