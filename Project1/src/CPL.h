#ifndef _CPL_H
#define _CPL_H
#include "party.h"
#include "candidate.h"
#include "VotingType.h"
#include <iostream>
#include <vector>

class CPL {
public:
	CPL(int seats, int ballots, int candidates);
	vector<Party*>* get_parties();
	int increment(int index);
private:
	std::vector<Party*> parties_;
};

#endif
