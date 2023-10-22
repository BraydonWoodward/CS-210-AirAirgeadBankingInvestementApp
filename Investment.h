/*
*     Program Name: AirGeadBankingInvestmentApp
*     Author: Braydon Woodward'
*     Date: 10/1/2022
*     File: Header
*     Description: This program was designed to allow users to see how their investments will grow over time. The user
*                  will enter an initial investment amount, a monthly deposit amount, an annual interest rate, and a
*                  length in years. The prgram will return a yearly break down of end of year account balance and interest
*                  earned. The program will run until the user enters 'q'.
*/

// Gaurd formatted as instructed
#ifndef AIRGEADBANKINGINVESTEMENTAPP_BRAYDONWOODWARD_H_
#define AIRGEADBANKINGINVESTEMENTAPP_BRAYDONWOODWARD_H_

class Investment {
private:
    double m_initialInvestmentAmount;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;
    bool withMonthlyDeposits; // This boolean controls if there is a monthly deposit or not

public:
    Investment(); // Constructor

    void printDataHeader(); // Displays data entry header
    void readDataInput(); // Gets data input from the user

    // Calculates investment details with or without monthly deposits depending on boolean value passed through
    void calculateInvestmentDetails(bool withMonthlyDeposits);

    // For further program development, setters and getters need to be added
};

#endif  AIRGEADBANKINGINVESTEMENTAPP_BRAYDONWOODWARD_H_

