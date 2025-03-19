#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

void editUserInformation(CUSTOMER currentCustomer)
{
    // check if data is updated
    bool updated = false;

    // select what you want to edit
    cout << "What do you want to edit?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone Number" << endl;
    cout << "3. Location" << endl;
    int choice;
    switch (choice)
    {
    case 1:
        cout << "Enter the new name: ";
        cin.ignore();
        getline(cin, currentCustomer.Name);
        // Validate the name
        if (currentCustomer.Name.empty())
        {
            cout << "Name cannot be empty. Please enter a valid name." << endl;
            break;
        }
        updated = true;
        break;
    case 2:
        cout << "Enter the new phone number: ";
        cin.ignore();
        getline(cin, currentCustomer.PhoneNumber);
        // Validate the phone number (must be 10 digits long and contain only numbers)
        if (currentCustomer.PhoneNumber.empty() || currentCustomer.PhoneNumber.length() != 11 || currentCustomer.PhoneNumber.find_first_not_of("0123456789") != string::npos)
        {
            cout << "Phone number must be 10 digits long and contain only numbers. Please enter a valid phone number." << endl;
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
            cout << "Location cannot be empty. Please enter a valid location." << endl;
            break;
        }
        updated = true;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    // display the result
    if (updated)
    {
        cout << "The information has been updated successfully" << endl;
        // display the updated information
        cout << "The updated information is:" << endl;
        cout << "Name: " << currentCustomer.Name << endl;
        cout << "Phone Number: " << currentCustomer.PhoneNumber << endl;
        cout << "Location: " << currentCustomer.Location << endl;
    }
    else
        cout << "The information has not been updated" << endl;
}