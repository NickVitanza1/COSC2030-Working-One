#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(double bal, double rate)
    : BankAccount(bal, rate) {}

void CheckingAccount::withdraw(double amount) {
    if (amount > balance) {
        monthlyServiceCharges += 15.0;
        std::cout << "Insufficient funds. $15 overdraft fee applied.\n";
    } else {
        BankAccount::withdraw(amount);
    }
}

void CheckingAccount::monthlyProc() {
    monthlyServiceCharges += 5.0 + (0.10 * numWithdrawals);
    BankAccount::monthlyProc();
}