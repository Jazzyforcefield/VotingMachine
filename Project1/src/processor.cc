#include <iostream>
#include <fstream>
#include <cstdlib>

#include "processor.h"

Processor::Processor(std::string fname) {
	fname_ = fname;
}

int Processor::process() {
  std::ifstream f;
  std::ofstream o;
  std::string line;
  std::vector<string>;

  int result = f.open(fname_);
  if (result < 0) {
    std::cout << "Invalid file" << std::endl;
    return -1;
  }

  result = o.open("audit.txt");
  if (result < 0) {
    std::cout << "Error occurred in opening audit file" << std::endl;
    return -1;
  }

  std::getline(f, line);
  if (line.compare("OPL") == 0) {
    int seats, ballots, candidates;

    std::getline(f, line);
    o << line << std::endl;
    seats = std::stoi(line);
    std::getline(f, line);
    o << line << std::endl;
    ballots = std::stoi(line);
    std::getline(f, line);
    o << line << std::endl;
    candidates = std::stoi(line);

    vote_ = new OPL(seats, ballots, candidates);

    for (int i = 0; i < candidates; i++) {
      Candidate * cand = new Candidate();
      std::getline(f, line);
      o << line << std::endl;
      parse_OPL_line(cand, line);
      vote_->get_candidates()->push_back(cand);
    }
  } else if (line.compare("CPL")) {
    int party_count, seats, ballots, candidates;
    std::getline(f, line);
    o << line << std::endl;
    party_count = std::stoi(line);
    std::getline(f, line);
    o << line << std::endl;

    std::getline(f, line);
    o << line << std::endl;
    seats = std::stoi(line);
    std::getline(f, line);
    o << line << std::endl;
    ballots = std::stoi(line);
    std::getline(f, line);
    o << line << std::endl;
    candidates = std::stoi(line);

    vote_ = new CPL(seats, ballots, candidates);

    int broken = 0;
    int j = 0;
    for (int i = 0; i < party_count; i++) {
      Party * party = new Party();
      if (broken == 1) {
        parse_CPL_line(party, line);
        broken = 0;
      }

      while (j < candidates) {
        std::getline(f, line);
        o << "[" << line << "]" << std::endl;
        int result = parse_CPL_line(party, line);
        if (result == 0) {
          j++;
        } else {
          broken = 1;
          break;
        }
      }
      vote_->get_parties()->push_back(party);
    }
  } else {
    std::cout << "Unexpected voting type" << std::endl;
    return -1;
  }

  // Start processing the votes
  int seats = vote_->get_seats();
  int ballots = vote_->get_ballots();
  int candidates = vote_->get_candidates();

  for (int i = 0; i < ballots; i++) {
    std::getline(f, line);
    o << line << std::endl;
    int index = get_one_index(line);
    vote_->increment(index);
  }
}

int Processor::parse_OPL_line(Candidate * candidate, string line) {
  std::vector
}

int Processor::parse_CPL_line(Party * party, string line) { // Sets party attributes

}

int Processor::get_one_index(std::string line) {

}

/*
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
*/
