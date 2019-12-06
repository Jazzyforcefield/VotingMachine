/**
 * \class OPL
 *
 * \brief OPL class
 *
 * This class is OPL.  It is used for create a entity of OPL class inherited
 * from VotingType. An entity of OPL class can have attributes like candidates
 * have methods like increment, get_candidates, GetMaxVotes, CalculateWinners
 * GenerateRandomNumber, BreakTie, create_txt_file.
 *
 * \note Will be used in processor to create OPL entity
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #5 $
 *
 */

#ifndef _OPL_H
#define _OPL_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "candidate.h"
#include "VotingType.h"

class OPL : public VotingType {
 public:
 /**
  * @brief Constructor of OPL
  *
  * @param seats An integer argument present seats
  *
  * @param ballots An integer argument present ballots
  *
  * @param candidates An integer argument present candidates
  *
  * @return Returns an entity of OPL class
  **/
	OPL(int seats, int ballots, int candidates);
  /**
   * @brief Get a list of candidates of OPL
   *
   * @param NULL
   *
   * @return a vector of candidates
   **/
	std::vector<Candidate *> * get_candidates() override;
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
   * @brief Gets the value of the max number of votes a candidate has
   *
   * @param intermediate A Candidate * vector
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  int GetMaxVotes(std::vector<Candidate *>& intermediate);
  /**
   * @brief Generate random number with time seeds
   *
   * @param seed an int time seed
   *
   * @return a double random number
   **/
  double GenerateRandomNumber(unsigned int seed = std::time(NULL));
  /**
   * @brief Break tie with generate random number function
   *
   * @param tied_candidates candidate vector
   *
   * @return index of the winner in party list
   **/
  int BreakTie(std::vector<Candidate *>& tied_candidates);
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
	std::vector<Candidate*> candidates_;
};

#endif
