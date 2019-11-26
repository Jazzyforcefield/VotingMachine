// Copyright 2019, CSCI 5801, Team 25

#include "OPL.h"

OPL::OPL(int seats, int ballots, int candidates) : VotingType(seats, ballots, candidates) {

}

std::vector<Candidate*>* OPL::get_candidates() {
	return &candidates_;
}

int OPL::increment(int index) {
	int size_of_candidates = candidates_.size();

	if (index > size_of_candidates - 1 || index < 0) {
		return -1;
	}
  *candidates_[index].votes_++;

	return 0;
}

int OPL::Display() {
  return 0;
}

int OPL::create_txt_file() {
  return 0;
}

int OPL::CalculateWinners() {
  if (seats_ < 1 || num_candidates_ < seats_ || num_candidates_ < 0) {
    std::cout << "Invalid election parameters" << std::endl;
    return -1;
  }

  // Variables to track tied candidates and copy of candidate_ vector
  std::vector<Candidate *> tied_candidates;
  std::vector<Candidate *> intermediate(candidates_.begin(), candidates_.end());
  int remaining_seats = seats_;
  int max;
  
	return 0;
}

int OPL::BreakTie(std::vector<Candidate *>& tied_candidates) {  // Returns index of winner
  int numc, seed, rmax, maxi;
  numc = tied_candidates.size();
  seed = std::time(NULL);   // Technically insecure from security standpoint
  double random_numbers[numc];

  // Generate random numbers for each of the tied candidates
  for (int i = 0; i < numc; i++) {
    random_numbers[i] = GenerateRandomNumber(seed);
    seed = random_numbers[i];
  }

  // Finds the index and the max random number
  rmax = random_numbers[0];
  for (int i = 0; i < numc; i++) {
    rmax = (random_numbers[i] >= rmax) ? random_numbers[i] : rmax;
    maxi = (random_numbers[i] >= rmax) ? random_numbers[i] : maxi;
  }

  return maxi;
}

double OPL::GenerateRandomNumber(unsigned int seed) {
  // Setting the first seed to the current UNIX time, seed thereafter
  std::srand(seed);
  return rand() * rand() / 73042.93;
}

int OPL::GetMaxVotes(std::vector<Candidate *>& intermediate) {
  int sizec, max;
  sizec = intermediate.size();

  if (sizec < 1) {
    std::cout << "No candidates in vector candidates_." << std::endl;
    return -1;
  }

  // Finds max votes of candidates
  max = intermediate[0]->votes_;
  for (int i = 1; i < sizec; i++) {
    max = (intermediate[i]->votes_ > max) ? intermediate[i]->votes_ : max;
  }

  return max;
}
