#include <iostream>
#include <string>
#include "struct.h"
using namespace std;

// Display menu to edit user information
int displayMenu()
{
    string choice;
    int digitchoice;
    while (true)
    {
        cout << BOLD << UNDERLINE << CYAN << "What do you want to edit?" << RESET << endl;
        cout << BOLD << "1. " << GREEN << "Name" << RESET << endl;
        cout << BOLD << "2. " << GREEN << "Phone Number" << RESET << endl;
        cout << BOLD << "3. " << GREEN << "Location" << RESET << endl;
        cout << BOLD << "4. " << GREEN << "Password" << RESET << endl;
        cout << BOLD << "0. " << RED << "Cancel" << RESET << endl;
        cout << endl;
        cout << BOLD << YELLOW << "Enter your choice: " << RESET;
        cin >> choice;
        if (choice.length() == 1 && isdigit(choice[0]))
        {
            digitchoice = choice[0] - '0';
            if (digitchoice >= 0 && digitchoice <= 4)
                break;
            else
                cout << RED << "Invalid choice. Please enter a number between 0 and 4.\n"
                     << RESET;
        }
        else
            cout << RED << "Invalid choice. Please enter a number from the menu.\n"
                 << RESET;
    }
    return digitchoice;
}

// Edit name
bool editName(CUSTOMER &currentCustomer)
{
    string input;
    while (true)
    {
        cout << BOLD << BLUE << "Current Name: " << RESET << currentCustomer.Name << endl;
        cout << endl;
        cout << BOLD << CYAN << "Enter the new name: " << RESET;
        cin.ignore();
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos)
        {
            cout << RED << BOLD << "Error: " << RESET << "Name cannot be empty. Please enter a valid name." << endl;
        }
        else
        {
            currentCustomer.Name = input;
            return true;
        }
    }
}

// Edit phone number
bool editPhoneNumber(CUSTOMER &currentCustomer)
{
    string input;
    cout << BOLD << BLUE << "Current Phone Number: " << RESET << currentCustomer.PhoneNumber << endl;
    cout << endl;

    while (true)
    {
        cout << BOLD << CYAN << "Enter the new phone number: " << RESET;
        getline(cin, input);

        if (input.empty() || input.length() != 11 || input.find_first_not_of("0123456789") != string::npos)
        {
            cout << RED << BOLD << "Error: " << RESET << "Phone number must be 11 digits long and contain only numbers." << endl;
            continue;
        }
        else
        {
            currentCustomer.PhoneNumber = input;
            return true;
        }
    }
}

// Edit location
bool editLocation(CUSTOMER &currentCustomer)
{
    string input;
    while (true)
    {
        cout << BOLD << BLUE << "Current Location: " << RESET << currentCustomer.Location << endl;
        cout << endl;
        cout << BOLD << CYAN << "Enter the new location: " << RESET;
        cin.ignore();
        getline(cin, input);

        if (input.empty() || input.find_first_not_of(' ') == string::npos)
        {
            cout << RED << BOLD << "Error: " << RESET << "Location cannot be empty." << endl;
        }
        else
        {
            currentCustomer.Location = input;
            return true;
        }
    }
}

// Edit password
bool editPassword(CUSTOMER &currentCustomer)
{
    string newPassword, confirmPassword;
    char ch;

    while (true) // Loop until valid password is set
    {
        newPassword = "";
        cout << BOLD << CYAN << "Enter the new password: " << RESET;

        while ((ch = _getch()) != '\r') // Enter to finish
        {
            if (ch == '\b' && !newPassword.empty())
            {
                newPassword.pop_back();
                cout << "\b \b";
            }
            else if (ch != '\b')
            {
                newPassword += ch;
                cout << '*';
            }
        }
        cout << endl;

        if (newPassword.empty())
        {
            cout << RED << BOLD << "Error: " << RESET << "Password cannot be empty.\n";
            continue;
        }

        if (newPassword.length() < 8)
        {
            cout << RED << BOLD << "Error: " << RESET << "Password must be at least 8 characters long.\n";
            continue;
        }

        confirmPassword = "";
        cout << BOLD << CYAN << "Retype the new password: " << RESET;

        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b' && !confirmPassword.empty())
            {
                confirmPassword.pop_back();
                cout << "\b \b";
            }
            else if (ch != '\b')
            {
                confirmPassword += ch;
                cout << '*';
            }
        }
        cout << endl;

        if (newPassword != confirmPassword)
        {
            cout << RED << BOLD << "Error: " << RESET << "Passwords do not match.\n";
            continue;
        }

        break; // Success
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
void editUserInformation(CUSTOMER customers[], int id, int numOfCustomers)
{
    bool updated = false;
    bool continueEditing = true;
    int index = -1;

    for (int i = 0; i < numOfCustomers; i++)
    {
        if (customers[i].ID == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << RED << "Customer with ID " << id << " not found." << RESET << endl;
        return;
    }

    while (continueEditing)
    {
        displayInformation(customers[index], 1);
        int choice = displayMenu();

        cout << endl;

        switch (choice)
        {
        case 1:
            updated = editName(customers[index]);
            break;
        case 2:
            updated = editPhoneNumber(customers[index]);
            break;
        case 3:
            updated = editLocation(customers[index]);
            break;
        case 4:
            updated = editPassword(customers[index]);
            break;
        case 0:
            cout << YELLOW << BOLD << "No changes have been made." << RESET << endl;
            continueEditing = false;
            break;
        default:
            cout << RED << BOLD << "Error: " << RESET << "Invalid choice." << endl;
            break;
        }

        if (updated)
        {
            displayInformation(customers[index], 2);
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
