#ifndef _PARTY_H
#define _PARTY_H

#include <iostream>
#include <vector>
#include <string>

#include "candidate.h"

class Party {
 public:
	Party(std::string party_name = "") { name_ = party_name; }
	std::string name_;
	int votes_;
	int seats_won_ = 0;
	int remainder_ = 0;
	std::vector<std::string> members_;
};

#endif  // _PARTY_H
