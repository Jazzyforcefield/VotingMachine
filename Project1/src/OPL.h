#ifndef _OPL_H
#define _OPL_H

#include <iostream>
#include <vector>
using namespace std;

class OPL
{
public:
    vector<Candidate> get_candidates();
    int increment();
    int display();
    int create_txt_file();
private:
    std::vector<Candidate> candidates;
};
#endif
