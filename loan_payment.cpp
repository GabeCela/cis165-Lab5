#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // Variable declarations 
    double principal = 0.0;
    double input_rate = 0.0;
    int times_compounded = 0;

    // User input
    std::cout << "Enter the principal balance: $";
    std::cin >> principal;

    std::cout << "Enter the annual interest rate (as a %): ";
    std::cin >> input_rate;

    std::cout << "Enter the number of times interest is compounded per year: ";
    std::cin >> times_compounded;

    // Conversions and calculations
    double decimal_rate = input_rate / 100.0;
    
    // Formula: amount = principal * (1 + rate / times_compounded) ^ times_compounded
    double amount = principal * std::pow(1.0 + decimal_rate / times_compounded, times_compounded);
    double interest_earned = amount - principal;

    // Display the report
    std::cout << "\n-----------------------------------------\n";
    std::cout << "          INTEREST SAVINGS REPORT        \n";
    std::cout << "-----------------------------------------\n";
    
    // Setup fixed-point notation with two decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Using setw(25) for left column alignment and setw(12) for numeric values
    std::cout << std::left << std::setw(25) << "Interest Rate:" 
              << std::right << std::setw(11) << input_rate << "%\n";
              
    std::cout << std::left << std::setw(25) << "Times Compounded:" 
              << std::right << std::setw(12) << times_compounded << "\n";
              
    std::cout << std::left << std::setw(25) << "Principal Balance:" 
              << "$ " << std::right << std::setw(10) << principal << "\n";
              
    std::cout << std::left << std::setw(25) << "Interest Earned:" 
              << "$ " << std::right << std::setw(10) << interest_earned << "\n";
              
    std::cout << std::left << std::setw(25) << "Total Amount in Savings:" 
              << "$ " << std::right << std::setw(10) << amount << "\n";
              
    std::cout << "-----------------------------------------\n";

    return 0;
}
