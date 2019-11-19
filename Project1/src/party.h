#ifndef _PARTY_H
#define _PARTY_H
#include "candidate.h"
#include <iostream>
#include <vector>
using namespace std;

class Party
{
    public:
        ~Party();
        Party(string name);
        string name;
        int votes;
        std::vector<Candidate*> candidate;
};
#endif
