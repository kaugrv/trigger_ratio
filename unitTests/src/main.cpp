#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "Ratio.hpp"


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
	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};


	for(int run=0; run<10000; ++run) {

    double num1 = gen();
    double den1 = gen();

    double num2 = gen();
    double den2 = gen();

    Ratio r1(num1, den1), r2(num2,den2);
    Ratio r3(num1*num2, den1*den2);

    ASSERT_EQ(r1*r2, r3);


	}
}






int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


