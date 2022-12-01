#include <gtest/gtest.h>
#include <vector>
#include <algorithms/numeric.h>

#include  <algorithms/utilities/scopedtimer.hpp>

void test_int() {
	const std::vector<int> v{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	ASSERT_EQ(wrp::average(v), 4.5f);
}

void test_float() {
	const std::vector<float> fv{ 0.01f, 0.03f, 0.6f, 0.058f, 0.87f, 1.2f, 0.123f, 0.89f, 0.00111f };
	ASSERT_NEAR(wrp::average(fv), 0.420f, 0.001f);
	
	std::vector<float> fvClone {std::begin(fv), std::begin(fv) + fv.size() - 1 };
	fv.pop_back();
	ASSERT_NEAR(wrp::average(std::begin(fv), std::end(fv)), wrp::average(fvClone), 0.001f);
}

void test_double() {
	const std::vector<double> dv{ 0.01d, 0.03d, 0.6d, 0.058d, 0.87d, 1.2d, 0.123d, 0.89d, 0.00111d };
	ASSERT_NEAR(wrp::average(dv), 0.420d, 0.001d);
	
	std::vector<double> dvClone {std::begin(dv), std::begin(dv) + dv.size() - 1 };
	dv.pop_back();
	ASSERT_NEAR(wrp::average(std::begin(dv), std::end(dv)), wrp::average(dvClone), 0.001f);
}

void test_empty() {
	std::vector<float> fv;
	ASSERT_EQ(wrp::average(fv), 0.0f);
	fv = std::vector<float>{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, };
	ASSERT_EQ(wrp::average(fv), 0.0f);
}

TEST(Numeric, average) {
	wrp::ScopedTimer<std::chrono::nanoseconds> tm{true, "Numeric.average"};
	test_int();
	test_float();
	test_double();
	test_empty();
}
