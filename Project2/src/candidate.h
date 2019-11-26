#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include <iostream>

class Candidate {
 public:
  int seat_winner_;
  std::string name_;
  std::string party_;
  int votes_;
};

#endif
