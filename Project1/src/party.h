#ifndef _PARTY_H
#define _PARTY_H

#include <iostream>
#include <vector>
#include <string>

#include "candidate.h"

class Party {
 public:
	Party(string party_name = "") { name = party_name; }
	string name;
	int votes;
	int seats_won = 0;
	int reminder = 0;
	std::vector<string> members;
};

#endif  // _PARTY_H
