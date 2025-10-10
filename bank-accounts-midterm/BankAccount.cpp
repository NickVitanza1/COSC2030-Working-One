#include "BankAccount.h"

BankAccount::BankAccount(double bal, double annualRate)
    : balance(bal), annualInterestRate(annualRate),
      numDeposits(0), numWithdrawals(0), monthlyServiceCharges(0.0) {}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        numDeposits++;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        numWithdrawals++;
    }
}

void BankAccount::calcInt() {
    double monthlyInterestRate = annualInterestRate / 12;
    double interest = balance * monthlyInterestRate;
    balance += interest;
}

void BankAccount::monthlyProc() {
    balance -= monthlyServiceCharges;
    calcInt();
    numDeposits = 0;
    numWithdrawals = 0;
    monthlyServiceCharges = 0.0;
}

double BankAccount::getBalance() const {
    return balance;
}

int BankAccount::getNumDeposits() const {
    return numDeposits;
}

int BankAccount::getNumWithdrawals() const {
    return numWithdrawals;
}

double BankAccount::getMonthlyServiceCharges() const {
    return monthlyServiceCharges;
}