#ifndef _OPL_H
#define _OPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "candidate.h"
#include "VotingType.h"

class OPL : public VotingType {
 public:
	OPL(int seats, int ballots, int candidates);
	std::vector<Candidate*>* get_candidates();
	int increment(int index);
	int winner();
	int create_txt_file();
	int Display();

 private:
	std::vector<Candidate*> candidates_;
};

#endif
