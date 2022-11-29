#include "gtest/gtest.h"
#include "algorithms/algorithms.h"

#include  "algorithms/utilities/scopedtimer.hpp"

TEST(Algorithms, contains) {
	wrp::ScopedTimer<std::chrono::nanoseconds> tm{true};
	std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ASSERT_TRUE (wrp::contains(v.cbegin(), v.cend(), 1));
	ASSERT_FALSE(wrp::contains(v.cbegin(), v.cend(), 42));

	constexpr int val{ 2 };
	ASSERT_TRUE (wrp::contains(v, val));
	ASSERT_TRUE (wrp::contains(v, std::move(val)));
	ASSERT_FALSE(wrp::contains(v, 42));

	v.clear();
	ASSERT_FALSE(wrp::contains(v.cbegin(), v.cend(), 1));
	ASSERT_FALSE(wrp::contains(v.cbegin(), v.cend(), 42));
}


TEST(Algorithms, contains_if) {
	wrp::ScopedTimer tm{true};
	std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	auto lmb1 = [](int a){ return a == 1;   };
	auto lmb42 = [](int a){ return a == 42; };
	ASSERT_TRUE (wrp::contains_if(v.cbegin(), v.cend(), lmb1));
	ASSERT_FALSE(wrp::contains_if(v.cbegin(), v.cend(), lmb42));

	ASSERT_TRUE (wrp::contains_if(v, lmb1));
	ASSERT_FALSE(wrp::contains_if(v, lmb42));

	v.clear();
	ASSERT_FALSE(wrp::contains_if(v.cbegin(), v.cend(), lmb1));
	ASSERT_FALSE(wrp::contains_if(v.cbegin(), v.cend(), lmb42));
}
