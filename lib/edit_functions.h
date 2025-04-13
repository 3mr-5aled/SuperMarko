#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

// ANSI escape codes for styling terminal output
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";
const string PURPLE = "\033[35m";
const string WHITE_BG = "\033[47m";
const string BLACK_TEXT = "\033[30m";

// Display menu to edit user information
int displayMenu()
{
    int choice;
    cout << BOLD << UNDERLINE << CYAN << "What do you want to edit?" << RESET << endl;
    cout << BOLD << "1. " << GREEN << "Name" << RESET << endl;
    cout << BOLD << "2. " << GREEN << "Phone Number" << RESET << endl;
    cout << BOLD << "3. " << GREEN << "Location" << RESET << endl;
    cout << BOLD << "4. " << GREEN << "Password" << RESET << endl;
    cout << BOLD << "5. " << RED << "Cancel" << RESET << endl;
    cout << endl;
    cout << BOLD << YELLOW << "Enter your choice: " << RESET;
    cin >> choice;
    return choice;
}

// Edit name
bool editName(CUSTOMER &currentCustomer)
{
    cout << BOLD << BLUE << "Current Name: " << RESET << currentCustomer.Name << endl;
    cout << endl;
    cout << BOLD << CYAN << "Enter the new name: " << RESET;
    cin.ignore();
    getline(cin, currentCustomer.Name);
    if (currentCustomer.Name.empty())
    {
        cout << RED << BOLD << "Error: " << RESET << "Name cannot be empty. Please enter a valid name." << endl;
        return false;
    }
    return true;
}

// Edit phone number
bool editPhoneNumber(CUSTOMER &currentCustomer)
{
    cout << BOLD << BLUE << "Current Phone Number: " << RESET << currentCustomer.PhoneNumber << endl;
    cout << endl;
    cout << BOLD << CYAN << "Enter the new phone number: " << RESET;
    cin.ignore();
    getline(cin, currentCustomer.PhoneNumber);
    if (currentCustomer.PhoneNumber.empty() || currentCustomer.PhoneNumber.length() != 11 || currentCustomer.PhoneNumber.find_first_not_of("0123456789") != string::npos)
    {
        cout << RED << BOLD << "Error: " << RESET << "Phone number must be 11 digits long and contain only numbers. Please enter a valid phone number." << endl;
        return false;
    }
    return true;
}

// Edit location
bool editLocation(CUSTOMER &currentCustomer)
{
    cout << BOLD << BLUE << "Current Location: " << RESET << currentCustomer.Location << endl;
    cout << endl;
    cout << BOLD << CYAN << "Enter the new location: " << RESET;
    cin.ignore();
    getline(cin, currentCustomer.Location);
    if (currentCustomer.Location.empty())
    {
        cout << RED << BOLD << "Error: " << RESET << "Location cannot be empty. Please enter a valid location." << endl;
        return false;
    }
    return true;
}

// Edit password
bool editPassword(CUSTOMER &currentCustomer)
{
    string newPassword, confirmPassword;
    cout << BOLD << CYAN << "Enter the new password: " << RESET;
    cin.ignore();
    getline(cin, newPassword);
    if (newPassword.empty())
    {
        cout << RED << BOLD << "Error: " << RESET << "Password cannot be empty. Please enter a valid password." << endl;
        return false;
    }
    cout << BOLD << CYAN << "Retype the new password: " << RESET;
    getline(cin, confirmPassword);
    if (newPassword != confirmPassword)
    {
        cout << RED << BOLD << "Error: " << RESET << "Passwords do not match. Please try again." << endl;
        return false;
    }
    currentCustomer.Password = newPassword;
    return true;
}

// Display updated information
void displayInformation(const CUSTOMER &currentCustomer, int state)
{
    if (state != 1 && state != 2)
    {
        cout << RED << BOLD << "Error: " << RESET << "Invalid state for displaying information." << endl;
        return;
    }
    if (state == 1)
    {
        cout << BOLD << YELLOW << UNDERLINE << "Your Information:" << RESET << endl;
        cout << BOLD << "-------------------" << RESET << endl;
        cout << GREEN << "Name: " << RESET << currentCustomer.Name << endl;
        cout << GREEN << "Phone Number: " << RESET << currentCustomer.PhoneNumber << endl;
        cout << GREEN << "Location: " << RESET << currentCustomer.Location << endl;
        cout << GREEN << "Password: " << RESET << currentCustomer.Password << endl;
        cout << BOLD << "-------------------" << RESET << endl;
    }
    else if (state == 2)
    {
        cout << endl;
        cout << GREEN << BOLD << "Success: " << RESET << "The information has been updated successfully!" << endl;
        cout << endl;
        cout << BOLD << YELLOW << UNDERLINE << "The Updated Information:" << RESET << endl;
        cout << BOLD << "--------------------------" << RESET << endl;
        cout << GREEN << "Name: " << RESET << currentCustomer.Name << endl;
        cout << GREEN << "Phone Number: " << RESET << currentCustomer.PhoneNumber << endl;
        cout << GREEN << "Location: " << RESET << currentCustomer.Location << endl;
        cout << GREEN << "Password: " << RESET << currentCustomer.Password << endl;
        cout << BOLD << "--------------------------" << RESET << endl;
    }
    cout << endl;
}

// Main function to edit user information
void editUserInformation(CUSTOMER currentCustomer)
{
    bool updated = false;
    bool continueEditing = true;

    while (continueEditing)
    {
        displayInformation(currentCustomer, 1);
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
            cout << YELLOW << BOLD << "No changes have been made." << RESET << endl;
            continueEditing = false;
            break;
        default:
            cout << RED << BOLD << "Error: " << RESET << "Invalid choice." << endl;
            break;
        }

        if (updated)
        {
            displayInformation(currentCustomer, 2);
            char editMore;
            do
            {
                cout << BOLD << CYAN << "Do you want to edit another data? (y/n): " << RESET;
                cin >> editMore;
                if (editMore == 'n' || editMore == 'N')
                {
                    continueEditing = false;
                }
                else if (editMore == 'y' || editMore == 'Y')
                {
                    continueEditing = true;
                }
                else
                {
                    cout << RED << BOLD << "Error: " << RESET << "Invalid input. Please enter 'y' or 'n'." << endl;
                }
            } while (editMore != 'y' && editMore != 'Y' && editMore != 'n' && editMore != 'N');
        }
        else
            cout << YELLOW << BOLD << "The information has not been updated." << RESET << endl;
    }

    cout << endl;
}
