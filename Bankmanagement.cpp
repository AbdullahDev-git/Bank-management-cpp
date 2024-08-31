#include <iostream>
#include <string>

using namespace std;

// Basic structure
struct Account
{
    string username;
    string password;
    double balance;
};

// Single account
Account account;

//  creating a new account
void createAccount()
{

    cout << "Enter username: ";
    cin >> account.username;
    cout << "Enter password: ";
    cin >> account.password;
    account.balance = 0.0;
    cout << "Account created successfully." << endl;
}

// Function to login
bool login()
{
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (account.username == username && account.password == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//  deposit cash
void deposit()
{
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    account.balance += amount;
    cout << "Deposit successful. New balance: " << account.balance << endl;
}

//  check balance
void checkBalance()
{
    cout << "Current balance: " << account.balance << endl;
}

//  withdraw cash
void withdraw()
{
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (account.balance >= amount)
    {
        account.balance -= amount;
        cout << "Withdrawal successful. New balance: " << account.balance << endl;
    }
    else
    {
        cout << "Insufficient balance." << endl;
    }
}

int main()
{
    int choice;
    bool loggedIn = false;

    while (true)
    {
        cout << "\nBanking System Menu:\n";
        cout << "1. Create New Account" << endl;
        cout << "-------------------------------" << endl;
        cout << "2. Log In" << endl;
        cout << "-------------------------------" << endl;
        cout << "3. Deposit Cash" << endl;
        cout << "-------------------------------" << endl;
        cout << "4. Check Balance" << endl;
        cout << "-------------------------------" << endl;
        cout << "5. Withdraw Cash" << endl;
        cout << "-------------------------------" << endl;
        cout << "6. Exit" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "-------------------------------" << endl;

        cout << "\n\t\t\t\t\t\t     WELCOME" << endl;
        cout << "\n\t\t\t\t\t\tBANKING SYSTEM\n";
        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            loggedIn = login();
            if (loggedIn)
            {
                cout << "Login successful." << endl;
            }
            else
            {
                cout << "Invalid username or password." << endl;
            }
            break;
        case 3:
            if (loggedIn)
            {
                deposit();
            }
            else
            {
                cout << "Please log in first." << endl;
            }
            break;
        case 4:
            if (loggedIn)
            {
                checkBalance();
            }
            else
            {
                cout << "Please log in first." << endl;
            }
            break;
        case 5:
            if (loggedIn)
            {
                withdraw();
            }
            else
            {
                cout << "Please log in first." << endl;
            }
            break;
        case 6:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}