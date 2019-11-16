// Copyright 2019, Michael Ung CSCI 5801

#include <iostream>

#include "src/processor.h"
#include "gtest/gtest.h"

// Test fixture for the Processor class
class ProcessorTests : public ::testing::Test {
 protected:
  // 3 different Processor declarations
  Processor * processor_;
  Processor * processor2_;
  Processor * processor3_;

  void SetUp() override {
    // Initializing different file names or scenarios for each processor
    processor_ = new Processor("filename.csv");
    processor2_ = new Processor("filename2.csv");
    processor3_ = new Processor("nonexistentbadspaces orbadextension.badext");
  }

  void TearDown() override {
    // Deleting Processor objects
    delete processor_;
    delete processor2_;
    delete processor3_;
  }
};

// These test whether the process function runs. These are not indicative of whether
// the values of the winners are good or not. Those will be tested more thoroughly
// in the system/integration tests.
TEST_F(ProcessorTests, ProcessTest) {
  int expected = processor_->process();
  int expected2 = processor2_->process();
  int expected3 = processor3_->process();

  EXPECT_EQ(expected, 0) << "Invalid file name\n" << std::endl;
  EXPECT_EQ(expected2, 0) << "Invalid file name.\n" << std::endl;
  EXPECT_EQ(expected3, -1) << "Process ran when it wasn't supposed to.\n" << std::endl;
}
