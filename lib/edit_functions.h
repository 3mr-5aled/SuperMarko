#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

void editUserInformation(CUSTOMER currentCustomer)
{
    // ANSI escape codes for styling terminal output
    const string RESET = "\033[0m";
    const string BOLD = "\033[1m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";

    bool updated = false;
    bool continueEditing = true;

    while (continueEditing)
    {
        // select what you want to edit
        cout << BOLD << "What do you want to edit?" << RESET << endl;
        cout << "1. Name" << endl;
        cout << "2. Phone Number" << endl;
        cout << "3. Location" << endl;
        cout << RED << "4. Cancel" << RESET << endl;
        cout << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter the new name: ";
            cin.ignore();
            getline(cin, currentCustomer.Name);
            // Validate the name
            if (currentCustomer.Name.empty())
            {
                cout << RED << "Name cannot be empty. Please enter a valid name." << RESET << endl;
                break;
            }
            updated = true;
            break;
        case 2:
            cout << "Enter the new phone number: ";
            cin.ignore();
            getline(cin, currentCustomer.PhoneNumber);
            // Validate the phone number (must be 11 digits long and contain only numbers)
            if (currentCustomer.PhoneNumber.empty() || currentCustomer.PhoneNumber.length() != 11 || currentCustomer.PhoneNumber.find_first_not_of("0123456789") != string::npos)
            {
                cout << RED << "Phone number must be 11 digits long and contain only numbers. Please enter a valid phone number." << RESET << endl;
                break;
            }
            updated = true;
            break;
        case 3:
            cout << "Enter the new location: ";
            cin.ignore();
            getline(cin, currentCustomer.Location);
            // Validate the location
            if (currentCustomer.Location.empty())
            {
                cout << RED << "Location cannot be empty. Please enter a valid location." << RESET << endl;
                break;
            }
            updated = true;
            break;
        case 4:
            cout << YELLOW << "No changes have been made" << RESET << endl;
            continueEditing = false;
            break;
        default:
            cout << RED << "Invalid choice" << RESET << endl;
            break;
        }

        if (updated)
        {
            cout << endl;
            cout << GREEN << "The information has been updated successfully" << RESET << endl;
            // display the updated information
            cout << endl;
            cout << BOLD << "The updated information is:" << RESET << endl;
            cout << "Name: " << currentCustomer.Name << endl;
            cout << "Phone Number: " << currentCustomer.PhoneNumber << endl;
            cout << "Location: " << currentCustomer.Location << endl;
            cout << endl;

            // Ask if the user wants to edit another data
            cout << "Do you want to edit another data? (y/n): ";
            char editMore;
            cin >> editMore;
            if (editMore == 'n' || editMore == 'N')
            {
                continueEditing = false;
            }
        }
        else
        {
            cout << YELLOW << "The information has not been updated" << RESET << endl;
        }

        cout << endl;
    }
}