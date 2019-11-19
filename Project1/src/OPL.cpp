
#include "OPL.h"

OPL::OPL(int seats, int ballots, int candidates) : VotingType(seats, ballots, candidates) {

}

std::vector<Candidate*>* OPL::get_candidates() {
	return &candidates_;
}

int OPL::increment(int index) {
	int size_of_candidates = candidates_.size();

	if (index > size_of_candidates - 1 || index < 0)
	{
		return -1;
	}

	(*candidates_[index]).votes_++;

	return 0;


}

int OPL::Display() {
  return 0;
}

int OPL::create_txt_file() {
  return 0;
}

int OPL::winner()
{ /*
	vector<Party*> winner;
	vector<Party*> parties = *CPL::get_parties();
	int threshold = std::ceil((double)ballots_ / (double)seats_);
	int sizep = parties.size();
	int total_seats = 0;
	vector<int> remain;
	vector<int> max;
	int maximum = 0;
	for (int i = 0; i < sizep; i++)
	{
		Party* party = parties[i];
		int get_seats = floor((double)party->votes / (double)threshold);
		total_seats += get_seats;
		int rem = party->votes - get_seats * threshold;
		party->seats_won = get_seats;
		party->reminder = rem;

		if (max.empty() || rem == maximum)
		{
			max.push_back(i);
		}
		else if (rem > maximum)
		{
			max.clear();
			max.push_back(i);
			maximum = rem;
		}
		remain.push_back(rem);
	}


	while (total_seats < seats_)
	{
		if (max.size() <= seats_ - total_seats)
		{
			for (int i = 0; i < max.size(); i++)
			{
				parties[max[i]]->seats_won++;
				total_seats++;
				parties[max[i]]->reminder = 0;
			}
			maximum = 0;
			max.clear();
			for (int j = 0; j < sizep; j++)
			{
				Party* party = parties[i];
				rem = party->reminder;
				if (max.empty() || rem == maximum)
				{
					max.push_back(i);
				}
				else if (rem > maximum)
				{
					max.clear();
					max.push_back(i);
					maximum = rem;
				}
			}
		}
		else
		{
			int seats_left = seats_ - total_seats;
			vector<int> random;
			for (int i = 0; i < max.size(); i++)
			{
				int iSecret = rand() % 10 + 1;
				random.push_back(iSecret);
			}
			while (seats_left > 0)
			{
				int max_random = random[0];
				int index = 0;
				for (int i = 0; i < max.size(); i++)
				{
					if (random[i] > max_random)
					{
						max_random = random[i];
						index = i;
					}
				}
				parties[max[index]]->seats_won++;
				seats_left -= 1;
			}

		}
	}*/
	return 0;

}
