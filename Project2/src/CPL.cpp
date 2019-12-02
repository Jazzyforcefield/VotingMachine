// Copyright 2019, CSCI 5801, Team 25

#include <cstdlib>

#include "CPL.h"

CPL::CPL(int seats_, int ballots_, int candidates): VotingType(seats_, ballots_, candidates)  {}

std::vector<Party*>* CPL::get_parties() {
	return &parties_;
}

int CPL::increment(int index) {
	int size_of_parties = parties_.size();

	if (index > size_of_parties - 1 || index < 0)
	{
		return -1;
	}

	(*parties_[index]).votes_++;
	printf("%d\n", (*parties_[index]).votes_);

	return 0;


}

int CPL::Display() {
  //create_txt_file();
  std::cout << "Displaying GUI" << std::endl;
  int ret = system("java display");  // Major security flaw
  if (ret < 0) {
    return -1;
  } 
	return 0;
}

int CPL::create_txt_file() {
	int winnerc = CPL::CalculateWinners();
	std::vector<Party*> parties = *CPL::get_parties();
	int sizep = parties.size();
	std::ofstream outfile;
	std::string new_file_name = "textfile.txt";
	outfile.open(new_file_name);
	outfile << "CPL\n";
	outfile << "seat: "<< seats_ << "\n";
	outfile << "ballots: " << ballots_ << "\n";
	outfile << "Number of Candidates: " << num_candidates_ << "\n";
	for (int i = 0; i < sizep; i++)
	{
		Party* party = parties_[i];
		outfile << "For party \""<< party->name_ << "\":\n";
		outfile << "It won " << party->seats_won_ << " seats\n";
		int seats_lol = party->seats_won_;
		outfile << "Winners are: ";
		int index = 0;
		if (party->seats_won_ != 0)
		{
			outfile << party->members_[index] << ", ";
			index++;
			seats_lol--;
		}
		
	}

}

int CPL::CalculateWinners() {
	std::vector<Party*> winner;
	std::vector<Party*> parties = *CPL::get_parties();
	int threshold = std::ceil((double)ballots_ / (double)seats_);
	int sizep = parties.size();
	int total_seats = 0;
	std::vector<int> remain;
	std::vector<int> max;
	int maximum = 0;
	for (int i = 0; i < sizep; i++) {
		Party* party = parties[i];
		int get_seats = floor((double)party->votes_ / (double)threshold);
		total_seats += get_seats;
		int rem = party->votes_ - get_seats * threshold;
		party->seats_won_ = get_seats;
		party->remainder_ = rem;
		
		if (max.empty() || rem == maximum) {
			max.push_back(i);
		} else if (rem> maximum) {
			max.clear();
			max.push_back(i);
			maximum = rem;
		}
		remain.push_back(rem);
	}


	while (total_seats < seats_) {
		if (max.size() <= seats_ - total_seats) {
			for (int i = 0; i < max.size(); i++) {
				parties[max[i]]->seats_won_++;
				total_seats++;
				parties[max[i]]->remainder_ = 0;
			}
			maximum = 0;
			max.clear();

			for (int j = 0; j < sizep; j++) {
				Party* party = parties[j];
				int rem = party->remainder_;
				if (max.empty() || rem == maximum) {
					max.push_back(j);
				} else if (rem > maximum) {
					max.clear();
					max.push_back(j);
					maximum = rem;
				}
			}
		} else {
			int seats_left = seats_ - total_seats;
			std::vector<int> random;
			for (int i = 0; i < max.size(); i++) {
				int iSecret = rand() % 10 + 1;
				random.push_back(iSecret);
			}
			while (seats_left > 0) {
				int max_random = random[0];
				int index = 0;
				for (int i = 0; i < max.size(); i++) {
					if (random[i] > max_random) {
						max_random = random[i];
						index = i;
					}
				}
				parties[max[index]]->seats_won_++;
				seats_left -= 1;
			}
			
		}
	}

	return 0;
}
