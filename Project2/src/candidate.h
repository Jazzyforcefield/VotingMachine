/**
 * \class candidate
 *
 * \brief Candidate class
 *
 * This class is candidate.  It is used for create an entity of candidate class
 * An entity of party class can have attributes like seat winner
 * name of candidate, party subordinate to, votes candidate earned.
 * no special methods
 *
 * \note Will be used in CPL and OPL to create candidate entity
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #1 $
 *
 */
#ifndef _CANDIDATE_H
#define _CANDIDATE_H

#include <iostream>

class Candidate {
 public:
   /**
   * A constructor.
   * Create an Candidate class entity with some intial values
   */
  Candidate() { seat_winner_ = 0; name_ = ""; party_ = ""; votes_ = 0; }
  /**
  * A private variable.
  * integer seats winner.
  */
  int seat_winner_;
  /**
  * A private variable.
  * string type candidate name.
  */
  std::string name_;
  /**
  * A private variable.
  * string type party name.
  */
  std::string party_;
  /**
  * A private variable.
  * integer type votes got by candidate.
  */
  int votes_;
};

#endif
