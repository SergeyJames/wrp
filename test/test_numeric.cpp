#include "gtest/gtest.h"
#include "algorithms/numeric.h"

void test_int() {
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	ASSERT_EQ(wrp::average(v), 5.5f);
}

void test_float() {
	std::vector<float> fv{ 0.01f, 0.03f, 0.6f, 0.058f, 0.87f, 1.2f, 0.123f, 0.89f, 0.00111f };
	ASSERT_NEAR(wrp::average(fv), 0.420f, 0.001f);
	
	std::vector<float> fvClone {std::begin(fv), std::begin(fv) + fv.size() - 1 };
	fv.pop_back();
	ASSERT_NEAR(wrp::average(std::begin(fv), std::end(fv)), wrp::average(fvClone), 0.001f);
}

void test_empty() {
	std::vector<float> fv;
	ASSERT_EQ(wrp::average(fv), 0.0f);
}

TEST(Numeric, average) {
	test_int();
	test_float();
	test_empty();
}
