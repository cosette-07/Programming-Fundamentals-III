#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string> 

class BankAccount {
private:
    std::string customerName; // Stores the name of the customer
    double checkingBalance;   // Stores checking account balance
    double savingsBalance;    // Stores savings account balance

public:
    // Constructor to initialize the customer name and account balances
    BankAccount(std::string newName, double chBalance, double sBalance);

    // Setter and Getter for customer name
    void SetName(std::string newName);
    std::string GetName();

    // Setter and Getter for checking account
    void SetChecking(double balance);
    double GetChecking();

    // Setter and Getter for savings account
    void SetSavings(double balance);
    double GetSavings();

    // Deposit and withdrawal functions
    void DepositChecking(double amt);
    void DepositSavings(double amt);
    void WithdrawChecking(double amt);
    void WithdrawSavings(double amt);

    // Function to transfer money from checking to savings
    void TransferToSavings(double amt);
};

#endif 
