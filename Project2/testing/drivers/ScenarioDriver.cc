// Copyright 2019, Team 25, CSCI 5801
/**
 * \class ScenarioDriver
 *
 * \brief ScenarioDriver
 *
 * This is the main() fucntion entry.  It is used for driving all the scenario
 * The main() function is the entry for driving all scenario to run the test
 * expected results and actual results of input file.
 * The erorr file with fault file name are tested as well.
 *
 * \note Will be used to drive all scenario
 *
 * \author Team25
 *
 * \version $Revision: 1.0 $
 *
 * \date $Date: 2019/12/01 $
 *
 * Contact: csci5801-fall2019-team25@umn.edu
 *
 * $structure id: #14 $
 *
 */
#include <iostream>
#include <string>

#include "src/processor.h"
/**
 * A public variable.
 * integer verbose.
 */
int verbose;
/**
 * A public variable.
 * string filename.
 */
std::string filename;

int main(int argc, char ** argv) {
  if (argc == 1) {
    verbose = 0;
  } else if (argc == 2) {
    if (!strcmp(argv[1], "-v")) {
      verbose = 1;
    }
  } else {
    std::cout << "Usage: %s [-v]" << std::endl;
    exit(0);
  }

  std::cout << "Input the file name of the voting data: ";
  std::cin >> filename;
  
  Processor * processor = new Processor(filename);
  int res = processor->process();
  if (res == 0) {
    std::cout << "Success, files located in current directory." << std::endl;
  } else {
    std::cout << "Error occurred in process." << std::endl;
  }
  return 0;
}
