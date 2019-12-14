

#include <string>
#include <iostream>



#include "../src/OPL.h"
#include "gtest/gtest.h"

/**
 * \class OPL_TEST
 *
 * \brief OPL test
 *
 * This class is OPL_Test.  It is used for testing the function in OPL class
 * The get_candidates() and increment() function are checked by asserting the
 * expected results and actual results.
 *
 *
 * \note Will be used to test the functions in OPL file
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #12 $
 *
 */

// The fixture for testing class Foo.
class OPLTests : public ::testing::Test {
	protected:
  	// Put member variables here
    /**
     * A protected variable.
     * CPL opl_test_case_.
     */
  	OPL * opl_test_case_;
    /**
     * A public function.
     * void setup() override function.
     */
  	void SetUp() override { // Initialize things here
     		opl_test_case_ = new OPL(10, 60, 15);
		std::vector<Candidate*> * candidates = opl_test_case_->get_candidates(); 
     		std::string parties_name[6] = {"D", "G", "R", "F","H","I"};
     		std::string name_candidates[15] = {"Pike", "Foster", "Deutsch", "Borg","Jones","Smith","Erik","Michael","Tyler","Berni","Xiaohui","Austin","Logan","Jack","Jessica"};
     		for (int i = 0; i < 15; i++) {

			Candidate* cands = new Candidate();
		
			cands->name_ = name_candidates[i];
		     
			cands->party_ = parties_name[i%6];
			candidates->push_back(cands);
		 
         
		}
	}

  void TearDown() override {  // Delete stuff here
     delete opl_test_case_;
  }
};
/**
 * A public function.
 * test function for OPL_Increment_Test assert the expected results and actual results.
 */
// Testing the OPL's increment function
TEST_F(OPLTests, OPL_Increment_Test) {
  std::vector<Candidate *> * cands = opl_test_case_->get_candidates();
  int csize = cands->size();
  
  for (int i = 0 ; i<csize; i++)
  {
	opl_test_case_->increment(i);
	for (int j = 0 ; j< csize; j++)
	{
		if(j<=i)
		{
			EXPECT_EQ((*cands)[j]->votes_, 1);
		}
		else
		{
			EXPECT_EQ((*cands)[j]->votes_, 0);
		}
	}
  }

  EXPECT_EQ(opl_test_case_->increment(20), -1);
  EXPECT_EQ(opl_test_case_->increment(30), -1);
  

}
/**
 * A public function.
 * test function for OPL_Get_Party_Test assert the expected results and actual results.
 */
// Testing the OPL get_candidates function
TEST_F(OPLTests, OPLCandidateTest) {
  std::vector<Candidate *> * cands = opl_test_case_->get_candidates();
  EXPECT_EQ((*cands)[1]->name_ ,"Foster");
  EXPECT_EQ((*cands)[6]->name_ ,"Erik");
  EXPECT_EQ((*cands)[13]->name_ ,"Jack");
  EXPECT_EQ((*cands)[4]->name_ ,"Jones");
  EXPECT_EQ((*cands).size(),15);
  EXPECT_EQ((*cands)[6]->party_,"D");
  EXPECT_EQ((*cands)[9]->party_,"F");

}
