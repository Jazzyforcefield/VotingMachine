#ifndef _OPL_H
#define _OPL_H

#include "candidate.h"
#include "VotingType.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

class OPL : public VotingType
{
public:
	OPL(int seats, int ballots, int candidates);
	vector<Candidate*>* get_candidates();
	int increment(int index);
	int winner();
	int create_txt_file();
	int Display();

private:
	std::vector<Candidate*> candidates_;
};
#endif
