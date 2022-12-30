#include <iostream>
#include "Ratio.hpp"
#include "operatorsMath.hpp"


int main() {
    Ratio<int> r1; //default constructor
    Ratio<int> r2(-5); //parametrized constructor (1)
    Ratio<int> r3(50,2); //parametrized constructor (2)

    long int a = 3;
    long int b = 2;
    Ratio<long int> r4(a,b); //Ratio can be (u) int, long int, long long int

    Ratio<long int>r5 = r4; //copy constructor

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    std::cout << "r4 = " << r4 << std::endl;
    std::cout << "r5 = " << r5 << std::endl <<  std::endl;


    std::cout << "Operations with Ratio : " << std::endl;
    std::cout << "r2+r3 = " << r2+r3 << std::endl;
    std::cout << "r2-r3 = " << r2-r3 << std::endl;
    std::cout << "r2*r3 = " << r2*r3 << std::endl;
    std::cout << "r2/r3 = " << r2/r3 << std::endl << std::endl;


    std::cout << "Math Operators on Ratio : " << std::endl;
    std::cout << "Square Root of 3/2 = " << sqrt(r5)<< std::endl;
    std::cout << "Exponential of 3/2 = " << exp(r5) << std::endl;
    std::cout << "Log of 3/2 = " << log(r5)<< std::endl;
    std::cout << "Cosine of 3/2 = " << cos(r5)<< std::endl;
    std::cout << "Sine of 3/2 = " << sin(r5)<< std::endl;
    std::cout << "3/2 pow. 2 = " << pow(r5,2)<< std::endl << std::endl;

    std::cout << "Average of (r1,r2,r3) = " <<  average(r1,r2,r3) << std::endl << std::endl;

    std::cout << "Infinite and 0 : " << std::endl;

    Ratio<int> ro1(0,5);
    Ratio<int> ro2(0,-5);
    Ratio<int> ri1(5,0);
    Ratio<int> ri2(-5,0);

    std::cout << "r3 + 0+ = " << r3 + ro1 << std::endl;
    std::cout << "r3 + 0- = " << r3 + ro2 << std::endl;
    std::cout << "r3 * 0+ = " << r3 * ro1 << std::endl;
    std::cout << "r3 * 0- = " << r3 * ro2 << std::endl;

    std::cout << "r3 + inf = " << r3 + ri1 << std::endl;
    std::cout << "r3 - inf = " << r3 + ri2 << std::endl;
    std::cout << "r3*inf = " << r3*ri1 << std::endl;
    std::cout << "r3*(-inf) = " << r3*ri2 << std::endl;

    std::cout << "inf*(-inf) = " << ri1*ri2 << std::endl;

    std::cout << "Build a ratio with 0 and 0 (Ratio<int>(0,0)) results in a floating point exception and stops the program" << std::endl;

    std::cout << "Ratio to Float 0 = " << convertRatioToFloat(ro1) << std::endl;
    std::cout << "Ratio to Float inf = " << convertRatioToFloat(ri1) << std::endl;

    std::cout << "0+.invert() = " << ro1.invert() << std::endl;
    std::cout << "0-.invert() = " << ro2.invert() << std::endl;

    std::cout << "+inf.invert() = " << ri1.invert() << std::endl;
    std::cout << "-inf.invert() = " << ri2.invert() << std::endl;

    std::cout << "-inf.invert().invert() = " << ri2.invert().invert() << std::endl;



    try {
        std::cout << "Cos(inf) = " << cos(ri1) << std::endl;
    } catch (std::exception &err){
        std::cerr << err.what() << std::endl;
    }
    
    std::cout << "Exp(inf) = " << exp(ri1) << std::endl;


 
    return 0;
}
