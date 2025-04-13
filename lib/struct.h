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
}customers[numOfCustomers];

// product structure
struct PRODUCT
{
    string Code;
    string Name;
    string Category;
    DATE ProductionDate;
    DATE ExpiredDate;
    double Price;
}product[numOfCategories][numOfProducts];

// order structure
struct ORDER
{
    int CustomerID;
    PRODUCT Products[20];
    double TotalPrice;
};
#endif // STRUCT_H
