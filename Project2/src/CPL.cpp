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
	std::cout<< "Party: "<< (*parties_[index]).name_<<" :"<< (*parties_[index]).votes_ <<std::endl;

	return 0;


}

int CPL::Display() {
	return 0;
}

int CPL::create_txt_file() {
	
	std::cout<< "--------------Creating txt file--------------"<<std::endl;
	std::vector<Party*> parties = *CPL::get_parties();
	int sizep = parties.size();
	
	std::cout << "CPL\n";
	std::cout << "seat: "<< seats_ << "\n";
	std::cout << "ballots: " << ballots_ << "\n";
	std::cout << "Number of Candidates: " << num_candidates_ << "\n\n";
	for (int i = 0; i < sizep; i++)
	{
		Party* party = parties[i];
		std::cout<< "For party ["<< party->name_ << "] :";
		if (party->seats_won_!=0)
		{
			std::cout<< "It won " << party->seats_won_ << " seats\n";
			int seats_lol = party->seats_won_;
			int index = 0;
			std::cout << "Winners are: ";
			while (seats_lol!= 0)
			{
				std::cout << party->members_[index] << ", ";
				seats_lol--;
				index++;
			}
			std::cout<<"\b\b\n";
		}
		else
		{
			std::cout<<"NO one won in this party"<<std::endl;
		}
		
	}

	return 0;

}

double CPL::GenerateRandomNumber(unsigned int seed) {
  // Setting the first seed to the current UNIX time, seed thereafter
  std::srand(seed);
  return std::rand() * std::rand() / 73042.93;
}

int CPL::CalculateWinners() {
	std::cout<< "--------------Calculating--------------"<<std::endl;
	std::vector<Party*> parties = *CPL::get_parties();
	int threshold = std::ceil((double)ballots_ / (double)seats_);
	std::cout<< "Threshold is: "<<threshold<<std::endl; 
	int total_seats = 0;
	for (int i = 0; i < parties.size(); i++) {
		Party* party = parties[i];
		std::cout<< "Party "<<party->name_ ;
		std::cout<< " has "<< (party->members_).size()<<" members and";
		int get_seats = floor((double)party->votes_ / (double)threshold);
		int rem = party->votes_ - get_seats * threshold;;
		if (get_seats>= (party->members_).size())
		{
			get_seats = (party->members_).size();
			rem = 0;
		}
		std::cout<< " gets seats: " << get_seats<<std::endl;
		total_seats += get_seats;
		std::cout << "remainder is "<<rem<<std::endl;
		remainder_to_index_[rem].push_back(i);
		party->seats_won_ = get_seats;
		
		remainder_.insert(rem);
		
	}
	
	//int round = 0;
 	while (total_seats < seats_) {
		int seats_left = seats_ - total_seats;
		std::cout<< "seats left: "<<seats_left<<std::endl;
		auto max = remainder_.begin();
		std::vector<int> pindex_has_max_remainder = remainder_to_index_[*max];
		/*
		round++;
		if (round == 10)
		{
			break;
		}
		*/
		if (pindex_has_max_remainder.size()<= seats_left) {
			//std::cout<<"666"<<std::endl;
			for (int i = 0; i < pindex_has_max_remainder.size(); i++) {
				//std::cout<<"777"<<std::endl;
				parties[pindex_has_max_remainder[i]]->seats_won_++;
				std::cout<< parties[pindex_has_max_remainder[i]]->name_ << " get one seats"<<std::endl;
				total_seats++;
				remainder_to_index_[0].push_back(pindex_has_max_remainder[i]);
	
			}
			remainder_.erase(*max);
		} 
		else {
			std::cout<<"Final round!!!!"<<std::endl;
			int seed = std::time(NULL); 
			std::vector<double> random;
			std::map<double,int> randomnumber_to_index; 
			for (int i = 0; i < pindex_has_max_remainder.size(); i++) {
				double random_number = GenerateRandomNumber(seed);
				random.push_back(random_number);
				seed = std::floor(random_number);
				randomnumber_to_index[random_number] = pindex_has_max_remainder[i];
				
			}
			std::sort(random.begin(),random.end());
			for (int j = 0; j< seats_left ; j++) {
				parties[randomnumber_to_index[random[j]]]->seats_won_++;
				std::cout<< parties[randomnumber_to_index[random[j]]]->name_ << " get one seats"<<std::endl;
				total_seats++;
			}
			
		}
	}
	std::cout<< "\n\n ----------------finished----------------\n\n";
	return 0;
}
