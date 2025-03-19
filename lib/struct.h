#ifndef STRUCT_H
#define STRUCT_H

#include <iostream>
#include <string>
using namespace std;

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
    // ID of the customer is same as it's index in the array
    int ID;
    string Name;
    string PhoneNumber;
    string Location;
    string Password;
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
    PRODUCT Products[20];
    double TotalPrice;
};
#endif // STRUCT_H
