#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    int transactionID;
    string type;
    double amount;
    string date;

    Transaction(int id, string t, double amt, string d) : transactionID(id), type(t), amount(amt), date(d) {}

    void showTransaction() const { // Marked as const
        cout << "Transaction ID: " << transactionID << ", Type: " << type << ", Amount: $" << amount << ", Date: " << date << endl;
    }
};

class Account {
private:
    int accountNumber;
    int customerID;
    double balance;
    string accountType;
    vector<Transaction> transactions;

public:
    Account(int accNum, int custID, string accType, double initialBalance) {
        accountNumber = accNum;
        customerID = custID;
        accountType = accType;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        transactions.emplace_back(transactions.size() + 1, "Deposit", amount, "2024-08-28");
        cout << "Deposited: $" << amount << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactions.emplace_back(transactions.size() + 1, "Withdrawal", amount, "2024-08-28");
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient funds." << endl;
        }
    }

    void transfer(Account &toAccount, double amount) {
        if (balance >= amount) {
            balance -= amount;
            toAccount.deposit(amount);
            transactions.emplace_back(transactions.size() + 1, "Transfer", amount, "2024-08-28");
            cout << "Transferred: $" << amount << " to Account " << toAccount.accountNumber << endl;
        } else {
            cout << "Insufficient funds for transfer." << endl;
        }
    }

    void getBalance() const { // Marked as const
        cout << "Current Balance: $" << balance << endl;
    }

    void showTransactions() const { // Marked as const
        cout << "Recent Transactions for Account " << accountNumber << ":" << endl;
        for (const auto &t : transactions) {
            t.showTransaction();
        }
    }

    int getAccountNumber() const { // Getter method for accountNumber
        return accountNumber;
    }
};

class Customer {
private:
    int customerID;
    string name;
    vector<Account> accounts;

public:
    Customer(int id, string n) : customerID(id), name(n) {}

    void createAccount(int accNum, string accType, double initialBalance) {
        accounts.emplace_back(accNum, customerID, accType, initialBalance);
        cout << "Account " << accNum << " created for Customer " << customerID << endl;
    }

    Account* getAccount(int accNum) {
        for (auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    const Account* getAccount(int accNum) const { // Marked as const
        for (const auto &account : accounts) {
            if (account.getAccountNumber() == accNum) {
                return &account;
            }
        }
        return nullptr;
    }

    void showCustomerInfo() const { // Marked as const
        cout << "Customer ID: " << customerID << ", Name: " << name << endl;
        cout << "Accounts: " << endl;
        for (const auto &account : accounts) {
            account.getBalance();
        }
    }
};

class BankingService {
public:
    void executeService(Customer &customer, Account &account, string serviceType, double amount) {
        if (serviceType == "Deposit") {
            account.deposit(amount);
        } else if (serviceType == "Withdraw") {
            account.withdraw(amount);
        } else if (serviceType == "Transfer") {
            int toAccNum;
            cout << "Enter the account number to transfer to: ";
            cin >> toAccNum;
            Account *toAccount = customer.getAccount(toAccNum);
            if (toAccount != nullptr) {
                account.transfer(*toAccount, amount);
            } else {
                cout << "Account not found." << endl;
            }
        } else {
            cout << "Invalid service type." << endl;
        }
    }
};

int main() {
    Customer customer1(1, "Alice Smith");
    customer1.createAccount(1001, "Savings", 500.00);
    customer1.createAccount(1002, "Checking", 1000.00);

    BankingService service;
    Account *account = customer1.getAccount(1001);

    if (account) {
        service.executeService(customer1, *account, "Deposit", 200);
        service.executeService(customer1, *account, "Withdraw", 100);
        account->showTransactions();
    }

    customer1.showCustomerInfo();

    return 0;
}
