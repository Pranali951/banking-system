// Simple Banking System Project in C++ (Object-Oriented)
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Customer class definition
class Customer {
private:
    string name;

public:
    Customer(string name) : name(name) {}

    string getName() const { return name; }
};

// Account class definition
class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accountNumber, double initialBalance) : accountNumber(accountNumber), balance(initialBalance) {}

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void deposit(double amount) { balance += amount; }
    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << fixed << setprecision(2) << "Balance: $" << balance << endl;
    }
};

// Main function
int main() {
    vector<Customer> customers;
    vector<Account> accounts;

    // Simple customer and account creation
    customers.push_back(Customer("John Doe"));
    accounts.push_back(Account(1001, 500.0));

    // Basic menu system
    int choice;
    do {
        cout << "\nBanking System Menu:\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Account Info\n4. Exit\nChoose an option: ";
        cin >> choice;

        if (choice == 1) {
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            accounts[0].deposit(amount);
        } else if (choice == 2) {
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            if (!accounts[0].withdraw(amount))
                cout << "Insufficient balance!\n";
        } else if (choice == 3) {
            accounts[0].displayAccountInfo();
        }

    } while (choice != 4);

    return 0;
}
