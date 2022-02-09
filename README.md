# OPL and CPL Voting System

## Introduction
The Voting System is designed to analyze the votes of two types of elections: Open Pary List and Closed Party List. The Open Party List method, which will be referred to as OPL, allows for people to vote for a certain candidate. The seat winners are determined by popular vote.
Closed Party List (CPL) voting allows a person to vote for a party, rather than a specific candidate. Within each party, the candidates have a predetermined ranking that determines who gets seats if they are won. The goal of the Voting System is to quickly and accurately determine the winners of an election given an input file that contains the data it requires.

## Design
The Processor class handles all the parsing. Polymorphism is used by having an abstract VotingType class to derive OPL and CPL objects from it. Then the different ways to process can be called easily and done in different ways. This project makes use of both C++ and Java due to the Java interface being readily available.

## How to Install
This program requires the use of both Java and C++, meaning that you must have both the Java Standard Edition JDK 8 and the GNU compiler running g++ version 7.4.0. Running on a CSELabs machine should be sufficient since it has all the dependencies.

## How to Run
In order to run the program, you must open a Terminal (Ctrl + Alt + T) and change directories to the VotingMachine folder. Depending on where you downloaded the repository, it will likely be in your Downloads folder. The Downloads folder is located in the home directory, and the repository should be accessible by using the following command:

`cd ~/Downloads/VotingMachine`

We then want to change directories to the Project2's "src" folder using the following command:

`cd src`

Once we are there, do the following to run the program:

`make`
`./voting_system`

After the build process is done, it will prompt you to locate an input file for calculating results. Then you click the button to start the algorithm and it will close the window while it processes.

The program will produce an audit file name audit.txt which can be saved to a different location depending on the user's intention.

The "result.txt" file will have a short summary of the results of the election. There will also be a display where you can see the results on the screen, click the button of "Results" to display it. Press "Audit" to view and have the option to save it. Feel free to share this file with media.
