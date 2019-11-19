#ifndef _CPL_H
#define _CPL_H

#include <iostream>
#include <vector>

class CPL {
 public:
  CPL(int seats, int ballots, int candidates, std::vector<Party *> *);
  vector<Party *> * get_parties();
  int increment(int index);
  int Display();
  int create_txt_file();

 private:
  std::vector<Party *> parties;
};

#endif
