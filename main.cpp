/*
 * Name: Jason Suits
 * Date: September 27, 2026
 * Assignment: Objects & Classes Lab - Bank Account Management System
 * Purpose: Driver program managing a collection of BankAccount objects using std::vector.
 */
#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "BankAccount.h"

int findAccount(const std::vector<BankAccount>& accounts, const std::string& accountNumber) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return static_cast<int>(i);
        }
    }
    return -1; // Account not found
}

int main() {
    // Your code here
    int userSelection;
    std::vector<BankAccount> accounts;
    std::string accountNumber, accountHolderName;
    double transactionAmount;

    do {
        std::cout << "\nBank Account Management System\n";
        std::cout << "1. Create a new account\n";
        std::cout << "2. Deposit funds\n";
        std::cout << "3. Withdraw funds\n";
        std::cout << "4. Display account balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> userSelection;

        switch (userSelection) {
            case 1: {
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter account holder name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                std::getline(std::cin, accountHolderName);
                double startingBalance;
                std::cout << "Enter starting balance: ";
                std::cin >> startingBalance;

                BankAccount newAccount(accountNumber, accountHolderName, startingBalance);
                accounts.push_back(newAccount);
                std::cout << "Account created successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Enter account number for deposit: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to deposit: ";
                    std::cin >> transactionAmount;
                    if (accounts[index].deposit(transactionAmount)) {
                        std::cout << "Deposit successful. New balance: $" << accounts[index].getAccountBalance() << "\n";
                    } else {
                        std::cout << "*** Deposit failed ***\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 3: {
                std::cout << "Enter account number for withdrawal: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Enter amount to withdraw: ";
                    std::cin >> transactionAmount;
                    if (accounts[index].withdraw(transactionAmount)) {
                        std::cout << "Withdrawal successful. New balance: $" << accounts[index].getAccountBalance() << "\n";
                    } else {
                        std::cout << "Withdrawal failed... Check amount and balance.\n";
                    }
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Enter account number to display balance: ";
                std::cin >> accountNumber;
                int index = findAccount(accounts, accountNumber);
                if (index != -1) {
                    std::cout << "Account Holder: " << accounts[index].getAccountHolderName() << "\n";
                    std::cout << "Account Balance: $" << accounts[index].getAccountBalance() << "\n";
                } else {
                    std::cout << "Account not found.\n";
                }
                break;
            }
            case 5:
                std::cout << "Exiting the program.\n";
                break;
        }
    } while (userSelection != 5);

    return 0;
}