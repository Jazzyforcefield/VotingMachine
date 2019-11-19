#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "CPL.h"
#include "OPL.h"

class Processor {
 public:
  Processor(std::string fname = "");
  int process();
  int parse_OPL_line(Candidate * candidate, string line);
  int parse_CPL_line(Party * party, string line);
  int get_one_index(std::string line);
  
 private:
  VotingType * vote_;
  std::string fname_;
};

#endif  // _PROCESSOR_H
