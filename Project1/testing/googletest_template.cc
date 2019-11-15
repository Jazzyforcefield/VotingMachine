#include "whatever source file you're testing"

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class <NAME OF YOUR TESTING CLASS> : public ::testing::Test {
 protected:
  // Put member variables here
  OPL * opl_;

  void SetUp() override { // Initialize things here
     opl_ = new OPL();
  }

  void TearDown() override {  // Delete stuff here
     delete opl_;
  }
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(<NAME OF YOUR TESTING CLASS>, OPLIncrementTest) {
  vector<Candidate *> * cands = opl->get_candidates();
  opl_->increment(2);
  EXPECT_EQ(*cands[2].votes_, 1);

  opl_->increment(2);
  EXPECT_EQ(*cands[2].votes_, 2);
  EXPECT_EQ(*cands[0].votes_, 0);
  EXPECT_EQ(*cands[1].votes_, 0);
  EXPECT_EQ(*cands[3].votes_, 0);

  opl_->increment(3);
  EXPECT_EQ(*cands[3].votes_, 1);
}

// Tests that Foo does Xyz.
TEST_F(FooTest, DoesXyz) {
  // Exercises the Xyz feature of Foo.
}
