#include <iostream>
#include <struct.h>
using namespace std;

void Logout()
{
    int choice;
    cout << "Do tou to register or login?" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    if (choice == 1)
    {
        registerUser();
    }
    else if (choice == 2)
    {
        loginUser();
    }
    else
    {
        cout << "Invalid choice" << endl;
        Logout();
    }
    
}

void registerUser()
{
    CUSTOMER customer;
    // Data Entry
    cout << "Enter your username: ";
    cin >> customer.Name;
    // Username validation => Prevent same usernames twice 
    cout << "Enter your password: ";
    cin >> customer.Password;
    // Password Validations : 
    cout << "Enter your phone number: ";
    cin >> customer.PhoneNumber;
    cout << "Enter your location: ";
    cout << customer.Location;

    cout << "Registration successful" << endl;
    // Add The customer to The file that saves the data here =>
}

void loginUser()
{
    string username, password;
    // get the username and password from the user
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;
    // get the username and password from the file
    if (username == "admin" && password == "admin")
    {
        cout << "Login successful" << endl;
    }
    else
    {
        cout << "The username or password is incorrect" << endl;
        Logout();
    }
}
