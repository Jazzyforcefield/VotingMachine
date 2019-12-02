#ifndef _CPL_H
#define _CPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>

#include "party.h"
#include "candidate.h"
#include "VotingType.h"


class CPL : public VotingType {
public:
	CPL(int seats, int ballots, int candidates);
	std::vector<Party*>* get_parties();
	int increment(int index);
	int CalculateWinners();
	double GenerateRandomNumber(unsigned int seed = std::time(NULL));
	int create_txt_file();
	int Display();

private:
	std::vector<Party*> parties_;
	std::map<int, std::vector<int> > remainder_to_index_;
	std::set<int, std::greater<int> > remainder_;
};

#endif
