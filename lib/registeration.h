#include <iostream>
#include "struct.h"
using namespace std;
int loginUser(CUSTOMER customers[], const int numerofcustomers);
void registerUser(CUSTOMER customers[], const int numerofcustomers,fstream &myfile,int &id);
int menu_logging_in(CUSTOMER customers[], const int numerofcustomers,fstream &myfile,int &id);

void registerUser(CUSTOMER customers[], const int numerofcustomers, fstream &myfile,int &id) {
    bool found = false, validPassword = false;
    int index = 0;

    for (int i = 0; i < numerofcustomers; i++) {
        if (!customers[i].ID) {
            index = i;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No empty slot to register.\n";
        return;
    }

    customers[index].ID = index + 1;
    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, customers[index].Name);

    while (!validPassword) {
        cout << "Enter your password: ";
        cin >> customers[index].Password;
        if (customers[index].Password.size() < 8) {
            cout << "Password too short!\n";
        } else {
            validPassword = true;
        }
    }

    cout << "Enter your phone number: ";
    cin >> customers[index].PhoneNumber;
    cin.ignore();
    cout << "Enter your location: ";
    getline(cin, customers[index].Location);
    
    cout << "Registration successful!\n";

    // Move to end to append
    myfile.clear();
    myfile.seekp(0, ios::end);
    myfile << customers[index].ID << '\n'
           << customers[index].Name << '\n'
           << customers[index].PhoneNumber << '\n'
           << customers[index].Location << '\n'
           << customers[index].Password << '\n';


    // Add The customer to The file that saves the data here =>
    menu_logging_in(customers,numerofcustomers,myfile,id);
}

int menu_logging_in(CUSTOMER customers[], const int numerofcustomers,fstream &myfile,int &id)
{
    int choice,flag=1;
    cout << "Do you want to register or login?" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout<<  "3. Exit THe Progam"<<endl;
    cin>>choice;
    if (choice == 1)
    {
        registerUser(customers,numerofcustomers,myfile,id);
    }
    else if (choice == 2)
    {
        id =loginUser(customers,numerofcustomers);
        if (id ==0)
        {
            flag =0;
            cout << "LOGIN FAILED !....." << endl;
        }
        
    }
    else if (choice == 3){
        cout << "EXITING PROGRAM ..." << endl;
        flag =0;
 
    }
    else
    {
        cout << "Invalid choice" << endl;
        menu_logging_in( customers,numerofcustomers,myfile,id);
    }
    return flag;
}
int loginUser(CUSTOMER customers[], const int numerofcustomers)
{
    string username, password;
    int attempts = 3,index=0;

    cin.ignore();
    while (attempts > 0)
    {
        cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

        bool found = false;
        for (int i = 0; i < numerofcustomers; i++)
        {
            if(!customers[i].Name.empty()){
            if (username == customers[i].Name && password == customers[i].Password)
            {
                cout << "Login successful" << endl;
                index=i;
                found = true;
                break;
            }
        }
        }

        if (found)
            return customers[index].ID ;
        else
        {
            attempts--;
            cout << "The username or password is incorrect. ";
            if (attempts > 0)
                cout << "You have " << attempts << " attempt(s) left.\n";
            else {
                cout << "\nNo attempts left.\n";
                return 0;
            }
        }
    }
    return 0;
}
