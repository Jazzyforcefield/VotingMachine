/**
 * \class party
 *
 * \brief Party class
 *
 * This class is party.  It is used for create a entity of party class
 * An entity of party class can have attributes like partyname
 * votes, seats won, candidates members.
 * no special methods
 *
 * \note Will be used in CPL and OPL to create party entity
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #2 $
 *
 */
#ifndef _PARTY_H
#define _PARTY_H

#include <iostream>
#include <vector>
#include <string>

#include "candidate.h"

class Party {
 public:
   /**
   * A constructor.
   * Create an Partyclass entity with some intial values
   */
	Party(std::string party_name = "") { name_ = party_name; seats_won_ = 0; votes_ = 0;}
  /**
  * A private variable.
  * string type party name.
  */
	std::string name_;
  /**
  * A private variable.
  * integer type votes got by party.
  */
	int votes_;
  /**
  * A private variable.
  * integer type seats won by party.
  */
	int seats_won_;
  /**
  * A private variable.
  * string vector candidates member.
  */
	std::vector<std::string> members_;
};

#endif  // _PARTY_H
