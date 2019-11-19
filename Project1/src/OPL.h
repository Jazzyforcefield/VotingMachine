#ifndef _OPL_H
#define _OPL_H
#include "party.h"
#include "candidate.h"
#include "VotingType.h"
#include <iostream>
#include <vector>
using namespace std;

class OPL
{
public:
	OPL(int seats, int ballots, int candidates);
	vector<Candidate*>* get_candidates();
	int increment(int index);
private:
	std::vector<Candidate*> candidates_;
};
#endif
