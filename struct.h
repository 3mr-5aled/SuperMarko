#include <iostream>
#include <string>
using namespace std;

// Define constants
const int numOfProducts = 10;
const int numOfOrders = 20;
const int numOfCustomers = 10;

// Define the structures

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
    int ID;
    string Name;
    string PhoneNumber;
    string Location;
};

// product structure

struct PRODUCT
{
    int Code;
    string Name;
    string Category;
    DATE ProductionDate;
    DATE ExpiredDate;
    double Price;
};

// order structure

struct ORDER
{
    int CustomerID;
    PRODUCT Products[numOfProducts];
    double TotalPrice;
};
