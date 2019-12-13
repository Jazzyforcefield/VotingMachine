//Copyright 2019, Zhuoran Bi CSCI 5801

#include <string>
#include <iostream>

#include "../src/CPL.h"
#include "gtest/gtest.h"

// Test feature for CPL class
class CPLTests : public ::testing::Test {
	protected:
	CPL* cpl_test_case1_;
	CPL* cpl_test_case2_;

	void SetUp() override { // Initialize things here
		
		cpl_test_case1_ = new CPL(5, 60, 21);
		int n_parties = 6;
		std::vector<Party*> * parties = cpl_test_case1_->get_parties();
		char party_name = 'A';
		for (int i = 0; i < n_parties ; i++)
		{
			Party* party = new Party();
			std::string s(1, party_name);
			party->name_ = s;
			party->votes_ = 0;
			std::vector<std::string> members;
			char member_name = 'a';
			for (int j = 0; j <= i; j++)
			{
				std::string mem(1, member_name);
				members.push_back(mem);
				member_name++;
			}
			party->members_ = members;
			party_name++;
			parties->push_back(party);
		}
		
		
		std::vector<std::string> party1_member;
		party1_member.push_back("Ali");
		party1_member.push_back("Jeffrey");
		party1_member.push_back("Imran");
		party1_member.push_back("Hassan");

		std::vector<std::string> party2_member;
		party2_member.push_back("Austin");
		party2_member.push_back("Rafi");
		party2_member.push_back("Logan");
		
		std::vector<std::string> party3_member;
		party3_member.push_back("Branden");
		party3_member.push_back("Alan");
		party3_member.push_back("Jacob");
		party3_member.push_back("Daniel");
		party3_member.push_back("Branden");

		std::vector<std::string> party4_member;
		party4_member.push_back("Alexander");
		party4_member.push_back("Xiaohui");
		party4_member.push_back("Berni");
		party4_member.push_back("Tyler");
		party4_member.push_back("Celeb");
		party4_member.push_back("Raymond");

		std::vector<std::string> party5_member;
		party5_member.push_back("Andrew");
		party5_member.push_back("Jack");
		party5_member.push_back("Erik");
		party5_member.push_back("Jessica");


		Party* party1 = new Party();
		party1->name_ = "G";
		party1->votes_ = 0;
		party1->members_ = party1_member;

		Party* party2 = new Party();
		party2->name_ = "B";
		party2->votes_ = 0;
		party2->members_ = party2_member;

		Party* party3 = new Party();
		party3->name_ = "R";
		party3->votes_ = 0;
		party3->members_ = party3_member;

		Party* party4 = new Party();
		party4->name_ = "T";
		party4->votes_ = 0;
		party4->members_ = party4_member;

		Party* party5 = new Party();
		party5->name_ = "L";
		party5->votes_ = 0;
		party5->members_ = party5_member;

		cpl_test_case2_ = new CPL(5, 70, 22);

		std::vector<Party*>* parties2 = cpl_test_case2_->get_parties();
		parties2->push_back(party1);
		parties2->push_back(party2);
		parties2->push_back(party3);
		parties2->push_back(party4);
		parties2->push_back(party5);


	}

	void TearDown() override {  // Delete stuff here
		delete cpl_test_case1_;
		delete cpl_test_case2_;
	}
};

// Tests that CPL::increament() method.
TEST_F(CPLTests, CPL_Increment_Test) {
	std::vector<Party *> * parties = cpl_test_case1_->get_parties();
	//EXPECT_EQ(*parties[1].name_, "G");
	//EXPECT_EQ(*parties[2].name_, "G");
  
	for (int each_ballot = 0; each_ballot < 10; each_ballot++)
	{ 
		int party_number = 0;
    		int parties_size = parties->size();

		for (int each_increment = 0; each_increment < parties_size; each_increment++)
		{ 
			cpl_test_case1_->increment(party_number);
  
			for (int each_party = 0; each_party < parties_size; each_party++)
			{
				if (each_party > party_number)
				{
					EXPECT_EQ((*parties)[each_party]->votes_, each_ballot) << "ballot added to wrong party";
				}
				else
				{
					EXPECT_EQ((*parties)[each_party]->votes_, each_ballot+1) << "ballot didn't add to the right party";
				}
			}
			party_number++;
		}
	}
	


	EXPECT_EQ(cpl_test_case1_->increment(6), -1) << "There should not exist the seventh party.";
	EXPECT_EQ(cpl_test_case1_->increment(-1), -1) << "increment() index should not be negative number";

	std::vector<Party *> * parties2 = cpl_test_case2_->get_parties();
	cpl_test_case2_->increment(2);
	EXPECT_EQ((*parties2)[2]->votes_, 1);
	EXPECT_EQ((*parties2)[0]->votes_, 0);
	EXPECT_EQ((*parties2)[1]->votes_, 0);

	cpl_test_case2_->increment(2);
	EXPECT_EQ((*parties2)[2]->votes_, 2);
	EXPECT_EQ((*parties2)[4]->votes_, 0);

	cpl_test_case2_->increment(4);
	EXPECT_EQ((*parties2)[2]->votes_, 2);
	EXPECT_EQ((*parties2)[1]->votes_, 0);
	EXPECT_EQ((*parties2)[4]->votes_, 1);
	EXPECT_EQ((*parties2)[0]->votes_, 0);

	EXPECT_EQ(cpl_test_case2_->increment(10), -1) << "There should not exist the seventh party.";
	EXPECT_EQ(cpl_test_case2_->increment(-5), -1) << "increment() index should not be negative number";
	
}


// Tests that CPL::get_party() method.
TEST_F(CPLTests, CPL_Get_Party_Test) {
	std::vector<Party*> parties1 = *(cpl_test_case1_->get_parties());
	EXPECT_EQ(parties1.size(), 6) << " the size of the parties should be 6";

	

	std::vector<Party*>* parties2 = cpl_test_case2_->get_parties();

	EXPECT_EQ((*parties2)[4]->name_, "L");
	EXPECT_EQ((*parties2)[3]->name_, "T");
	

	EXPECT_EQ((*parties2)[4]->members_[2], "Erik");
	EXPECT_EQ((*parties2)[3]->members_[3], "Tyler");

	EXPECT_EQ(parties1[3]->members_[1], "b");
	EXPECT_EQ(parties1[4]->members_[3], "d");
}
