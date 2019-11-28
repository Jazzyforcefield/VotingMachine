#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include <iostream>

class Candidate {
 public:
  Candidate() { seat_winner_ = 0; name_ = ""; party_ = ""; votes_ = 0; }
  int seat_winner_;
  std::string name_;
  std::string party_;
  int votes_;
};

#endif
