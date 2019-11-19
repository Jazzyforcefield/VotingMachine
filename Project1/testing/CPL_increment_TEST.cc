//Copyright 2019, Zhuoran Bi CSCI 5801

#include <string>
#include <iostream>

#include "src/cpl.h"
#include "gtest/gtest.h"

// Test feature for CPL class
class CPLTests : public ::testing::Test {
	protected:
	CPL* cpl_test_case1_;
	CPL* cpl_test_case2_;

	void SetUp() override { // Initialize things here
		
		cpl_test_case1_ = new CPL(5, 60, 21);
		int n_parties = 6;
		vector<Party*>* parties;
		char party_name = 'A';
		for (int i = 0; i<n_parties ; i++)
		{
			Party* party = new Party();
			std::string s(1, party_name);
			Party->name_ = s;
			Party->vote_ = 0;
			vector<std::string> members;
			char member_name = 'a';
			for (int j = 0; j <= i; j++)
			{
				std::string mem(1, member_name);
				members.push_back(mem);
				member_name++;
			}
			Party->members_ = members;
			party_name++;
			parties.push_back(party);
		}
		
		
		vector<std::string> party1_member;
		party1_member.push_back("Ali");
		party1_member.push_back("Jeffrey");
		party1_member.push_back("Imran");
		party1_member.push_back("Hassan");

		vector<std::string> party2_member;
		party2_member.push_back("Austin");
		party2_member.push_back("Rafi");
		party2_member.push_back("Logan");
		
		vector<std::string> party3_member;
		party3_member.push_back("Branden");
		party3_member.push_back("Alan");
		party3_member.push_back("Jacob");
		party3_member.push_back("Daniel");
		party3_member.push_back("Branden");

		vector<std::string> party4_member;
		party4_member.push_back("Alexander");
		party4_member.push_back("Xiaohui");
		party4_member.push_back("Berni");
		party4_member.push_back("Tyler");
		party4_member.push_back("Celeb");
		party4_member.push_back("Raymond");

		vector<std::string> party5_member;
		party5_member.push_back("Andrew");
		party5_member.push_back("Jack");
		party5_member.push_back("Erik");
		party5_member.push_back("Jessica");


		Party* party1 = new Party();
		party1->name_ = "G";
		party1->vote_ = 0;
		party1->members_ = party1_member;

		Party* party2 = new Party();
		party2->name_ = "B";
		party2->vote_ = 0;
		party2->members_ = party2_member;

		Party* party3 = new Party();
		party3->name_ = "R";
		party3->vote_ = 0;
		party3->members_ = party3_member;

		Party* party4 = new Party();
		party4->name_ = "T";
		party4->vote_ = 0;
		party4->members_ = party4_member;

		Party* party5 = new Party();
		party5->name_ = "L";
		party5->vote_ = 0;
		party5->members_ = party5_member;

		vector<Party*>* parties2;
		parties2.push_back(party1);
		parties2.push_back(party2);
		parties2.push_back(party3);
		parties2.push_back(party4);
		parties2.push_back(party5);

		cpl_test_case2_ = new CPL(5, 70, 22, parties2);

	}

	void TearDown() override {  // Delete stuff here
		delete cpl_test_case1_;
		delete cpl_test_case2_;
	}
};

// Tests that CPL::increament() method.
TEST_F(CPLTests, CPLIncrementTest) {
	vector<Party *> * parties = cpl_test_case1_->get_parties();
	//EXPECT_EQ(*parties[1].name_, "G");
	//EXPECT_EQ(*parties[2].name_, "G");
  
	for (int each_ballot = 0; each_ballot < 10; each_ballot++)
	{ 
		int party_number = 0;
		for (int each_increment = 0; each_increment < parties.size(); each_increment++)
		{ 
			cpl_test_case1_->increment(party_number);
  
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
	


	EXPECT_EQ(cpl_test_case1_->increment(6), -1) << "There should not exist the seventh party.";
	EXPECT_EQ(cpl_test_case1_->increment(-1), -1) << "increment() index should not be negative number";
	EXPECT_EQ(cpl_test_case2_->increment(2.37), -1) << "increment() index should not be a double or float";
	EXPECT_EQ(cpl_test_case2_->increment("string"), -1) << "increment() index should not be a string";


	cpl_test_case2_->increment(2);
	EXPECT_EQ(*parties[2].votes_, 1);
	EXPECT_EQ(*parties[0].votes_, 0);
	EXPECT_EQ(*parties[1].votes_, 0);

	cpl_test_case2_->increment(2);
	EXPECT_EQ(*parties[2].votes_, 2);
	EXPECT_EQ(*parties[4].votes_, 0);

	cpl_test_case2_->increment(4);
	EXPECT_EQ(*parties[2].votes_, 2);
	EXPECT_EQ(*parties[1].votes_, 0);
	EXPECT_EQ(*parties[4].votes_, 1);
	EXPECT_EQ(*parties[0].votes_, 0);

	EXPECT_EQ(cpl_test_case2_->increment(10), -1) << "There should not exist the seventh party.";
	EXPECT_EQ(cpl_test_case2_->increment(-5), -1) << "increment() index should not be negative number";
	EXPECT_EQ(cpl_test_case2_->increment(6.07), -1) << "increment() index should not be a double or float";
	EXPECT_EQ(cpl_test_case2_->increment("string"), -1) << "increment() index should not be a string";
	
}


// Tests that CPL::get_party() method.
TEST_F(CPLTests, CPL_Get_Party_Test) {
	vector<Party*>* parties1 = cpl_test_case1_->get_parties();
	std::string party_name = "A";
	for (int each_party; each_party < parties1.size(); each_party++)
	{
		std::string s(1, party_name);
		EXPECT_EQ(*parties1[each_party].name_, s);
		party_name++;
	}
	EXPECT_EQ(*parties.size(), 6)<< " the size of the parties should be 6";

	

	vector<Party*>* parties2 = cpl_test_case2_->get_parties();

	EXPECT_EQ(*parties2[4]->name_, "L");
	EXPECT_EQ(*parties2[3]->name_, "T");

	EXPECT_EQ(*parties1[3]->members_[5], "Raymond");
	EXPECT_EQ(*parties1[4]->members_[2], "Erik");
}
