/*
*     Program Name: AirGeadBankingInvestmentApp
*     Author: Braydon Woodward'
*     Date: 10/1/2022
*     File: Main
*     Description: This program was designed to allow users to see how their investments will grow over time. The user
*                  will enter an initial investment amount, a monthly deposit amount, an annual interest rate, and a
*                  length in years. The prgram will return a yearly break down of end of year account balance and interest
*                  earned. The program will run until the user enters 'q'.
*/

#include <iostream>
#include <memory> // Include for std::m_unique
#include "Investment.h"

int main() {
    bool isProgramRunning = true; //Boolean value that drives the program
    char userChoice;

    std::cout << "Welcome to the AirGead Banking Investment App" << std::endl; // Opening line diplayed to user
    std::cout << std::endl; // Endline for readabiity

    do {
        std::cout << "Press any key to continue, or 'q' to quit: ";
        std::cin >> userChoice;
        std::cout << std::endl; // New line for readability

        if (userChoice == 'q') { // Entering q ends the program
            std::cout << "Goodbye!" << std::endl;
            isProgramRunning = false;
        }
        else {
            try {
                auto investment = std::make_unique<Investment>(); // Declare new Investment Object following standards guidline
                investment->printDataHeader(); // Prints data header
                investment->readDataInput(); // Gets input from the user
                investment->calculateInvestmentDetails(false); //Calculates and displays info to the user without monthy deposits
                investment->calculateInvestmentDetails(true); //Calculates and displays info to the user with monthy deposits

                std::cout << std::endl; // New line for readability
            }
            catch (const std::exception& e) { // Catch errors and display error messages
                std::cout << "Error: " << e.what() << std::endl; 
            }
        }
    } while (isProgramRunning);

    return 0;
}