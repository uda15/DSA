#include <iostream>
using namespace std;

// ---------------- Base Class ----------------
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    // Encapsulation (getter)
    double getBalance() {
        return balance;
    }

    // Deposit
    virtual void deposit(double amount) {
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    // Withdraw
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    // Polymorphic method
    virtual void calculateInterest() {
        cout << "No interest for base account.\n";
    }

    // Display info
    virtual void displayAccountInfo() {
        cout << "\nAccount Number: " << accountNumber;
        cout << "\nAccount Holder: " << accountHolderName;
        cout << "\nBalance: " << balance << endl;
    }

    virtual ~BankAccount() {}
};

// ---------------- Savings Account ----------------
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal) {
        interestRate = rate;
    }

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        balance += interest;
        cout << "Savings interest added: " << interest << endl;
    }
};

// ---------------- Checking Account ----------------
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal) {
        overdraftLimit = limit;
    }

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawal successful (Overdraft allowed).\n";
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }

    void calculateInterest() override {
        cout << "No interest for checking account.\n";
    }
};

// ---------------- Fixed Deposit Account ----------------
class FixedDepositAccount : public BankAccount {
private:
    int term; // in months

public:
    FixedDepositAccount(int accNo, string name, double bal, int t)
        : BankAccount(accNo, name, bal) {
        term = t;
    }

    void calculateInterest() override {
        double rate = 6.5;
        double interest = balance * rate * term / (12 * 100);
        balance += interest;
        cout << "Fixed Deposit interest added: " << interest << endl;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal not allowed before maturity.\n";
    }
};

// ---------------- Main Program ----------------
int main() {
    BankAccount* account = nullptr;
    int choice;

    do {
        cout << "\n------ Bank Menu ------";
        cout << "\n1. Create Savings Account";
        cout << "\n2. Create Checking Account";
        cout << "\n3. Create Fixed Deposit Account";
        cout << "\n4. Deposit";
        cout << "\n5. Withdraw";
        cout << "\n6. Calculate Interest";
        cout << "\n7. Display Account Info";
        cout << "\n0. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            account = new SavingsAccount(101, "Arpit", 5000, 4);
            cout << "Savings Account Created.\n";
            break;

        case 2:
            account = new CheckingAccount(102, "Arpit", 3000, 2000);
            cout << "Checking Account Created.\n";
            break;

        case 3:
            account = new FixedDepositAccount(103, "Arpit", 10000, 12);
            cout << "Fixed Deposit Account Created.\n";
            break;

        case 4:
            if (account) {
                double amt;
                cout << "Enter amount: ";
                cin >> amt;
                account->deposit(amt);
            }
            break;

        case 5:
            if (account) {
                double amt;
                cout << "Enter amount: ";
                cin >> amt;
                account->withdraw(amt);
            }
            break;

        case 6:
            if (account)
                account->calculateInterest();
            break;

        case 7:
            if (account)
                account->displayAccountInfo();
            break;

        case 0:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    delete account;
    return 0;
}
