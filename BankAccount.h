/* ------------------------------------------
Author: Jason Suits
Date: 9/27/2026
------------------------------------------ */

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>

class BankAccount {
public:
    BankAccount();
    BankAccount(const std::string& _accountNumber, const std::string& _accountHolderName, double _startingBalance);
    bool deposit(double amount);
    bool withdraw(double amount);
    void setAccountHolderName(const std::string& name);
    double getAccountBalance() const;
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;

private:
    std::string accountNumber;
    std::string accountHolderName;
    double accountBalance;
};

#endif // BANKACCOUNT_H
