#include "CPL.h"

CPL::CPL(int seats, int ballots, int candidates) {
	VotingType(seats, ballots, candidates);


}

std::vector<Party*>* CPL::get_parties() {
	return &parties_;
}

int CPL::increment(int index) {
	int size_of_parties = parties_.size();

	if (index > size_of_parties - 1 || index < 0)
	{
		return -1;
	}

	(*parties_[index]).votes++;
	printf("%d\n", (*parties_[index]).votes);

	return 0;


}

int CPL::Display() {
	return 0;
}

int CPL::create_txt_file() {
	vector<Party*> parties = *CPL::get_parties();
	int sizep = parties.size();
	ofstream outfile;
	string new_file_name = "textfile.txt";
	outfile.open(new_file_name);
	outfile << "CPL\n";
	outfile << "Seats: "<<seats_<< "\n";
	outfile << "Ballots: " << ballots_ << "\n";
	outfile << "Nmuber of Candidates: " << candidates_ << "\n";
	for (int i = 0; i < sizep; i++)
	{
		Party* party = parties[i];
		outfile << "For party \""<< party->name << "\":\n";
		outfile << "It won " << party->seats_won << " seates\n";
		outfile << "Winners are \"" << party->name << "\":\n";
	}

}

int CPL::winner()
{
	vector<Party*> winner;
	vector<Party*> parties = *CPL::get_parties();
	int threshold = std::ceil((double)ballots_ / (double)seats_);
	int sizep = parties.size();
	int total_seats = 0
	for (int i = 0; i< sizep; i++)
	{
		Party* party = parties[i];
		int get_seats = floor((double)party->votes / (double)threshold);
		total_seats += get_seats;
		int rem = party->votes - get_seats * threshold;
		party->seats_won = get_seats;
		party->reminder = rem;
	}

	while (total_seats < seats_)
	{

	}

}