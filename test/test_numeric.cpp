#include "gtest/gtest.h"
#include "algorithms/numeric.h"
#include <chrono>

void test_int() {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ASSERT_EQ(wrp::average(v), 5.5f);
}

void test_float() {
	constexpr size_t size{ 10 };
	std::vector<double> dv(size);
	auto it = dv.begin();
	for (size_t k = 0; k < size; ++k, ++it) {
		auto start{ std::chrono::system_clock::now() };
		for(size_t i = 0; i < 10'000; ++i) {
			std::string qualityInfo = "";
		}
		*it = std::chrono::duration<double>(std::chrono::system_clock::now() - start).count();
	}

	ASSERT_NEAR(wrp::average(dv), 0.00119, 0.001);
}

TEST(Numeric, average)
{
	test_int();
	test_float();
}
