// Copyright 2019, CSCI 5801, Team 25

#include "processor.h"

int main() {
  system("java VotingCsvFile");
  std::string file_name;
  std::ifstream path("path.txt", std::ifstream::in);
  path >> file_name;
  path.close();

  Processor * processor = new Processor(file_name);  
  processor->process();
}
