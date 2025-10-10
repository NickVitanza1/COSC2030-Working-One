#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(double bal, double rate)
    : BankAccount(bal, rate) {
    status = (balance >= 25);
}

void SavingsAccount::checkStatus() {
    status = (balance >= 25);
}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        BankAccount::deposit(amount);
        checkStatus();
    }
}

void SavingsAccount::withdraw(double amount) {
    checkStatus();
    if (status && amount > 0 && amount <= balance) {
        BankAccount::withdraw(amount);
    } else {
        std::cout << "Withdrawal denied. Account is inactive or insufficient funds.\n";
    }
    checkStatus();
}

void SavingsAccount::monthlyProc() {
    if (numWithdrawals > 4) {
        monthlyServiceCharges += (numWithdrawals - 4);
    }
    BankAccount::monthlyProc();
    checkStatus();
}