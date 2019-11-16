#include "processor.h"
#include <iostream>
using namespace std;

Processor::Processor(const char* fname) {
	f.open(fname);
	if (f.is_open()) {
		cout << "Open file '" << filename << "' successfully." << endl;
	}
	else
		cerr << "Fail to open file '" << filename << "'." << endl;
}

std::vector<std::string> parsing(std::ifstream& f)
{
    std::vector<std::string> words;
    std::string line;
    std::getline(f,line);

    std::stringstream lineStream(line);
    std::string elem;
    
    while(std::getline(lineStream,elem, ','))
    {
        result.push_back(elem);
    }
    // check for no elements after comma
    if (!lineStream && elem.empty())
    {
        // push empty to the comma
        words.push_back("");
    }
    return words;
}

}
