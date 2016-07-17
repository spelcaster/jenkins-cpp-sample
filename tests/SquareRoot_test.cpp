#include "../src/SquareRoot.hpp"

#include <gtest/gtest.h>
#include <iostream>

class SquareRootTest : public ::testing::Test
{
public:
  SquareRoot *object;

  SquareRootTest();
  ~SquareRootTest();
  virtual void SetUp ();
  virtual void TearDown ();

  void callConstructor();
};

SquareRootTest::SquareRootTest () {
  object = nullptr;
}

SquareRootTest::~SquareRootTest () {
  if (!object)
    delete object;
}

void SquareRootTest::SetUp () {
}

void SquareRootTest::TearDown () {
}

void SquareRootTest::callConstructor () {
  object = new SquareRoot();
}

TEST_F (SquareRootTest, GivenNoChange_WhenAnyMethodsCalled_ThenInitialValues) {
  // GIVEN
  callConstructor();

  // WHEN
  double expected = 0.0;

  // THEN
  EXPECT_EQ(expected, object->getNumber());
  EXPECT_EQ(expected, object->calculate());
}

TEST_F (SquareRootTest, GivenAnyNumber_WhenSettingValue_ThenPropertyMustChange) {
  // GIVEN
  callConstructor();
  object->setNumber(9.0);

  // WHEN
  double expected = 9.0;

  // THEN
  EXPECT_EQ(expected, object->getNumber());
}

TEST_F (SquareRootTest, GivenPositiveNumber_WhenCalculating_ThenGoodResult) {
  // GIVEN
  callConstructor();
  object->setNumber(9.0);

  // WHEN
  double expected = 3.0;

  // THEN
  EXPECT_EQ(expected, object->calculate());
}

TEST_F (SquareRootTest, GivenZero_WhenCalculating_ThenReturnIsZero) {
  // GIVEN
  callConstructor();
  object->setNumber(0.0);

  // WHEN
  double expected = 0.0;

  // THEN
  EXPECT_EQ(expected, object->calculate());
}

TEST_F (SquareRootTest, GivenNegativeNumber_WhenCalculating_ThenReturnIsFixed) {
  // GIVEN
  callConstructor();
  object->setNumber(-18.0);

  // WHEN
  double expected = -1;

  // THEN
  EXPECT_EQ(expected, object->calculate());
}
