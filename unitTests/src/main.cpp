#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "Ratio.hpp"
#include "operatorsMath.hpp"

// constructors

TEST (RatioConstructor, defaultConstructor) { 
  Ratio<int> r;
	ASSERT_EQ (r.num(), 0);
}



// operators

TEST (RatioOperators, times) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    int num2 = gen();
    int den2 = gen();

    Ratio<int> r1(num1, den1), r2(num2,den2);
    Ratio<int> r3(num1*num2, den1*den2);

    ASSERT_EQ(r1*r2, r3);


	}
}

TEST (RatioMaths, cos) {

	const size_t maxSize = 5;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();


    Ratio<int> r1(num1, den1);
    std::cout << r1 << std::endl;

    float f = cos(num1*1.0/den1);
    ASSERT_NEAR(convertRatioToFloat(cos(r1)), f,1e-1);


	}
}

TEST (RatioMaths, exp) {

	const size_t maxSize = 5;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();


    Ratio<int> r1(num1, den1);
    std::cout << r1 << std::endl;

    float f = expf(num1*1.0/den1);
    ASSERT_NEAR(convertRatioToFloat(exp(r1)), f,1e-5);


	}
}


TEST (RatioMaths, pow) {

	const size_t maxSize = 50;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();
    int n = gen();

    if(den1 ==0) (den1 == 1);

    Ratio<int> r1(num1, den1);
    std::cout << r1 << std::endl;

    float f = powf(num1*1.0/den1,n);
    ASSERT_NEAR(convertRatioToFloat(pow(r1,n)), f,1e-2);


	}
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


