// Copyright 2019, Team 25, CSCI 5801

#include <iostream>
#include <string>

#include "src/processor.h"

int verbose;
string filename;

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
