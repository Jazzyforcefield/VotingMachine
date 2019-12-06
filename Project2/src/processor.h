/**
 * \class processor
 *
 * \brief processor class
 *
 * This class is processor.  It is used for parsing input file and Calculate ballots
 * An entity of processor class can have attributes like votes, filename
 * have methods like process, parse_CPL_line, parse_OPL_line, get_one_index
 * The main class of whole voting system
 *
 * \note Will be used to process the input file and generate the results
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
#ifndef _PROCESSOR_H
#define _PROCESSOR_H

#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cstdlib>

#include "CPL.h"
#include "OPL.h"

class Processor {
 public:
   /**
    * @brief Constructor of Processor
    *
    * @param string filename
    *
    * @return Returns an entity of Processor class
    **/
  Processor(std::string fname = "");
  /**
   * @brief process the input file to generate audit file
   *
   * @param NULL
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  int process();
  /**
   * @brief parse OPL input file line by line
   *
   * @param candidate Candidate pointer
   *
   * @param line string line
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  int parse_OPL_line(Candidate * candidate, std::string line);
  /**
   * @brief parse CPL input file line by line
   *
   * @param line string line
   *
   * @return Returns 0 represent success, -1 represent failure.
   **/
  int parse_CPL_line(std::string line);
  /**
   * @brief get the candidate index in the vector
   *
   * @param line string line
   *
   * @return index of the position of candidate in thier party
   **/
  int get_one_index(std::string line);

 private:
   /**
   * A private variable.
   * VotingType pointer vote
   */
  VotingType * vote_;
  /**
  * A private variable.
  * String input filename
  */
  std::string fname_;
};

#endif  // _PROCESSOR_H
