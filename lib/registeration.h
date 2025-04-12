#include <iostream>
#include "struct.h"
using namespace std;
void loginUser(CUSTOMER customers[], const int numerofcustomers);
void registerUser(CUSTOMER customers[], const int numerofcustomers);
void menu_logging_in(CUSTOMER customers[], const int numerofcustomers);

void registerUser(CUSTOMER customers[], const int numerofcustomers)
{
    bool found = false,validPassword;
    int index=0;
    for (int i = 0; i < numerofcustomers; i++)
    {
        if (!customers[i].ID)
        {
            index =i;
            found =true;
            break;
        }
        
    }
    // Data Entry
    cout<<index;
    cout << "Enter your username: ";
    cin >> customers[index].Name;
    // Username validation => Prevent same usernames twice 
    while (!validPassword) {
    cout << "Enter your password: ";
    cin >> customers[index].Password;
    if (customers[index].Password.size() < 8) {
        cout << "Error: Password must be at least 8 characters long!\n";
    } else {
        validPassword = true;
    }
}
    // Password Validations : 
    cout << "Enter your phone number: ";
    cin >> customers[index].PhoneNumber;
    cout << "Enter your location: ";
    cin >> customers[index].Location;

    cout << "Registration successful" << endl;

    // Add The customer to The file that saves the data here =>
    loginUser(customers,numerofcustomers);
}
void menu_logging_in(CUSTOMER customers[], const int numerofcustomers)
{
    int choice;
    cout << "Do you want to register or login?" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cin>>choice;
    if (choice == 1)
    {
        registerUser(customers,numerofcustomers);
    }
    else if (choice == 2)
    {
        loginUser(customers,numerofcustomers);
    }
    else
    {
        cout << "Invalid choice" << endl;
        menu_logging_in( customers,numerofcustomers);
    }
    
}
void loginUser(CUSTOMER customers[], const int numerofcustomers)
{
    string username, password;
    int attempts = 3;

    cin.ignore(); // Clear input buffer only once before entering the loop

    while (attempts > 0)
    {
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

        bool found = false;
        for (int i = 0; i < numerofcustomers; i++)
        {
            if (username == customers[i].Name && password == customers[i].Password)
            {
                cout << "Login successful" << endl;
                found = true;
                break;
            }
        }

        if (found)
            return;
        else
        {
            attempts--;
            cout << "The username or password is incorrect. ";
            if (attempts > 0)
                cout << "You have " << attempts << " attempt(s) left.\n";
            else {
                cout << "\nNo attempts left. Logging out...\n";
                return;
            }
        }
    }
}
