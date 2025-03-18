#include <iostream>
#include <struct.h>
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
}

// Get Customer by ID
CUSTOMER getCustomerbyID(int customerID, CUSTOMER customer[])
{
    bool found = false;
    int index;
    for (int i = 0; i < 10; i++)
    {
        if (customer[i].ID == customerID)
        {
            index = i;
            found = true;
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
}

// Get Product by ID
PRODUCT getProductbyID(int productID, PRODUCT product[])
{
    bool found = false;
    int index;
    for (int i = 0; i < 10; i++)
    {
        if (product[i].Code == productID)
        {
            index = i;
            found = true;
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
}