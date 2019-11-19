#ifndef _VOTINGTYPE_H
#define _VOTINGTYPE_H

#include <iostream>
#include <vector>

#include "party.h"
#include "candidate.h"

class VotingType {
 public:
	VotingType(int seats, int ballots, int candidates) : seats_(seats), ballots_(ballots), candidates_(candidates) {};
	virtual int increment(int index) = 0;
  virtual int Display() = 0;
  virtual std::vector<Party *> * get_parties() { return NULL; }
  virtual std::vector<Candidate *> * get_candidates() { return NULL; }
  int get_seats() { return seats_; }
  int get_ballots() { return ballots_; }
  int get_candidates_num() { return candidates_; }

 protected:
	int seats_;
	int ballots_;
	int candidates_;
};

#endif  // _VOTINGTYPE_H
