#ifndef _OPL_H
#define _OPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "candidate.h"
#include "VotingType.h"

class OPL : public VotingType {
 public:
	OPL(int seats, int ballots, int candidates);
	std::vector<Candidate *> * get_candidates();
	int increment(int index);
	int CalculateWinners();

  /**
   * @brief Gets the value of the max number of votes a candidate has
   *
   * @param[in] A Candidate * vector
   *
   * @param[out] Returns the max number of votes of a Candidate * vector
   **/
  int GetMaxVotes();
  double GenerateRandomNumber(unsigned int seed = std::time(NULL));
  int BreakTie(std::vector<Candidate *> tied_candidates);
	int create_txt_file();
	int Display();

 private:
	std::vector<Candidate*> candidates_;
};

#endif
