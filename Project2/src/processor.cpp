// Copyright 2019, CSCI 5801 Team 25

#include "processor.h"

Processor::Processor(std::string fname) {
	fname_ = fname;
}

int Processor::process() {
  std::ifstream f(fname_);
  std::ofstream o("audit.txt");
  std::string line;
  std::string part;

  if (!f) {
    std::cout << "Invalid file" << std::endl;
    return -1;
  }

  if (!o) {
    std::cout << "Error occurred in opening audit file" << std::endl;
    return -1;
  }

  std::getline(f, line);
  o << line << std::endl;
  std::cout << line << std::endl;
  if (!line.compare("OPL")) {
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
  } else if (!line.compare("CPL")) {
    int party_count, seats, ballots, candidates;
    std::getline(f, line);
    o << line << std::endl;
    party_count = std::stoi(line);
    std::getline(f, line);
    o << "[" << line << "]" << std::endl;
    part = line;

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

    int j = 0;
    std::vector<std::string> partytokens;
    std::stringstream partystream(part);
    std::string temp;
    while (std::getline(partystream, temp, ',')) {
      partytokens.push_back(temp);
    }

    for (int i = 0; i < party_count; i++) {
      Party * party = new Party();
      party->name_ = partytokens[i];
      party->votes_ = 0;
      vote_->get_parties()->push_back(party);
    }
    while (j < candidates) {
      std::getline(f, line);
      o << "[" << line << "]" << std::endl;
      int result = parse_CPL_line(line);
      if (result == 0) {
        j++;
      } else {
        break;
      }
    }
      
  
  } else {
    std::cout << "Unexpected voting type" << std::endl;
    return -1;
  }

  // Start processing the votes
  int seats = vote_->get_seats();
  int ballots = vote_->get_ballots();
  int candidates = vote_->get_candidates_num();

  for (int i = 0; i < ballots; i++) {
    std::getline(f, line);
    o << line << std::endl;
    int index = get_one_index(line);
    vote_->increment(index);
  }
  vote_->CalculateWinners();
  vote_->Display();
  vote_->create_txt_file();
}

int Processor::parse_OPL_line(Candidate * candidate, std::string line) {
  std::vector<std::string> tokens;
  std::stringstream linestream(line);

  std::string temp;

  while (std::getline(linestream, temp, ',')) {
    tokens.push_back(temp);
  }

  if (tokens.size() != 2) {
    std::cout << "Invalid amount of tokens" << std::endl;
    return -1;
  }

  candidate->name_ = tokens[0];
  candidate->party_ = tokens[1];
  return 0;
}

int Processor::parse_CPL_line(std::string line) { // Sets party attributes
  std::vector<std::string> tokens;
  std::stringstream linestream(line);

  std::string temp;

  while (std::getline(linestream, temp, ',')) {
    tokens.push_back(temp);
  }

  if (tokens.size() != 3) {
    std::cout << "Invalid amount of tokens" << std::endl;
    return -1;
  }
  
  std::vector<Party *> * parties = vote_->get_parties(); 
  for (int i = 0; i< parties->size();i++)
  {
	Party * party = (*parties)[i];
  	if (tokens[1].compare(party->name_ )== 0) {
  		party->members_.push_back(tokens[0]);
	}
  }
  return 0;
}

int Processor::get_one_index(std::string line) {
  std::vector<std::string> tokens;
  std::stringstream linestream(line);
  int count = 0;
  std::string temp;

  while (std::getline(linestream, temp, ',')) {
    if (!temp.compare("1")) {
      return count;
    }
    count++;
  }

  return -1;
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
