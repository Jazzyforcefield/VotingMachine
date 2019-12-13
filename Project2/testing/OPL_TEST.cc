

#include <string>
#include <iostream>



#include "../src/OPL.h"
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class OPLTests : public ::testing::Test {
	protected:
  	// Put member variables here
  	OPL * opl_test_case_;

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
