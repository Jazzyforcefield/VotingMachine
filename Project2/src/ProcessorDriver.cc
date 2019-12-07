// Copyright 2019, CSCI 5801, Team 25

#include "processor.h"

int main() {
  system("java VotingCsvFile");
  std::string file_name;
  std::cout << "Enter file name: ";
  std::cin >> file_name;

  Processor * processor = new Processor(file_name);  
  processor->process();
}
