#include "gtest/gtest.h"
#include "algorithms/utilities/utilities.hpp"

class parent {};
class child : public parent {};

TEST(Utilities, isFirstDerivedOfSecond)
{
    constexpr bool res1 { wrp::isFirstDerivedOfSecond<parent, child>::getResult() };
    ASSERT_FALSE(res1);
	constexpr bool res2 { wrp::isFirstDerivedOfSecond<child, parent>::getResult() };
    ASSERT_TRUE(res2);
}
