#ifndef _CPL_H
#define _CPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>

#include "party.h"
#include "candidate.h"
#include "VotingType.h"

class CPL {
public:
	CPL(int seats, int ballots, int candidates);
	vector<Party*>* get_parties();
	int increment(int index);
  int Display();
  int create_txt_file();
  int winner();

private:
	std::vector<Party*> parties_;
};

#endif
