#include <iostream>
#include "BankAccount.h"

int main() {
    // Create a BankAccount object
    BankAccount myAccount("Tim Barkington", 1000.0, 5000.0);

    // Display initial balances
    std::cout << "Account holder: " << myAccount.GetName() << std::endl;
    std::cout << "Checking balance: $" << myAccount.GetChecking() << std::endl;
    std::cout << "Savings balance: $" << myAccount.GetSavings() << std::endl;

    // Perform some transactions
    myAccount.DepositChecking(300.0);
    myAccount.WithdrawSavings(150.0);
    myAccount.TransferToSavings(75.0);

    // Display updated balances
    std::cout << "Updated Checking balance: $" << myAccount.GetChecking() << std::endl;
    std::cout << "Updated Savings balance: $" << myAccount.GetSavings() << std::endl;

    return 0;
}
