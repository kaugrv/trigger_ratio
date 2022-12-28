#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "Ratio.hpp"
#include "operatorsMath.hpp"

// RatioConstructors

TEST (RatioConstructors, defaultConstructor) { 
  Ratio<int> r;
	ASSERT_EQ (r.num(), 0);
}



// RatioOperators


TEST (RatioOperators, adds) {

	const size_t maxSize = 10;  
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(1,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    int num2 = gen();
    int den2 = gen();

    Ratio<int> r1(num1, den1), r2(num2,den2);
    Ratio<int> r3(num1*den2 + num2*den1, den1*den2);

    ASSERT_EQ(r1+r2, r3);

	}
}

TEST (RatioOperators, times) {

	const size_t maxSize = 1000;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(1,maxSize);
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


TEST (RatioMaths, sqrt) {

	const size_t maxSize = 50;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(1,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    Ratio<int> r1(num1, den1);

    float f = sqrtf(num1*1.0/den1);
    ASSERT_NEAR(sqrt(r1), f, 1e-5);


	}
}

TEST (RatioMaths, exp) {

	const size_t maxSize = 50;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-maxSize,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    Ratio<int> r1(num1, den1);

    float f = expf(num1*1.0/den1);
    //std::cout << exp(r1) << "//" << f  << " // " << isinf(exp(r1)) << std::endl;
    if(den1 == 0){
      ASSERT_EQ(exp(r1),f);
      break;
    }
    ASSERT_NEAR(exp(r1), f, 1e-5);

	}
}


TEST (RatioMaths, cos) {

	const size_t maxSize = 50;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-maxSize,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    Ratio<int> r1(num1, den1);

    // try {
    //   float a = num1*1.0/den1;
    //   float f = cosf(num1*1.0/den1);
    //   ASSERT_NEAR(cos(r1), f, 1e-5);

    // }catch(const std::string &s) {
    //     std::cerr << "error : " << s << std::endl;
    // }
    if (den1==0) break;
    float f = cosf(num1*1.0/den1);
    ASSERT_NEAR(cos(r1), f, 1e-5);
	}
}

TEST (RatioMaths, sin) {

	const size_t maxSize = 50;  // max size of the tested vectors
	std::mt19937 generator(0);
	std::uniform_int_distribution<int> uniformIntDistribution(-maxSize,maxSize);
	std::uniform_int_distribution<int> uniformDistributionValue(-maxSize,maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    int num1 = gen();
    int den1 = gen();

    Ratio<int> r1(num1, den1);

    if (den1 == 0) break;
    float f = sinf(num1*1.0/den1);
    ASSERT_NEAR(sin(r1), f, 1e-5);


	}
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


