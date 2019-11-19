#include "src/opl.h"

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class OPLTests : public ::testing::Test {
 protected:
  // Put member variables here
  OPL * opl_;

  void SetUp() override { // Initialize things here
     int n_cands = 15 ;
     opl_ = new OPL();
     string parties_name[6] = {"big", "big", "small", "medium","small","big"}
     string name_candidates[6] = {"Elephant", "Lion", "Deer", "Tiger","Elephant",
      "Lion"}
     for (int i = 0; i < 15; i++){

         Candidate* cands = new Candidate();
        
         cands->name_ = name_candidates[i];
             
         cands->party_ = parties_name[i]
         opl_->get_candidates()->push_back;
         
         
     }
  }

  void TearDown() override {  // Delete stuff here
     delete opl_;
  }
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(OPLTests, OPLIncrementTest) {
  vector<Candidate *> * cands = opl->get_candidates();
  int number = 0;

  
  for (int q = 0; q < 4; q++){
      for (int i = 0; i< cands.size(); i++){
          opl_->increment(i);
          for(int j = 0; j< cands.size(); j++){
          if (i == j)
          {
            number ++;
          }
          EXPECT_EQ(*cands[j].votes_, number);
      }     
  }

  }
  opl_->increment(20);
  EXPECT_EQ(increment(20), -1);
  opl_->increment(30);
  EXPECT_EQ(increment(30), -1);
  

}

// Tests that Foo does Xyz.
TEST_F(OPLTests, OPLCandidateTest) {
  vector<Candidate *> * cands = opl->get_candidates();
  EXPECT_EQ(*cands[1].name_ ,"Lion");
  EXPECT_EQ(*cands[2].name_ ,"Deer");
  EXPECT_EQ(*cands[3].name_ ,"Tiger");
  EXPECT_EQ(*cands[4].name_ ,"Elepant");
  EXPECT_EQ(*cands.size(),15);
  EXPECT_EQ(*cands[4].party_,"small");
  EXPECT_EQ(*cands[5].party_,"big");

}