#include <iostream>
#include <string>
#include "struct.h"
#include "get_functions.h"
using namespace std;

// Edit Order Functions
void editOrder(ORDER orders[])
{
    cout << "Enter the order ID you want to edit : " << endl;
    // TODO function viewOrders()
    // select an order to edit
    int selectedOrderID;
    cin >> selectedOrderID;

    ORDER currentOrder = getOrderbyID(selectedOrderID, orders);

    // TODO function viewOrderDetails(int orderID)
    // select what you want to edit
    cout << "Select what you want to edit" << endl;
    cout << "1. Customer ID" << endl;
    cout << "2. Product" << endl;
    cout << "3. Total Price" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        // edit the customer ID
        int newCustomerID = editOrderCustomerID(currentOrder);
        currentOrder.CustomerID = newCustomerID;
        cout << "Customer ID updated successfully" << endl;
        break;
    case 2:
        // edit the product in the order
        editOrderProduct(currentOrder);
        cout << "Product updated successfully" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "Order saved" << endl;
    // view edited order
    // TODO function viewOrderDetails(int orderID)
}

int editOrderCustomerID(ORDER order)
{
    int newCustomerID;
    cout << "Enter the new Customer ID : " << endl;
    cin >> newCustomerID;

    // Validate the new customer ID
    if (newCustomerID < 0)
    {
        cout << "Invalid Customer ID. Please enter a positive number." << endl;
        return order.CustomerID; // Return the original ID if validation fails
    }

    return newCustomerID;
}
void editOrderProduct(ORDER &order)
{
    cout << "Edit product function called" << endl;
    // Display the products in the order
    for (int i = 0; i < numOfProducts; i++)
    {
        cout << i + 1 << ". " << order.Products[i].Name << " - " << order.Products[i].Price << endl;
    }

    // Select a product to edit
    cout << "Enter the product number you want to edit: ";
    int productNumber;
    cin >> productNumber;

    if (productNumber < 1 || productNumber > numOfProducts)
    {
        cout << "Invalid product number" << endl;
        return;
    }

    PRODUCT &product = order.Products[productNumber - 1];

    // Edit the selected product
    cout << "Enter new product name: ";
    cin >> product.Name;
    cout << "Enter new product category: ";
    cin >> product.Category;
    cout << "Enter new product price: ";
    cin >> product.Price;

    // Validate the new product details
    if (product.Name.empty() || product.Category.empty() || product.Price < 0)
    {
        cout << "Invalid product details. Please enter valid information." << endl;
        return;
    }

    // Update the total price of the order
    updateOrderTotalPrice(order);
}
void updateOrderTotalPrice(ORDER &order)
{
    double sum = 0;
    int orderSize = sizeof(order.Products) / sizeof(order.Products[0]);
    for (int i = 0; i < orderSize; i++)
    {
        sum += order.Products[i].Price;
    }
    order.TotalPrice = sum;
}

// Edit Product Functions
void editProduct(PRODUCT products[])
{
    cout << "Enter the product ID you want to edit : " << endl;
    // TODO function viewProducts()
    // select a product to edit
    int selectedProductID;
    cin >> selectedProductID;

    PRODUCT currentProduct = getProductbyID(selectedProductID, products);

    // select what you want to edit
    cout << "Select what you want to edit" << endl;
    cout << "1. Name" << endl;
    cout << "2. Category" << endl;
    cout << "3. Production Date" << endl;
    cout << "4. Expired Date" << endl;
    cout << "5. Price" << endl;
    int choice;
    cin >> choice;
    int newCode;
    string newName, newCategory;
    DATE newProductionDate, newExpiredDate;
    double newPrice;
    switch (choice)
    {
    case 1:
        // edit the product name
        newName = editProductName(currentProduct.Name);
        currentProduct.Name = newName;
        cout << "Name updated successfully" << endl;
        break;
    case 2:
        // edit the product category
        newCategory = editProductCategory(currentProduct.Category);
        currentProduct.Category = newCategory;
        cout << "Category updated successfully" << endl;
        break;
    case 3:
        // edit the product production date
        newProductionDate = editProductProductionDate(currentProduct.ProductionDate);
        currentProduct.ProductionDate = newProductionDate;
        cout << "Production date updated successfully" << endl;
        break;
    case 4:
        // edit the product expired date
        newExpiredDate = editProductExpiredDate(currentProduct.ExpiredDate);
        currentProduct.ExpiredDate = newExpiredDate;
        cout << "Expired date updated successfully" << endl;
        break;
    case 5:
        // edit the product price
        newPrice = editProductPrice(currentProduct.Price);
        currentProduct.Price = newPrice;
        cout << "Price updated successfully" << endl;
        break;
    case 6:
        // edit the product code
        newCode = editProductCode(currentProduct.Code);
        currentProduct.Code = newCode;
        cout << "Code updated successfully" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "Product saved" << endl;
    // view edited product
    // TODO function viewProductDetails(int productID)
}

// Edit Product Functions

int editProductCode(int productCode)
{
    int newCode;
    cout << "Enter the new code : " << endl;
    cin >> newCode;

    // Validate the new code
    if (newCode < 0)
    {
        cout << "Invalid code. Please enter a positive number." << endl;
        return productCode; // Return the original code if validation fails
    }

    return newCode;
}
string editProductName(string productName)
{
    string newName;
    cout << "Enter the new name : " << endl;
    cin >> newName;

    // Validate the new name
    if (newName.empty())
    {
        cout << "Invalid name. Please enter a non-empty name." << endl;
        return productName; // Return the original name if validation fails
    }

    return newName;
}
string editProductCategory(string productCategory)
{
    string newCategory;
    cout << "Enter the new category : " << endl;
    cin >> newCategory;

    // Validate the new category
    if (newCategory.empty())
    {
        cout << "Invalid category. Please enter a non-empty category." << endl;
        return productCategory; // Return the original category if validation fails
    }

    return newCategory;
}
DATE editProductProductionDate(DATE productProductionDate)
{
    DATE newProductionDate;
    cout << "Enter the new production date : " << endl;
    cout << "Day: ";
    cin >> newProductionDate.Day;
    cout << "Month: ";
    cin >> newProductionDate.Month;
    cout << "Year: ";
    cin >> newProductionDate.Year;

    // Validate the new production date
    if (newProductionDate.Day < 1 || newProductionDate.Day > 31 || newProductionDate.Month < 1 || newProductionDate.Month > 12 || newProductionDate.Year < 1900 || newProductionDate.Year > 2021)
    {
        cout << "Invalid production date. Please enter a valid date." << endl;
        return productProductionDate; // Return the original production date if validation fails
    }

    return newProductionDate;
}
DATE editProductExpiredDate(DATE productExpiredDate)
{
    DATE newExpiredDate;
    cout << "Enter the new expired date : " << endl;
    cout << "Day: ";
    cin >> newExpiredDate.Day;
    cout << "Month: ";
    cin >> newExpiredDate.Month;
    cout << "Year: ";
    cin >> newExpiredDate.Year;

    // Validate the new expired date
    if (newExpiredDate.Day < 1 || newExpiredDate.Day > 31 || newExpiredDate.Month < 1 || newExpiredDate.Month > 12 || newExpiredDate.Year < 1900 || newExpiredDate.Year > 2021)
    {
        cout << "Invalid expired date. Please enter a valid date." << endl;
        return productExpiredDate; // Return the original expired date if validation fails
    }

    return newExpiredDate;
}
double editProductPrice(double productPrice)
{
    double newPrice;
    cout << "Enter the new price : " << endl;
    cin >> newPrice;

    // Validate the new price
    if (newPrice < 0)
    {
        cout << "Invalid price. Please enter a positive number." << endl;
        return productPrice; // Return the original price if validation fails
    }

    return newPrice;
}

// Edit Customer Functions
void editCustomer(CUSTOMER customers[])
{
    cout << "Enter the customer ID you want to edit : " << endl;
    // TODO function viewCustomers()
    // select a customer to edit
    int selectedCustomerID;
    cin >> selectedCustomerID;

    getCustomerbyID(selectedCustomerID, customers);

    // select what you want to edit
    cout << "Select what you want to edit" << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone Number" << endl;
    cout << "3. Location" << endl;
    int choice;
    cin >> choice;
    string newName, newPhoneNumber, newLocation;
    switch (choice)
    {
    case 1:
        // edit the customer name
        newName = editCustomerName(customers[selectedCustomerID].Name);
        customers[selectedCustomerID].Name = newName;
        cout << "Name updated successfully" << endl;
        break;
    case 2:
        // edit the customer phone number
        newPhoneNumber = editCustomerPhoneNumber(customers[selectedCustomerID].PhoneNumber);
        customers[selectedCustomerID].PhoneNumber = newPhoneNumber;
        cout << "Phone number updated successfully" << endl;
        break;
    case 3:
        // edit the customer location
        newLocation = editCustomerLocation(customers[selectedCustomerID].Location);
        customers[selectedCustomerID].Location = newLocation;
        cout << "Location updated successfully" << endl;
        break;
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    cout << "Customer saved" << endl;
    // view edited customer
    // TODO function viewCustomerDetails(int customerID)
}

string editCustomerName(string customerName)
{
    string newName;
    cout << "Enter the new name : " << endl;
    cin >> newName;

    // Validate the new name
    if (newName.empty())
    {
        cout << "Invalid name. Please enter a non-empty name." << endl;
        return customerName; // Return the original name if validation fails
    }

    return newName;
}
string editCustomerPhoneNumber(string customerPhoneNumber)
{
    string newPhoneNumber;
    cout << "Enter the new phone number : " << endl;
    cin >> newPhoneNumber;

    // Validate the new phone number
    if (newPhoneNumber.empty() || newPhoneNumber.length() < 10 || newPhoneNumber.length() > 15)
    {
        cout << "Invalid phone number. Please enter a valid phone number." << endl;
        return customerPhoneNumber; // Return the original phone number if validation fails
    }

    return newPhoneNumber;
}
string editCustomerLocation(string customerLocation)
{
    string newLocation;
    cout << "Enter the new location : " << endl;
    cin >> newLocation;

    // Validate the new location
    if (newLocation.empty())
    {
        cout << "Invalid location. Please enter a non-empty location." << endl;
        return customerLocation; // Return the original location if validation fails
    }

    return newLocation;
}
