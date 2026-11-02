# cis165-Lab5
# 1 - Plan For: compound_interest.cpp

## Overview & Purpose
This program calculates the final balance and total interest earned on a savings account using the compound interest formula. 
The user will enter the principal, annual interest percentage, and compounding frequency.
The program calculates the results, and displays an aligned report.

## Required Variables Input
principal (double): The initial amount of money.
input_rate (double): The annual interest rate entered as a percentage.
times_compounded (int): The number of times interest is compounded per year.

### Percentage Conversions & Intermediate Variables
The user enters the rate as a whole or fractional percentage. 
This will be converted to a decimal before calculating by dividing /100.
Formula: decimal_rate (Double) = input_rate / 100.0
amount (double): The total final balance in savings after compounding.
interest_earned (double): The dollar amount of interest accumulated.

### Formulas
**Total Balance (Savings):**
amount = principal * pow(1.0 + decimal_rate / times_compounded, times_compounded);
**Interest Earned:**
interest_earned = amount - principal

### Required Output
Floating-point values fixed to 2 decimal places.
Aligned labels using `std::setw` for clean horizontal presentation.
Display:
Interest Rate (%)
Times Compounded
Principal Balance ($)
Interest Earned ($)
Total Amount in Savings ($)

---

## 2 - Suggest two useful test cases for this loan-payment formula and explain what each test checks.

### Test Case 1: Simple Annual Compounding
**Input:**
Principal: $1,000.00
Interest Rate: 5.0%
Times Compounded: 1
**Expected Results:**
decimal_rate = 5.0 / 100 = 0.05
amount = $1000 \times (1 + 0.05 / 1)^1 = 1000 \times 1.05 = $1,050.00
interest_earned = $1,050.00 - $1,000.00 = $50.00
**What this checks:** Verifies percentage conversion and exponent work perfectly when there is no fractional compounding.

### Test Case 2: Standard Monthly Compounding
**Input:**
Principal: $4,300.00
Interest Rate: 3.5%
Times Compounded: 12 
**Expected Mathematical Derivation:**
decimal_rate = 3.5 / 100 = 0.035
Base term = $1.0 + (0.035 / 12) = approx $1.002916667
Exponent calculation = $(1.002916667)^{12} = approx $1.035568
amount = $4300 \times 1.035568 = $4,452.94
interest_earned = $4,452.94 - $4,300.00 = $152.94
**What this checks:** Confirms the accuracy of the `pow()` function, and currency rounding by using setprecision(2).

## 3 - TEST Program

### Input Values:
Principal: $1,000.00
Annual interest rate: 4.25%
Times compounded: 12
### The results should are:
Interest Earned: $43.34
Amount in Savings: $1,043.34

The results are as expected.

## Second Test
### Input Values:
Principal: $1,624.00
Annual interest rate: 3.75%
Times compounded: 12
### The results should are:
Interest Earned: $61.96
Amount in Savings: $1,685.96

Results are as expected.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 1 - Plan for loan_payment.cpp

# Overview
This program will calculate the Loan Monthly Payments.

### Input:
loan_amount: Total principal borrowed ($) (double)
annual_rate: Annual interest rate as a raw percentage (e.g., 12.0 for 12%) (double)
number_of_payments: Total number of monthly repayment periods (int)

### Percentage Conversions
Convert annual rate to a monthly decimal rate by dividing by 100 and dividing by the 12 calendar months:
monthly_rate = annual_rate / 100.0 / 12.0

### Intermediate Variables
monthly_rate: The calculated monthly interest (double)
rate_pow: The pre-calculated exponential factor (double):
rate_pow = std::pow(1.0 + monthly_rate, number_of_payments)

### Formulas
**Monthly Payment Calculation:**
monthly_payment = (monthly_rate * rate_pow) / (rate_pow - 1.0) * loan_amount
double rate_pow = std::pow(1.0 + monthly_rate, number_of_payments);
monthly_payment = (monthly_rate * rate_pow) / (rate_pow - 1.0) * loan_amount;
   
**Total Amortization:**
amount_paid_back = monthly_payment * number_of_payments;
    
**Interest Paid:**
interest_paid = amount_paid_back - loan_amount;

### Output
A table formatted to two decimal points showing:
Loan Amount ($)
Monthly Interest Rate (%)
Number of Payments
Monthly Payment ($)
Amount Paid Back ($)
Net Interest Paid ($)

### 2 - TEST PROGRAM
**Test 1: Long Term Loan**
Inputs: Loan Amount = $10000.00, Annual Rate = 12.0%, Total Payments = 36
Expected interest: monthly_rate = 0.01 (1% per month)
Expected Outputs: Monthly Payment = $332.14, Total Paid Back = $11957.15, Interest Paid = $1957.15
The program run as expected, returning the right values.

**Test 2: Short-Term Loan**
Inputs: Loan Amount = $1200.00, Annual Rate = 6.0%, Total Payments = 12
Expected Mid-point Precision: monthly_rate = 0.005 (0.5% per month)
Expected Outputs: Monthly Payment = $103.28, Total Paid Back = $1239.36, Interest Paid = $39.36
The program run as expected, returning the right values.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

## EXPLAINING the Code

### 1. Why must a percentage be divided by 100 before using it in a formula?
A percentage is way to express a fraction out of 100. 
For instance, if you multiply a principal of \$1,000 directly by a raw input rate of 5, the math thinks the money scales by a factor of 5 (growing to $5,000). Dividing input_rate / 100.0 turns it into 0.05, allowing the formula to correctly compute a 5% addition.

### 2. How does pow represent exponentiation?
The C++ library has not an exponent operator like ^ 
To raise a base value to a power, we must use `std::pow(base, exponent)` from the `<cmath>` library. 
In the program, it evaluates everything inside the parentheses first as the base, and then multiplies that base by itself times_compounded times.

### 3. What does the number of compounding periods change in the savings formula?
The number of compounding periods (times_compounded) change how frequently interest is calculated and added back into the account balance. 
A higher compounding frequency returns a slightly larger final balance because you earn "interest on top of interest" more often.

### 4. How is an annual interest rate converted to a monthly rate?
An annual interest percentage is converted to a monthly decimal rate by dividing the percentage by 100 to make it a decimal, and then dividing that result by 12. 

### 5. Why should double be used for these calculations?
This is a financial application so, we must track precise fractional amounts (dollars and cents). 
If we used an `int` (integer) data type, the program will discard all decimal points via integer division, reducing interest values like `0.035` down to `0`. 
The double data type provides double-precision floating-point numbers that can precisely handle fractional values.

### 6. Why should calculations use full precision when money is displayed to two decimal places?
Rounding numbers early causes "round-off error" that we will translate to final results. 
To preserve integrity of the values, calculations must maintain full precision at every intermediate step. 
Using `std::setprecision(2)` should only happen at the very end when displaying the value to the user.

### 7. How are the amount paid back and total interest calculated?
**Total Amount:** Computed using the compound interest formula, which scales the initial principal by the periodic interest factor raised to the compounding power.
**Total Interest Earned:** Calculated by subtracting the initial investment from the final accumulated balance. 

### 8. Why are calculations stored in variables before being displayed?
Separating the calculation logic from the output layout is an good programming practice. 
Storing values in intermediate variables like `amount` and `interest_earned` makes the code easi to read, trace, and debug. 
It also allows to reuse those computed numbers later in other equations if needed. 

