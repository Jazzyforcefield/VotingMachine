#ifndef _PARTY_H
#define _PARTY_H

#include <iostream>
#include <vector>
using namespace std;

class Party
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
