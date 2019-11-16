#include "whatever source file you're testing"

#include "gtest/gtest.h"

// The fixture for testing class Foo.
class <CPL> : public ::testing::Test {
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
TEST_F(<CPL>, CPLIncrementTest) {
  vector<Party *> * parties = cpl->get_parties();
  //EXPECT_EQ(*parties[1].name_, "G");
  //EXPECT_EQ(*parties[2].name_, "G");


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


}

// Tests that Foo does Xyz.
TEST_F(FooTest, DoesXyz) {
  // Exercises the Xyz feature of Foo.
}
