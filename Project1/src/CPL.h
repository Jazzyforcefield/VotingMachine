#ifndef _CPL_H
#define _CPL_H

#include "party.h"
#include "candidate.h"
#include "VotingType.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>


class CPL : public VotingType {
public:
	CPL(int seats, int ballots, int candidates);
	std::vector<Party*>* get_parties();
	int increment(int index);
	int winner();
	int create_txt_file();
	int Display();

private:
	std::vector<Party*> parties_;
};

#endif
