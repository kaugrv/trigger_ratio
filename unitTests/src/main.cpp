#include <random>
#include <vector>
#include <string>
#include <algorithm>

#include <gtest/gtest.h>

#include "Ratio.hpp"


/////////////////////////////////////////////////////
// constructors

TEST (RatioConstructor, defaultConstructor) { 
	ASSERT_EQ (0, 0);
}




// /////////////////////////////////////////////////////
// // arithmetic

// TEST (VectorDArithmetic, plus) {

// 	const size_t maxSize = 1000;  // max size of the tested vectors
// 	std::mt19937 generator(0);
// 	std::uniform_int_distribution<int> uniformIntDistribution(1,maxSize);
// 	std::uniform_real_distribution<double> uniformDistributionValue(-int(maxSize),maxSize);
// 	auto gen = [&uniformDistributionValue, &generator](){ return uniformDistributionValue(generator);};

// 	// run many times the same test with different values
// 	for(int run=0; run<100; ++run){

// 		// define a vector dimension
// 		const size_t dim = uniformIntDistribution(generator);

// 		// generate random data
// 		std::vector<double> data1(dim), data2(dim);
// 		std::generate(data1.begin(), data1.end(), gen);
// 		std::generate(data2.begin(), data2.end(), gen);

// 		// build the corresponding VectorD
// 		VectorD vec1(dim), vec2(dim), vec3(dim);
// 		for(size_t i=0; i<dim; ++i){
// 			vec1[i] = data1[i];
// 			vec2[i] = data2[i];
// 		}

// 		vec3 = vec1 + vec2;
// 		ASSERT_EQ (vec3.size(), dim);

// 		for(size_t i=0; i<dim; ++i){
// 	    	ASSERT_DOUBLE_EQ (vec3[i], data1[i] + data2[i]);    // EXPECT_DOUBLE_EQ would be fine too
// 		}
// 	}
// }



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


