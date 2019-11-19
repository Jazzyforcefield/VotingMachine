#ifndef _VOTINGTYPE_H
#define _VOTINGTYPE_H
#include "party.h"
#include "candidate.h"
#include "CPL.h"
#include "OPL.h"
#include <iostream>
#include <vector>
using namespace std;

class VotingType
{
public:
	VotingType(int seats, int ballots, int candidates);
	int increment(int index);
private:
	int seats_;
	int ballots_;
	int candidates_;
};
#endif