/**
 * \class VotingType
 *
 * \brief VotingType class
 *
 * This class is VotingType.  It is used for create a entity of VotingType class
 * An entity of VotingType class can have attributes like seats, ballots, num_candidates,
 * have methods like increment, get_candidates, get_parties, CalculateWinners
 * GenerateRandomNumber, BreakTie, create_txt_file.
 *
 * \note Will be used to inherit for OPL and CPL
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
#ifndef _VOTINGTYPE_H
#define _VOTINGTYPE_H

#include <iostream>
#include <vector>

#include "party.h"
#include "candidate.h"

class VotingType {
 public:
   /**
    * @brief Constructor of VotingType
    *
    * @param seats An integer argument present seats
    *
    * @param ballots An integer argument present ballots
    *
    * @param candidates An integer argument present candidates
    *
    * @return Returns an entity of VotingType class
    **/
	VotingType(int seats, int ballots, int candidates) : seats_(seats), ballots_(ballots), num_candidates_(candidates) {};
  /**
   * @brief destructor of VotingType
   *
   **/
  virtual ~VotingType() {};
  /**
   * @brief Increment the votes of candidates of index by one
   *
   * @param index an integer argument present index of candidate in vector
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
	virtual int increment(int index) = 0;

  virtual int Display() = 0;
  /**
   * @brief Get a list of parties
   *
   * @param NULL
   *
   * @return a vector of parties
   **/
  virtual std::vector<Party *> * get_parties() { return NULL; }
  /**
   * @brief Get a list of candidates
   *
   * @param NULL
   *
   * @return a vector of candidates
   **/
  virtual std::vector<Candidate *> * get_candidates() { return NULL; }
  /**
   * @brief Calculate Winners of voting
   *
   * @param NULL
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  virtual int CalculateWinners() = 0;
  /**
   * @brief Create txt file of resutls brief
   *
   * @param NULL
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  virtual int create_txt_file() = 0;
  /**
   * @brief Get seats
   *
   * @param NULL
   *
   * @return seat an integer
   **/
  int get_seats() { return seats_; }
  /**
   * @brief Get ballots
   *
   * @param NULL
   *
   * @return ballots an integer
   **/
  int get_ballots() { return ballots_; }
  /**
   * @brief Get number of candidates
   *
   * @param NULL
   *
   * @return number of candidates
   **/
  int get_candidates_num() { return num_candidates_; }

 protected:
   /**
   * A protected variable.
   * int seat
   */
	int seats_;
  /**
  * A protected variable.
  * int ballots
  */
	int ballots_;
  /**
  * A protected variable.
  * int number of candidates
  */
	int num_candidates_;
};

#endif  // _VOTINGTYPE_H
