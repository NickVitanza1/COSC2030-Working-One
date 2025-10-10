#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "BankAccount.h"

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(double bal, double rate);

    void withdraw(double amount) override;
    void monthlyProc() override;
};

#endif