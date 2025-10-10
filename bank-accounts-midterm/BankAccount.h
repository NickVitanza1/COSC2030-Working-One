#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount {
protected:
    double balance;
    int numDeposits;
    int numWithdrawals;
    double annualInterestRate;
    double monthlyServiceCharges;

public:
    BankAccount(double bal = 0.0, double annualRate = 0.0);

    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void calcInt();
    virtual void monthlyProc();

    // Getters
    double getBalance() const;
    int getNumDeposits() const;
    int getNumWithdrawals() const;
    double getMonthlyServiceCharges() const;
};

#endif