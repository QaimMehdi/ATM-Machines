#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>

class Account {
public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

    void transfer(Account& recipient, double amount) {
        if (amount <= balance) {
            withdraw(amount);
            recipient.deposit(amount);
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

private:
    int accountNumber;
    double balance;
};

class ATM {
public:
    void createAccount() {
        int accountNumber = generateAccountNumber();
        double initialBalance;
        std::cout << "\nEnter initial balance: $";
        std::cin >> initialBalance;

        accounts.push_back(Account(accountNumber, initialBalance));

        std::cout << "\nAccount created successfully. Account number: " << accountNumber << std::endl;
    }

    void showBalance(int accountNumber) {
        for (const auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                std::cout << "\nAccount Balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
                return;
            }
        }
        std::cout << "Account not found!" << std::endl;
    }

    void deposit(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                std::cout << "\nDeposit successful. New balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
                return;
            }
        }
        std::cout << "Account not found!" << std::endl;
    }

    void withdraw(int accountNumber, double amount) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                std::cout << "\nWithdrawal successful. New balance: $" << std::fixed << std::setprecision(2) << account.getBalance() << std::endl;
                return;
            }
        }
        std::cout << "Account not found!" << std::endl;
    }

    void transfer(int senderAccountNumber, int recipientAccountNumber, double amount) {
        Account* senderAccount = findAccount(senderAccountNumber);
        Account* recipientAccount = findAccount(recipientAccountNumber);

        if (senderAccount && recipientAccount) {
            senderAccount->transfer(*recipientAccount, amount);
            std::cout << "\nTransfer successful. New balance for sender: $" << std::fixed << std::setprecision(2) << senderAccount->getBalance()
                      << ", New balance for recipient: $" << std::fixed << std::setprecision(2) << recipientAccount->getBalance() << std::endl;
        } else {
            std::cout << "One or both accounts not found!" << std::endl;
        }
    }

private:
    std::vector<Account> accounts;

    int generateAccountNumber() {
        // Generate a random account number for simplicity
        return rand() % 10000 + 1000;
    }

    Account* findAccount(int accountNumber) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                return &account;
            }
        }
        std::cout << "Account not found!" << std::endl;
        return nullptr;
    }
};

int main() {
    ATM atm;

    int choice;
    do {
        std::cout << "\n==========================\n       ATM Menu\n==========================\n";
        std::cout << "1. Create Account\n2. Show Balance\n3. Deposit\n4. Withdraw\n5. Transfer\n0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                atm.createAccount();
                break;
            case 2: {
                int accountNumber;
                std::cout << "\nEnter account number: ";
                std::cin >> accountNumber;
                atm.showBalance(accountNumber);
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "\nEnter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter deposit amount: $";
                std::cin >> amount;
                atm.deposit(accountNumber, amount);
                break;
            }
            case 4: {
                int accountNumber;
                double amount;
                std::cout << "\nEnter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter withdrawal amount: $";
                std::cin >> amount;
                atm.withdraw(accountNumber, amount);
                break;
            }
            case 5: {
                int senderAccountNumber, recipientAccountNumber;
                double amount;
                std::cout << "\nEnter sender account number: ";
                std::cin >> senderAccountNumber;
                std::cout << "Enter recipient account number: ";
                std::cin >> recipientAccountNumber;
                std::cout << "Enter transfer amount: $";
                std::cin >> amount;
                atm.transfer(senderAccountNumber, recipientAccountNumber, amount);
                break;
            }
            case 0:
                std::cout << "\nExiting ATM. Goodbye!\n";
                break;
            default:
                std::cout << "\nInvalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
