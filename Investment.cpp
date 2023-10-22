/*
*     Program Name: AirGeadBankingInvestmentApp
*     Author: Braydon Woodward'
*     Date: 10/1/2022
*     File: Class
*     Description: This program was designed to allow users to see how their investments will grow over time. The user
*                  will enter an initial investment amount, a monthly deposit amount, an annual interest rate, and a 
*                  length in years. The prgram will return a yearly break down of end of year account balance and interest
*                  earned. The program will run until the user enters 'q'.
*/

#include "Investment.h"
#include <iostream>
#include <iomanip>

Investment::Investment() { // Initialize Investment object, set everything to -1 for troubleshooting clarity
    m_initialInvestmentAmount = -1;
    m_monthlyDeposit = -1;
    m_annualInterestRate = -1;
    m_numberOfYears = -1;
}
void Investment::printDataHeader() { // Displays data entry header
    std::cout << "******** DATA INPUT ********" << std::endl;
    std::cout << "Initial Investment Amount:" << std::endl;
    std::cout << "Monthly Deposit:" << std::endl;
    std::cout << "Annual Interest:" << std::endl;
    std::cout << "Number of Years:" << std::endl;
    std::cout << std::endl; // New line for readability
}

void Investment::readDataInput() { // Gets data input from the user
    std::cout << "******** DATA INPUT ********" << std::endl;

    do {
        // Ensure the initial investment amount is non-negative
        std::cout << "Initial Investment Amount: ";
        std::cin >> m_initialInvestmentAmount;
        if (m_initialInvestmentAmount < 0) {
            std::cout << "Error: Please enter a non-negative value for Initial Investment Amount." << std::endl;
        }
    } while (m_initialInvestmentAmount < 0);

    do {
        // Ensure the monthly deposit is non-negative
        std::cout << "Monthly Deposit: ";
        std::cin >> m_monthlyDeposit;
        if (m_monthlyDeposit < 0) {
            std::cout << "Error: Please enter a non-negative value for Monthly Deposit." << std::endl;
        }
    } while (m_monthlyDeposit < 0);

    do {
        // Ensure the annual interest rate is non-negative
        std::cout << "Annual Interest: ";
        std::cin >> m_annualInterestRate;
        if (m_annualInterestRate < 0) {
            std::cout << "Error: Please enter a non-negative value for Annual Interest." << std::endl;
        }
    } while (m_annualInterestRate < 0);

    do {
        // Ensure the number of years is non-negative
        std::cout << "Number of Years: ";
        std::cin >> m_numberOfYears;
        if (m_numberOfYears < 0) {
            std::cout << "Error: Please enter a non-negative value for Number of Years." << std::endl;
        }
    } while (m_numberOfYears < 0);

    std::cout << std::endl; // New line for readability
}

// Calculates investment details with or without monthly deposits depending on boolean value passed through
void Investment::calculateInvestmentDetails(bool withMonthlyDeposits) { 
    double usedmonthlyDeposit;
    if (withMonthlyDeposits) {
        std::cout << "Balance and Interest With Monthly Deposits" << std::endl;
        usedmonthlyDeposit = m_monthlyDeposit;
    }
    else {
        std::cout << "Balance and Interest With-Out Monthly Deposits" << std::endl;
        usedmonthlyDeposit = 0;
    }
    // Header for data display
    std::cout << "----------------------------------------------------------------" << std::endl;
    std::cout << "YEAR          YEAR END BALANCE        YEAR END EARNED INTEREST" << std::endl;
    std::cout << "----------------------------------------------------------------" << std::endl;

    // These declared variables are used only in this function
    double total = m_initialInvestmentAmount; // Tracks total account balance
    double m_earnedInterest = 0.00;// Tracks yearly earned interest
    double monthlyInterest = 0.00;// Tracks monthly earned interest

    for (int year = 1; year <= m_numberOfYears; ++year) { // Loop through each year
        m_earnedInterest = 0; // Reset yearly earned interest
        for (int month = 1; month <= 12; ++month) { // loop through each month
            // Calculate monthly interest
            monthlyInterest = (total + usedmonthlyDeposit) * (m_annualInterestRate / 100.0) / 12.0;


            // Add the monthly deposit to total
            total = total + usedmonthlyDeposit;

            // Add the calculated monthly interest to total
            total = total + monthlyInterest;

            // Accumulate the earned interest for the year
            m_earnedInterest = m_earnedInterest + monthlyInterest;
        }

        // Print the total balance and earned interest at the end of each year formatted to fit the above header
        std::cout << " " << std::setw(17) << std::left << year << std::setw(25) << std::fixed << std::setprecision(2) << total
            << std::setw(25) << std::fixed << std::setprecision(2) << m_earnedInterest << std::endl;
    }
    std::cout << std::endl; // New line for readability
}

// For further program development, setters and getters need to be added
