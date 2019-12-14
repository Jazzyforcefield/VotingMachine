// Copyright 2019, Michael Ung CSCI 5801

#include <iostream>

/**
 * \class ProcessorTest
 *
 * \brief Processor Test
 *
 * This class is ProcessorTests.  It is used for testing the function in Processor class
 * The processor() function are checked by asserting the
 * expected results and actual results of CPLScenario and OPLScenario file.
 * The erorr file with fault file name are tested as well.
 *
 * \note Will be used to test the processor() function
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #13 $
 *
 */
#include "src/processor.h"
#include "gtest/gtest.h"

// Test fixture for the Processor class
class ProcessorTests : public ::testing::Test {
 protected:
  // 3 different Processor declarations
    /**
     * A protected variable.
     * Processor processor_.
     */
  Processor * processor_;
    /**
     * A protected variable.
     * Processor processor2_.
     */
  Processor * processor2_;
    /**
     * A protected variable.
     * Processor processor3_.
     */
  Processor * processor3_;
    /**
     * A public function.
     * void setup() override function.
     */
  void SetUp() override {
    // Initializing different file names or scenarios for each processor
    processor_ = new Processor("testdata/OPLScenario1.csv");
    processor2_ = new Processor("testdata/CPLScenario1.csv");
    processor3_ = new Processor("badfile.abc");
  }
    /**
     * A private function.
     * void setup() override function.
     */
  void TearDown() override {
    // Deleting Processor objects
    delete processor_;
    delete processor2_;
    delete processor3_;
  }
};
/**
 * A public function.
 * test function for ProcessorTests assert the expected results and actual results.
 */
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
