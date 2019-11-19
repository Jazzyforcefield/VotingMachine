#ifndef _PARTY_H
#define _PARTY_H
#include "candidate.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Party
{
public:
	~Party();
	Party(string name);
	string name;
	int votes;
	int seats_won = 0;
	int reminder = 0;
	std::vector<string> members;
};
#endif
