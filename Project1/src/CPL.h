#ifndef _CPL_H
#define _CPL_H

#include <iostream>
#include <vector>
using namespace std;

class CPL
{
public:
    ~CPL();
    vector<Party> get_parties();
    int increment();
    int display();
    int create_txt_file();
private:
    std::vector<Party> parties;
};
#endif
