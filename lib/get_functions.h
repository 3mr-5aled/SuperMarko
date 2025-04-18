 #include <iostream>
#include "struct.h"
using namespace std;

// Get Functions

// Get Order by ID
ORDER getOrderbyID(int orderID, ORDER order[])
{
    bool found = false;
    int index;
    for (int i = 0; i < 20; i++)
    {
        if (order[i].CustomerID == orderID)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        return order[index];
    }
    else
    {
        cout << "Order not found" << endl;
    }
    return ORDER();
}

// Get Customer by ID
CUSTOMER getCustomerbyID(int customerID, CUSTOMER customer[],const int numofcustomers)
{
    bool found = false;
    int index;
    for (int i = 0; i < numOfCustomers; i++)
    {
        if (customer[i].ID == customerID)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        return customer[index];
    }
    else
    {
        cout << "Customer not found" << endl;
    }
    return CUSTOMER();
}

// Get Product by ID
PRODUCT getProductbyID(string productID, PRODUCT product[])
{
    bool found = false;
    int index;
    for (int i = 0; i < 10; i++)
    {
        if (product[i].Code == productID)
        {
            index = i;
            found = true;
            break;
        }
    }

    if (found)
    {
        return product[index];
    }
    else
    {
        cout << "Product not found" << endl;
    }
    return PRODUCT();
}