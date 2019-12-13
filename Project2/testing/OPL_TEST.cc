

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
TEST_F(OPLTests, OPL_Candidate_Test) {
  std::vector<Candidate *> * cands = opl_test_case_->get_candidates();
  EXPECT_EQ((*cands)[1]->name_ ,"Foster");
  EXPECT_EQ((*cands)[6]->name_ ,"Erik");
  EXPECT_EQ((*cands)[13]->name_ ,"Jack");
  EXPECT_EQ((*cands)[4]->name_ ,"Jones");
  EXPECT_EQ((*cands).size(),15);
  EXPECT_EQ((*cands)[6]->party_,"D");
  EXPECT_EQ((*cands)[9]->party_,"F");

}

// Testing the OPL GenerateRandomNumber function
TEST_F(OPLTests, OPL_GenerateRandomNumber_Test) {
	double ans1 = opl_test_case_->GenerateRandomNumber(0);
	double ans2 = opl_test_case_->GenerateRandomNumber(10);
	double ans3 = opl_test_case_->GenerateRandomNumber(100);
	double ans4 = opl_test_case_->GenerateRandomNumber(2000);
	double ans5 = opl_test_case_->GenerateRandomNumber(500000);
	EXPECT_EQ(int(ans1),-18675);
	EXPECT_EQ(int(ans2),6019);
	EXPECT_EQ(int(ans3),1555);
	EXPECT_EQ(int(ans4),7515);
	EXPECT_EQ(int(ans5),-27394);

}

// Tests the GetMaxVotes function
TEST_F(OPLTests, OPL_GetMaxVotes_Test) {
  OPL * function_only = new OPL(9, 9, 9);
  int expectedx = -1;
  int expected0 = 0;
  int expected1 = 2016;
  int expected2 = 94;
  int expected3 = 400923;

  std::vector<Candidate *> cvec;
  Candidate * cand1 = new Candidate();
  cand1->name_ = "Bob";
  cand1->party_ = "D";

  Candidate * cand2 = new Candidate();
  cand2->name_ = "Dan";
  cand2->party_ = "R";

  Candidate * cand3 = new Candidate();
  cand3->name_ = "Sam";
  cand3->party_ = "Sad-U-Party";

  Candidate * cand4 = new Candidate();
  cand4->name_ = "Moe";
  cand4->party_ = "Mas-U-Party";

  int actualx = function_only->GetMaxVotes(cvec);

  cvec.push_back(cand1);
  cvec.push_back(cand2);
  cvec.push_back(cand3);
  cvec.push_back(cand4);

  int actual0 = function_only->GetMaxVotes(cvec);

  cand1->votes_ = 2016;
  cand2->votes_ = 74;
  cand3->votes_ = 2016;
  cand4->votes_ = 94;

  int actual1 = function_only->GetMaxVotes(cvec);

  cand1->votes_ = 9;
  cand3->votes_ = 0;

  int actual2 = function_only->GetMaxVotes(cvec);

  cand3->votes_ = 400923;

  int actual3 = function_only->GetMaxVotes(cvec);

  EXPECT_EQ(actualx, expectedx) << "Function not catching empty vector" << std::endl;
  EXPECT_EQ(actual0, expected0) << "Votes not initialized correctly" << std::endl;
  EXPECT_EQ(actual1, expected1) << "Function not getting max votes in a tie" << std::endl;
  EXPECT_EQ(actual2, expected2) << "Function not getting max votes" << std::endl;
  EXPECT_EQ(actual3, expected3) << "Function does not handle large numbers well" << std::endl;
}

// Tests the error checking for BreakTie, manual testing for more than 1 in OPLScenario6.csv
TEST_F(OPLTests, OPL_BreakTie_Test) {
  OPL * function_only = new OPL(9, 9, 9);
  int expectedx = -1;
  int expected0 = 0;

  std::vector<Candidate *> cvec;
  Candidate * cand1 = new Candidate();
  cand1->name_ = "Bob";
  cand1->party_ = "D";

  int actualx = function_only->BreakTie(cvec);

  cvec.push_back(cand1);

  int actual0 = function_only->BreakTie(cvec);

  EXPECT_EQ(actualx, expectedx) << "Function not catching empty vector" << std::endl;
  EXPECT_EQ(actual0, expected0) << "Function not returning correct number when only 1 candidate" << std::endl;
}





