#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

// ANSI escape codes for styling terminal output
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";

// Display menu to edit user information
int displayMenu()
{
    int choice;
    cout << BOLD << "What do you want to edit?" << RESET << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone Number" << endl;
    cout << "3. Location" << endl;
    cout << "4. Password" << endl;
    cout << RED << "5. Cancel" << RESET << endl;
    cout << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// Edit name
bool editName(CUSTOMER &currentCustomer)
{
    cout << "Enter the new name: ";
    cin.ignore();
    getline(cin, currentCustomer.Name);
    if (currentCustomer.Name.empty())
    {
        cout << RED << "Name cannot be empty. Please enter a valid name." << RESET << endl;
        return false;
    }
    return true;
}

// Edit phone number
bool editPhoneNumber(CUSTOMER &currentCustomer)
{
    cout << "Enter the new phone number: ";
    cin.ignore();
    getline(cin, currentCustomer.PhoneNumber);
    if (currentCustomer.PhoneNumber.empty() || currentCustomer.PhoneNumber.length() != 11 || currentCustomer.PhoneNumber.find_first_not_of("0123456789") != string::npos)
    {
        cout << RED << "Phone number must be 11 digits long and contain only numbers. Please enter a valid phone number." << RESET << endl;
        return false;
    }
    return true;
}

// Edit location
bool editLocation(CUSTOMER &currentCustomer)
{
    cout << "Enter the new location: ";
    cin.ignore();
    getline(cin, currentCustomer.Location);
    if (currentCustomer.Location.empty())
    {
        cout << RED << "Location cannot be empty. Please enter a valid location." << RESET << endl;
        return false;
    }
    return true;
}

// Edit password
bool editPassword(CUSTOMER &currentCustomer)
{
    string newPassword, confirmPassword;
    cout << "Enter the new password: ";
    cin.ignore();
    getline(cin, newPassword);
    if (newPassword.empty())
    {
        cout << RED << "Password cannot be empty. Please enter a valid password." << RESET << endl;
        return false;
    }
    cout << "Retype the new password: ";
    getline(cin, confirmPassword);
    if (newPassword != confirmPassword)
    {
        cout << RED << "Passwords do not match. Please try again." << RESET << endl;
        return false;
    }
    currentCustomer.Password = newPassword;
    return true;
}

// Display updated information
void displayUpdatedInformation(const CUSTOMER &currentCustomer)
{
    cout << endl;
    cout << GREEN << "The information has been updated successfully" << RESET << endl;
    cout << endl;
    cout << BOLD << "The updated information is:" << RESET << endl;
    cout << "Name: " << currentCustomer.Name << endl;
    cout << "Phone Number: " << currentCustomer.PhoneNumber << endl;
    cout << "Location: " << currentCustomer.Location << endl;
    cout << "Password: " << currentCustomer.Password << endl;
    cout << endl;
}

// Main function to edit user information
void editUserInformation(CUSTOMER currentCustomer)
{
    bool updated = false;
    bool continueEditing = true;

    while (continueEditing)
    {
        int choice = displayMenu();

        cout << endl;

        switch (choice)
        {
        case 1:
            updated = editName(currentCustomer);
            break;
        case 2:
            updated = editPhoneNumber(currentCustomer);
            break;
        case 3:
            updated = editLocation(currentCustomer);
            break;
        case 4:
            updated = editPassword(currentCustomer);
            break;
        case 5:
            cout << YELLOW << "No changes have been made" << RESET << endl;
            continueEditing = false;
            break;
        default:
            cout << RED << "Invalid choice" << RESET << endl;
            break;
        }

        if (updated)
        {
            displayUpdatedInformation(currentCustomer);
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