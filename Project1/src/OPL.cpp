
#include "OPL.h"

OPL::OPL(int seats, int ballots, int candidates) {
	VotingType(seats, ballots, candidates);


}

std::vector<Candidate*> * OPL::get_candidates() {
	return &candidates_;
}

int OPL::increment(int index) {
	int size_of_candidates = candidates_.size();

	if (index > size_of_candidates - 1 || index < 0)
	{
		return -1;
	}

	(*candidates_[index]).votes++;

	return 0;


}
