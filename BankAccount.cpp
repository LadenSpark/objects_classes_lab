/* ------------------------------------------
author: Jason Suits
date: 9/27/2026
------------------------------------------ */

#include "BankAccount.h"

BankAccount::BankAccount() {
    accountNumber = "";
    accountHolderName = "";
    accountBalance = 0.0;
}

BankAccount::BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance) {
    accountBalance = (_startingBalance >= 0.0) ? _startingBalance : 0.0;
    accountNumber = _accountNumber;
    accountHolderName = _accountHolderName;
}

bool BankAccount::deposit(double amount) {
    if (amount> 0)
    {
        accountBalance += amount;
        return true;
    }
    else
    {
        return false;
    }
}

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= accountBalance) {
        accountBalance -= amount;
        return true;
    }
    else
    {
        return false;
    }
}

void BankAccount::setAccountHolderName(const std::string& name) {
    accountHolderName = name;
}

std::string BankAccount::getAccountHolderName() const {
    return accountHolderName;
}

double BankAccount::getAccountBalance() const {
    return accountBalance;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}





