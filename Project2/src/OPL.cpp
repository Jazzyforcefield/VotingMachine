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
  (*candidates_[index]).votes_++;

	return 0;
}

int OPL::Display() {
  return 0;
}

int OPL::create_txt_file() {
  std::ofstream o("result.txt");
    std::ifstream f("temp.txt");
    std::string line;
    if (!o) {
        std::cout << "Error occurred in opening result file" << std::endl;
        return -1;
    }
    if (!f) {
        std::cout << "Invalid file" << std::endl;
        return -1;
    }

    o << "Type of election : OPL"  << std::endl;
    o << "Number of seats: "  << seats_ << std::endl;
    o << "Number of ballots: "  << ballots_ << std::endl;
    o << "Number of candidates: "  << static_cast<int>(candidates_.size()) << std::endl;
    while(std::getline(f, line)){
        o << line << std::endl;
    }
    

  return 0;
}

int OPL::CalculateWinners() {
    std::ofstream o("temp.txt");
  std::cout << "CALCULATING" << std::endl;
  if (seats_ < 1 || num_candidates_ < seats_ || num_candidates_ < 0) {
    std::cout << "Invalid election parameters" << std::endl;
    return -1;
  }

  // Variables to track tied candidates and copy of candidate_ vector
  std::vector<Candidate *> tied_candidates;
  std::vector<Candidate *> intermediate(candidates_.begin(), candidates_.end());
  std::vector<int> tied_indices;
  std::vector<int> indices;
  int remaining_seats, max, winner_index;   // If you want the index of the winner, is it called Windex?
  remaining_seats = seats_;
  winner_index = -1;

  for (int i = 0; i < num_candidates_; i++) {
    indices.push_back(i);
  }

  // When there are still seats remaining, keep assigning seats
  while (remaining_seats > 0) {
    std::cout << "SEATS: " << remaining_seats << std::endl;

    // Add all candidates with the same number of votes to the vector
    if (tied_candidates.empty()) {
      int sizec = static_cast<int>(intermediate.size());
      max = GetMaxVotes(intermediate);
      std::cout << "MAX: " << max << std::endl;

      for (int i = 0; i < sizec; i++) {
        if (intermediate[i]->votes_ == max) {
            o << "Candidate \"" << intermediate[i]->name_ << "\" from [" << intermediate[i]->party_ << "] won " << max << " ballots. " << std::endl;
          tied_candidates.push_back(intermediate[i]);
          tied_indices.push_back(indices[i]);
        }
      }
    }

    // Break a tie if present and assign seat
    if (tied_candidates.size() < 1) {
      std::cout << "Unexpected error has occurred in function CalculateWinners!" << std::endl;
      exit(1);
    } else {
      winner_index = BreakTie(tied_candidates);
      std::cout << "windex: " << winner_index << " size: " << tied_candidates.size() << std::endl;
      tied_candidates[winner_index]->seat_winner_ = 1;
      tied_candidates.erase(tied_candidates.begin() + winner_index);
      intermediate[tied_indices[winner_index]]->votes_ = -1;
      tied_indices.erase(tied_indices.begin() + winner_index);
      remaining_seats--;
    }
  }

	return 0;
}

int OPL::BreakTie(std::vector<Candidate *>& tied_candidates) {  // Returns index of winner
  int numc, seed, rmax, maxi;
  double random_numbers[numc];
  numc = tied_candidates.size();
  seed = std::time(NULL);   // Technically insecure from security standpoint
  maxi = 0;

  if (numc < 1) { // Ideally shoud never happen
    std::cout << "Invalid number of candidates in function BreakTie" << std::endl;
    return -1;
  } else if (numc == 1) {
    return 0;
  }

  // Generate random numbers for each of the tied candidates
  for (int i = 0; i < numc; i++) {
    random_numbers[i] = GenerateRandomNumber(seed);
    seed = random_numbers[i];
  }

  // Finds the index and the max random number
  rmax = random_numbers[0];
  for (int i = 0; i < numc; i++) {
    rmax = (random_numbers[i] >= rmax) ? random_numbers[i] : rmax;
    maxi = (random_numbers[i] >= rmax) ? i : maxi;
  }

  return maxi;
}

double OPL::GenerateRandomNumber(unsigned int seed) {
  // Setting the first seed to the current UNIX time, seed thereafter
  std::srand(seed);
  return std::rand() * std::rand() / 73042.93;
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
