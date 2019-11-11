#include "gtest/gtest.h"
#include "algorithms/numeric.h"

void test_int() {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ASSERT_EQ(wrp::average(v), 5.5f);
}

void test_float() {
	std::vector<float> dv{ 0.01f, 0.03f, 0.6f, 0.058f, 0.87f, 1.2f, 0.123f, 0.89f, 0.00111f };
	ASSERT_NEAR(wrp::average(dv), 0.420f, 0.001f);
}

TEST(Numeric, average)
{
	test_int();
	test_float();
}
