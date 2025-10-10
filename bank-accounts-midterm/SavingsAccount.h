#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
    bool status; // true = active, false = inactive
    void checkStatus();

public:
    SavingsAccount(double bal, double rate);

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void monthlyProc() override;
};

#endif