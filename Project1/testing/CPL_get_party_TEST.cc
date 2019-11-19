#include "src/cpl.h"

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class CPLTests : public ::testing::Test {
 protected:
  // Put member variables here
  CPL * cpl_;

  void SetUp() override { // Initialize things here
     cpl_ = new CPL();
  }

  void TearDown() override {  // Delete stuff here
     delete cpl_;
  }
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(CPLTests, CPLIncrementTest) {
  vector<Party *> * parties = cpl->get_parties();
  char party_name = 'A';
  for (int each_party; each_party < parties.size(); each_party++)
  {
	  EXPECT_EQ(*parties[each_party].name_, party_name);
	  party_name++;
  }
  

  /*
  int party_number = 0;
  for (int each_ballot = 0; each_ballot < 10; each_ballot++)
  { 
	  for (int each_increment = 0; each_increment < parties.size(); each_increment++)
	  { 
		  cpl_->increment(party_number);
  
		  for (int each_party = 0; each_party < parties.size(); each_party++)
		  {
			  if (each_party > party_number)
			  {
				  EXPECT_EQ(*parties[each_party].votes_, each_ballot) << "ballot added to wrong party";
			  }
			  else
			  {
				  EXPECT_EQ(*parties[each_party].votes_, each_ballot+1) << "ballot didn't add to the right party";
			  }  
		  }
  
		  party_number++;
	  }
  }
  */
}



