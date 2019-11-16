#ifndef _PARTY_H
#define _PARTY_H

#include <iostream>
using namespace std;

class Party
{
private:
    string name;
    string vote;
    vector<Candidate*> candidate;
};
#endif
