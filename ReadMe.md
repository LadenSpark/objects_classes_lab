# BankAccount Class

A C++ class for representing a bank account in a banking management system.

## Data Dictionary

| Attribute           | Data Type     | Description                         |
|---------------------|---------------|-------------------------------------|
| `accountNumber`     | `std::string` | Unique identifier for the account.  |
| `accountHolderName` | `std::string` | Full name of the account holder.    |
| `accountBalance`    | `double`      | Current balance of the account.     |

## Methods List

| Method Signature                                                 | Return Type   | Description                     |
|------------------------------------------------------------------|---------------|---------------------------------|
| `BankAccount()`                                                  | (Constructor) | Default constructor.            |
| `BankAccount(accountNumber, accountHolderName, startingBalance)` | (Constructor) | Parameterized constructor.      |
| `getAccountNumber() const`                                       | `std::string` | Gets the account number.        |
| `getAccountHolderName() const`                                   | `std::string` | Gets the account holder's name. |
| `getAccountBalance() const`                                      | `double`      | Gets the account balance.       |
| `setAccountHolderName(name)`                                     | `void`        | Sets the account holder's name. |
| `deposit(amount)`						   | `bool`	   | Deposits funds to account.      |
| `withdraw(amount)`						   | `bool`	   | Withdraws finds from account.   |