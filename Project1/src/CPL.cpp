
#include "CPL.h"

CPL::CPL(int seats, int ballots, int candidates ) {
  VotingType(seats, ballots, candidates);


}

std::vector<Party*> * CPL::get_parties() {
	return &parties_;
}

int CPL::increment(int index) {
	int size_of_parties = parties_.size();

	if (index > size_of_parties - 1 || index <0)
	{
		return -1;
	}
	
	(*parties_[index]).votes++ ;
    printf("%d\n",(*parties_[index]).votes);

	return 0;


}

