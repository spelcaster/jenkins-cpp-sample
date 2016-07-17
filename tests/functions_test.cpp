#include "../src/functions.hpp"

#include "../lib/fff/fff.h"
#include <gtest/gtest.h>

extern "C" double __real_square_root (double);
FAKE_VALUE_FUNC(double, __wrap_square_root, double)

class FunctionsTest : public ::testing::Test
{
 public:
    FunctionsTest();
    ~FunctionsTest();
    virtual void SetUp ();
    virtual void TearDown ();
};

FunctionsTest::FunctionsTest () {
}

FunctionsTest::~FunctionsTest () {
}

void FunctionsTest::SetUp () {
  RESET_FAKE(__wrap_square_root);
  FFF_RESET_HISTORY();
}

void FunctionsTest::TearDown () {
}

TEST_F (FunctionsTest, GiveFakeFunction_WhenCallingFunction_ThenResultIsManipulated) {
    // GIVEN
    __wrap_square_root_fake.return_val = 42.0;

    // WHEN
    double given1 = square_root(324.0);
    double given2 = square_root(645.16);
    double given3 = square_root(2533.310224);
    double expected = 42.0;

    // THEN
    EXPECT_EQ (expected, given1);
    EXPECT_EQ (expected, given2);
    EXPECT_EQ (expected, given3);
    EXPECT_EQ (3u, __wrap_square_root_fake.call_count);
}

TEST_F (FunctionsTest, GiveRealFunction_WhenCallingFunction_ThenResultIsCalculated) {
    // GIVEN
    __wrap_square_root_fake.custom_fake = __real_square_root;

    // WHEN
    double given1 = square_root(324.0);
    double expected1 = 18.0;

    double given2 = square_root(645.16);
    double expected2 = 25.4;

    double given3 = square_root(2533.310224);
    double expected3 = 50.332;

    // THEN
    EXPECT_EQ (expected1, given1);
    EXPECT_EQ (expected2, given2);
    EXPECT_EQ (expected3, given3);
    EXPECT_EQ (3u, __wrap_square_root_fake.call_count);
}

TEST_F (FunctionsTest, GivenRealFunction_WhenZero_ThenResultIsZero) {
    // GIVEN
    __wrap_square_root_fake.custom_fake = __real_square_root;

    // WHEN
    double given = square_root(0.0);
    double expected = 0.0;

    // THEN
    ASSERT_EQ(expected, given);
    EXPECT_EQ (1u, __wrap_square_root_fake.call_count);
}

TEST_F (FunctionsTest, GivenRealFunction_WhenNegativeNumber_ThenNegativeOne) {
    // GIVEN
    __wrap_square_root_fake.custom_fake = __real_square_root;

    // WHEN
    double given = square_root(-22);
    double expected = -1;

    // THEN
    ASSERT_EQ(expected, given);
    EXPECT_EQ (1u, __wrap_square_root_fake.call_count);
}
