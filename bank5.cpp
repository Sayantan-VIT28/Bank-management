#include<iostream>
using namespace std;

class Bank {
    char name[20];
    int accno;
    char type[10];
    int balance;
    int pin;

public:
    Bank() {
        balance = 0;
    }

    void initialize() {
        getname();
        getaccno();
        gettype();
        do {
            getbalance();
            if (balance < 1000) {
                cout << "Initial balance must be at least 1000." << endl;
            }
        } while (balance < 1000);
        getpin();
    }

    void getname() {
        cout << "Enter name of the account holder: ";
        cin >> name;
    }
    void getaccno() {
        cout << "Enter account number: ";
        cin >> accno;
    }
    void gettype() {
        cout << "Enter type of account: (Savings/Current) ";
        cin >> type;
    }
    void getbalance() {
        cout << "Enter balance: ";
        cin >> balance;
    }
    void getpin() {
        cout << "Enter PIN: ";
        cin >> pin;
    }
    void deposit() {
        int amt;
        cout << "Enter amount to deposit: ";
        cin >> amt;
        balance += amt;
    }
    void withdraw() {
        int amt;
        cout << "Enter amount to withdraw: ";
        cin >> amt;
        if (amt > balance)
            cout << "Insufficient balance" << endl;
        else
            balance -= amt;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Account number: " << accno << endl;
        cout << "Type of account: " << type << endl;
        cout << "Balance: " << balance << endl;
    }
    bool verifyPin(int inputPin) {
        return pin == inputPin;
    }
};

int main() {
    Bank accounts[5]; 
    int choice, userIndex, userPin;
    for (int i = 0; i < 5; i++) {
        cout << "\nInitializing account for person " << i + 1 << endl;
        accounts[i].initialize();
    }

    do {
        cout << "\nEnter the user number (1-5): ";
        cin >> userIndex;
        userIndex--;  

        if (userIndex < 0 || userIndex >= 5) {
            cout << "Invalid user number!" << endl;
            continue;
        }

        cout << "Enter PIN for user " << userIndex + 1 << ": ";
        cin >> userPin;

        if (!accounts[userIndex].verifyPin(userPin)) {
            cout << "Incorrect PIN. Try again." << endl;
            continue;
        }
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Display\n4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    accounts[userIndex].deposit();
                    break;
                case 2:
                    accounts[userIndex].withdraw();
                    break;
                case 3:
                    accounts[userIndex].display();
                    break;
                case 4:
                    cout << "Exiting the program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 4);

    } while (true);

    return 0;
}
