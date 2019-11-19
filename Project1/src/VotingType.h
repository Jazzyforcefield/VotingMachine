#ifndef _VOTINGTYPE_H
#define _VOTINGTYPE_H

#include <iostream>
#include <vector>
using namespace std;

class VotingType
{
public:
	VotingType(int seats, int ballots, int candidates): seats_(seats), ballots_(ballots), candidates_(candidates) {};
	int increment(int index);
protected:
	int seats_;
	int ballots_;
	int candidates_;
};
#endif
