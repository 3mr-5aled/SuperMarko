#include <iostream>
#include "struct.h"
#include <conio.h>
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

    return;
}

int menu_logging_in(CUSTOMER customers[], const int numerofcustomers, fstream &myfile, int &id)
{
    int flag = 1;
    string input;
    int choice;

    while (true)
    {
        cout << YELLOW << "Do you want to register or login?" << RESET << endl;
        cout << BLUE << "1. Register" << RESET << endl;
        cout << BLUE << "2. Login" << RESET << endl;
        cout << BLUE << "0. Exit The Program" << RESET << endl;
        cout << CYAN << "Enter your choice: " << RESET;

        cin >> input;

        // Check if the input is a number
        if (input.length() == 1 && isdigit(input[0]))
        {
            choice = input[0] - '0'; // convert char to int
        }
        else
        {
            cout << RED << "Invalid input. Please enter a number (0, 1, or 2).\n"
                 << RESET;
            continue;
        }

        if (choice == 1)
        {
            registerUser(customers, numerofcustomers, myfile, id);
            flag = 1;
            break;
        }
        else if (choice == 2)
        {
            id = loginUser(customers, numerofcustomers);
            if (id == 0)
            {
                cout << RED << "LOGIN FAILED!....." << RESET << endl;
                flag = 0;
                break;
            }
            flag = 1;
            break;
        }
        else if (choice == 0)
        {
            cout << GREEN << "EXITING PROGRAM ..." << RESET << endl;
            flag = 0;
            break;
        }
        else
        {
            cout << RED << "Invalid choice. Please enter 0, 1, or 2.\n"
                 << RESET;
        }
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
        password = "";
        char ch;

        // Mask input
        while ((ch = getch()) != '\r') // Enter key
        {
            if (ch == '\b' && !password.empty())
            {
                password.pop_back();
                cout << "\b \b";
            }
            else if (ch != '\b')
            {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;
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
