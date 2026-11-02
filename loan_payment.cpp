#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    // Variables
    double loan_amount;
    double annual_rate;
    int number_of_payments;
    
    double monthly_rate;
    double monthly_payment;
    double amount_paid_back;
    double interest_paid;

    // Input
    std::cout << "Enter the loan amount: ";
    std::cin >> loan_amount;

    std::cout << "Enter the annual interest rate (as a percentage): ";
    std::cin >> annual_rate;

    std::cout << "Enter the number of monthly payments: ";
    std::cin >> number_of_payments;

    // Convert annual percentage rate into a monthly decimal rate
    monthly_rate = annual_rate / 100.0 / 12.0;

    // Calculate monthly payment using unrounded values
    double rate_pow = std::pow(1.0 + monthly_rate, number_of_payments);
    monthly_payment = (monthly_rate * rate_pow) / (rate_pow - 1.0) * loan_amount;

    // Calculate total amount paid back and total interest paid
    amount_paid_back = monthly_payment * number_of_payments;
    interest_paid = amount_paid_back - loan_amount;

    // Display results
    std::cout << "\n----------------------------------------\n";
    std::cout << "             Loan Statement             \n";
    std::cout << "----------------------------------------\n";
    
    // Set spacing widths and float display formatting
    std::cout << std::fixed << std::left;
    
    std::cout << std::setw(28) << "Loan Amount:" << "$" << std::setprecision(2) << loan_amount << "\n";
    
    // Monthly rate is displayed as a percentage (multiplied by 100)
    std::cout << std::setw(28) << "Monthly Interest Rate:" << std::setprecision(2) << (monthly_rate * 100.0) << "%\n";
    
    std::cout << std::setw(28) << "Number of Payments:" << number_of_payments << "\n";
    std::cout << std::setw(28) << "Monthly Payment:" << "$" << std::setprecision(2) << monthly_payment << "\n";
    std::cout << std::setw(28) << "Amount Paid Back:" << "$" << std::setprecision(2) << amount_paid_back << "\n";
    std::cout << std::setw(28) << "Interest Paid:" << "$" << std::setprecision(2) << interest_paid << "\n";
    
    std::cout << "----------------------------------------\n";

   return 0;
}
