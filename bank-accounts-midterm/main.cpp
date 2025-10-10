//
// Nicholas Vitanza
// 10/8/25
// Bank Accounts Midterm Programming Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
#include "SavingsAccount.h"
#include "CheckingAccount.h"

void processAccount(BankAccount &account, const std::string& accountType) {
    double depositAmt, withdrawAmt;
    int numDeposits, numWithdrawals;

    std::cout << "\n--- " << accountType << " ---\n";

    std::cout << "How many deposits for " << accountType << "? ";
    std::cin >> numDeposits;
    for (int i = 0; i < numDeposits; ++i) {
        std::cout << "Deposit amount #" << (i + 1) << ": ";
        std::cin >> depositAmt;
        account.deposit(depositAmt);
    }

    std::cout << "How many withdrawals for " << accountType << "? ";
    std::cin >> numWithdrawals;
    for (int i = 0; i < numWithdrawals; ++i) {
        std::cout << "Withdrawal amount #" << (i + 1) << ": ";
        std::cin >> withdrawAmt;
        account.withdraw(withdrawAmt);
    }

    account.monthlyProc();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Ending balance: $" << account.getBalance() << '\n';
    std::cout << "Total deposits: " << account.getNumDeposits() << '\n';
    std::cout << "Total withdrawals: " << account.getNumWithdrawals() << '\n';
    std::cout << "Monthly service charges: $" << account.getMonthlyServiceCharges() << '\n';
}

int main() {
    double savBal, chkBal, interestRate;

    std::cout << "Enter savings account initial balance: $";
    std::cin >> savBal;
    std::cout << "Enter checking account initial balance: $";
    std::cin >> chkBal;
    std::cout << "Enter annual interest rate (e.g., 0.05 for 5%): ";
    std::cin >> interestRate;

    SavingsAccount savings(savBal, interestRate);
    CheckingAccount checking(chkBal, interestRate);

    processAccount(savings, "Savings Account");
    processAccount(checking, "Checking Account");

    return 0;
}