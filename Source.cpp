/* important dev notes */
/*

! use camelCase for variables and functions
! use UpperCase for structures
! use comments to explain the code

*/

#include <iostream>
#include <string>
#include "struct.h"
#include "edit_functions.h"
using namespace std;

int main()
{
    cout << "Welcome to SUPERMARKO" << endl;

    // Initialize the orders array
    ORDER orders[numOfOrders];
    PRODUCT products[numOfProducts];
    CUSTOMER customers[numOfCustomers];

    // Call the edit function
    edit(orders, products, customers);

    return 0;
}

// * Amr Khaled Section

void edit(ORDER orders[], PRODUCT products[], CUSTOMER customers[])
{
    // select what you want to edit
    cout << "Select what you want to edit" << endl;
    cout << "1. Order" << endl;
    cout << "2. Product" << endl;
    cout << "3. Customer" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        editOrder(orders);
        break;
    case 2:
        editProduct(products);
        break;
    case 3:
        editCustomer(customers);
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }
}
