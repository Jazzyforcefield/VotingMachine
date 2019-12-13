/**
 * \class CPL
 *
 * \brief CPL class
 *
 * This class is CPL.  It is used for create a entity of CPL class inherited
 * from VotingType. An entity of CPL class can have attributes like parties,
 * remainder, remainder to index
 * have methods like increment, get_parties, CalculateWinners, CalculateWinners
 * GenerateRandomNumber, BreakTie, create_txt_file.
 *
 * \note Will be used in processor to create CPL entity
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #4 $
 *
 */

#ifndef _CPL_H
#define _CPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>

#include "party.h"
#include "candidate.h"
#include "VotingType.h"


class CPL : public VotingType {
public:
	/**
   * @brief Constructor of CPL
   *
   * @param seats An integer argument present seats
   *
   * @param ballots An integer argument present ballots
   *
   * @param candidates An integer argument present candidates
   *
   * @return Returns an entity of CPL class
   **/
	CPL(int seats, int ballots, int candidates);
	/**
   * @brief Get a list of parties of CPL
   *
   * @param NULL
   *
   * @return a vector of parties
   **/
	std::vector<Party*>* get_parties();
	/**
	 * @brief Increment the votes of candidates of index by one
	 *
	 * @param index an integer argument present index of candidate in vector
	 *
	 * @return Returns 0 represent success, -1 represent failure.
	 **/
	int increment(int index);
	/**
	 * @brief Calculate Winners of voting
	 *
	 * @param NULL
	 *
	 * @return Returns 0 represent success, -1 represent failure.
	 **/
	int CalculateWinners();
	/**
	 * @brief Generate random number with time seeds
	 *
	 * @param seed an int time seed
	 *
	 * @return a double random number
	 **/
	double GenerateRandomNumber(unsigned int seed = std::time(NULL));
	/**
	 * @brief Create txt file of resutls brief
	 *
	 * @param NULL
	 *
	 * @return Returns 0 represent success, -1 represent failure.
	 **/
	int create_txt_file();
	int Display();

private:
	/**
	* A private variable.
	* Candidate vector candidates member.
	*/
	std::vector<Party*> parties_;
	/**
	* A private variable.
	* map index and vector pair
	*/
	std::map<int, std::vector<int> > remainder_to_index_;
	/**
	* A private variable.
	* set index and greater pair
	*/
	std::set<int, std::greater<int> > remainder_;
};

#endif
