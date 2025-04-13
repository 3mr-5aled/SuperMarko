#include <iostream>
#include "struct.h"
using namespace std;

int loginUser(CUSTOMER customers[], const int numerofcustomers);
void registerUser(CUSTOMER customers[], const int numerofcustomers, fstream &myfile, int &id);
int menu_logging_in(CUSTOMER customers[], const int numerofcustomers, fstream &myfile, int &id);

void registerUser(CUSTOMER customers[], const int numerofcustomers, fstream &myfile, int &id)
{
    bool found = false, validPassword = false;
    int index = 0;

    for (int i = 0; i < numerofcustomers; i++)
    {
        if (!customers[i].ID)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << RED << "No empty slot to register.\n"
             << RESET;
        return;
    }

    customers[index].ID = index + 1;
    cout << CYAN << "Enter your username: " << RESET;
    cin.ignore();
    getline(cin, customers[index].Name);

    while (!validPassword)
    {
        cout << CYAN << "Enter your password: " << RESET;
        cin >> customers[index].Password;
        if (customers[index].Password.size() < 8)
        {
            cout << RED << "Password too short!\n"
                 << RESET;
        }
        else
        {
            validPassword = true;
        }
    }

    cout << CYAN << "Enter your phone number: " << RESET;
    cin >> customers[index].PhoneNumber;
    cin.ignore();
    cout << CYAN << "Enter your location: " << RESET;
    getline(cin, customers[index].Location);

    cout << GREEN << "Registration successful!\n"
         << RESET;

    // Move to end to append
    myfile.clear();
    myfile.seekp(0, ios::end);
    myfile << customers[index].ID << '\n'
           << customers[index].Name << '\n'
           << customers[index].PhoneNumber << '\n'
           << customers[index].Location << '\n'
           << customers[index].Password << '\n';

    menu_logging_in(customers, numerofcustomers, myfile, id);
}

int menu_logging_in(CUSTOMER customers[], const int numerofcustomers, fstream &myfile, int &id)
{
    int choice, flag = 1;
    cout << YELLOW << "Do you want to register or login?" << RESET << endl;
    cout << BLUE << "1. Register" << RESET << endl;
    cout << BLUE << "2. Login" << RESET << endl;
    cout << BLUE << "3. Exit The Program" << RESET << endl;
    cout << CYAN << "Enter your choice: " << RESET;
    cin >> choice;

    if (choice == 1)
    {
        registerUser(customers, numerofcustomers, myfile, id);
    }
    else if (choice == 2)
    {
        id = loginUser(customers, numerofcustomers);
        if (id == 0)
        {
            flag = 0;
            cout << RED << "LOGIN FAILED!....." << RESET << endl;
        }
    }
    else if (choice == 3)
    {
        cout << GREEN << "EXITING PROGRAM ..." << RESET << endl;
        flag = 0;
    }
    else
    {
        cout << RED << "Invalid choice" << RESET << endl;
        menu_logging_in(customers, numerofcustomers, myfile, id);
    }
    return flag;
}

int loginUser(CUSTOMER customers[], const int numerofcustomers)
{
    string username, password;
    int attempts = 3, index = 0;

    cin.ignore();
    while (attempts > 0)
    {
        cout << CYAN << "Enter your username: " << RESET;
        getline(cin, username);
        cout << CYAN << "Enter your password: " << RESET;
        getline(cin, password);

        bool found = false;
        for (int i = 0; i < numerofcustomers; i++)
        {
            if (!customers[i].Name.empty())
            {
                if (username == customers[i].Name && password == customers[i].Password)
                {
                    cout << GREEN << "Login successful" << RESET << endl;
                    index = i;
                    found = true;
                    break;
                }
            }
        }

        if (found)
            return customers[index].ID;
        else
        {
            attempts--;
            cout << RED << "The username or password is incorrect. " << RESET;
            if (attempts > 0)
                cout << YELLOW << "You have " << attempts << " attempt(s) left.\n"
                     << RESET;
            else
            {
                cout << RED << "\nNo attempts left.\n"
                     << RESET;
                return 0;
            }
        }
    }
    return 0;
}
