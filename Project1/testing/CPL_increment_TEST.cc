#include "src/cpl.h"
#include <string>
#include "gtest/gtest.h"

// The fixture for testing class Foo.
class CPLTests : public ::testing::Test {
 protected:
  // Put member variables here
  CPL * cpl_;

  void SetUp() override { // Initialize things here
		
	  int n_parties = 6;
	  vector<Party*>* parties;
	  char party_name = 'A';
	  for (int i = 0; i<n_parties ; i++)
	  {
		  Party* party = new Party();
		  std::string s(1, party_name);
		  Party->name_ = s;
		  Party->vote_ = 0;
		  vector<string> members;
		  char member_name = 'a';
		  for (int j = 0; j <= i; j++)
		  {
			  std::string mem(1, member_name);
			  members.push_back(mem);
			  member_name++;
		  }
		  party_name++;

	  }
	  cpl_ = new CPL(5,60,21,parties);

  }

  void TearDown() override {  // Delete stuff here
      delete cpl_;
  }
};

// Tests that the Foo::Bar() method does Abc.
TEST_F(CPLTests, CPLIncrementTest) {
  vector<Party *> * parties = cpl_->get_parties();
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

TEST_F(CPLTests, CPL_Get_Party_Test) {
	vector<Party*>* parties = cpl_->get_parties();
	string party_name = "A";
	for (int each_party; each_party < parties.size(); each_party++)
	{
		std::string s(1, party_name);
		EXPECT_EQ(*parties[each_party].name_, s);
		party_name++;
	}
}
