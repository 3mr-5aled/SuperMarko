#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>
using namespace std;

// Define the constants
const int numOfProducts = 10;
const int numOfCategories = 10;
const int numOfOrders = 20;
const int numOfCustomers = 10;

// date structure
struct DATE
{
    int Day;
    int Month;
    int Year;
};

// customer structure
struct CUSTOMER
{
    // ID of the customer is same as it's index in the array
    int ID;
    string Name;
    string PhoneNumber;
    string Location;
    string Password;
} customers[numOfCustomers];

// product structure
struct PRODUCT
{
    string Code;
    string Name;
    string Category;
    DATE ProductionDate;
    DATE ExpiredDate;
    double Price;
} product[numOfCategories][numOfProducts];

// order structure
struct ORDER
{
    int CustomerID;
    PRODUCT Products[20];
    double TotalPrice;
};

// ANSI escape codes for styling terminal output
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string RED = "\033[91m";          // Bright red
const string GREEN = "\033[92m";        // Bright green
const string YELLOW = "\033[93m";       // Bright yellow
const string BLUE = "\033[94m";         // Bright blue
const string CYAN = "\033[96m";         // Bright cyan
const string PURPLE = "\033[95m";       // Bright magenta
const string WHITE_BG = "\033[107m";    // Bright white background
const string BLACK_TEXT = "\033[90m";   // Bright black (gray) text
const string ORANGE = "\033[38;5;214m"; // Bright orange
const string TEAL = "\033[36m";         // Teal color

#endif // STRUCT_H
