#include "BankAccount.h" 
#include <iostream>      

// Constructor definition
BankAccount::BankAccount(std::string newName, double chBalance, double sBalance) {
    customerName = newName;
    checkingBalance = chBalance;
    savingsBalance = sBalance;
}

// Set customer name
void BankAccount::SetName(std::string newName) {
    customerName = newName;
}

// Get customer name
std::string BankAccount::GetName() {
    return customerName;
}

// Set checking account balance
void BankAccount::SetChecking(double balance) {
    checkingBalance = balance;
}

// Get checking account balance
double BankAccount::GetChecking() {
    return checkingBalance;
}

// Set savings account balance
void BankAccount::SetSavings(double balance) {
    savingsBalance = balance;
}

// Get savings account balance
double BankAccount::GetSavings() {
    return savingsBalance;
}

// Deposit money into checking account
void BankAccount::DepositChecking(double amt) {
    if (amt > 0) {
        checkingBalance += amt;
    }
    else {
        std::cout << "Deposit amount must be positive.\n";
    }
}

// Deposit money into savings account
void BankAccount::DepositSavings(double amt) {
    if (amt > 0) {
        savingsBalance += amt;
    }
    else {
        std::cout << "Deposit amount must be positive.\n";
    }
}

// Withdraw money from checking account
void BankAccount::WithdrawChecking(double amt) {
    if (amt > 0 && amt <= checkingBalance) {
        checkingBalance -= amt;
    }
    else {
        std::cout << "Invalid withdrawal amount.\n";
    }
}

// Withdraw money from savings account
void BankAccount::WithdrawSavings(double amt) {
    if (amt > 0 && amt <= savingsBalance) {
        savingsBalance -= amt;
    }
    else {
        std::cout << "Invalid withdrawal amount.\n";
    }
}

// Transfer money from checking to savings
void BankAccount::TransferToSavings(double amt) {
    if (amt > 0 && amt <= checkingBalance) {
        checkingBalance -= amt;
        savingsBalance += amt;
    }
    else {
        std::cout << "Invalid transfer amount.\n";
    }
}
