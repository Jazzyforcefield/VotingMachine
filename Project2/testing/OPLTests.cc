#include "../src/OPL.h"

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class OPLTests : public ::testing::Test {
 protected:
  // Put member variables here
  OPL * opl_;

  void SetUp() override { // Initialize things here
     int n_cands = 15 ;
     opl_ = new OPL(10, 60, n_cands);
     std::string parties_name[6] = {"D", "D", "R", "R","R","I"};
     std::string name_candidates[6] = {"Pike", "Foster", "Deutsch", "Borg","Jones",
      "Smith"};
     for (int i = 0; i < 15; i++) {

         Candidate* cands = new Candidate();
        
         cands->name_ = name_candidates[i];
             
         cands->party_ = parties_name[i];
         opl_->get_candidates()->push_back(cands);
         
         
     }
  }

  void TearDown() override {  // Delete stuff here
     delete opl_;
  }
};

// Testing the OPL's increment function
TEST_F(OPLTests, OPLIncrementTest) {
  std::vector<Candidate *> * cands = opl_->get_candidates();
  int number = 0;
  int csize = cands->size();
  
  for (int q = 0; q < 4; q++) {
      for (int i = 0; i < csize; i++){
          opl_->increment(i);
          for(int j = 0; j < csize; j++){
              if (i == j) {
                number ++;
              }

              EXPECT_EQ((*cands)[j]->votes_, number);
          }     
      }
  }

  EXPECT_EQ(opl_->increment(20), -1);
  EXPECT_EQ(opl_->increment(30), -1);
  

}

// Testing the OPL get_candidates function
TEST_F(OPLTests, OPLCandidateTest) {
  std::vector<Candidate *> * cands = opl_->get_candidates();
  EXPECT_EQ((*cands)[1]->name_ ,"Foster");
  EXPECT_EQ((*cands)[2]->name_ ,"Deutsch");
  EXPECT_EQ((*cands)[3]->name_ ,"Borg");
  EXPECT_EQ((*cands)[4]->name_ ,"Jones");
  EXPECT_EQ((*cands).size(),6);
  EXPECT_EQ((*cands)[4]->party_,"R");
  EXPECT_EQ((*cands)[5]->party_,"I");

}
