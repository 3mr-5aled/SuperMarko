#include "struct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void addProducts(ORDER order[numOfCustomers], PRODUCT product[numOfCategories][numOfProducts], int &id, int CategoryCase, bool &returnToCategoryMenu)
{
    int number;
    string productInput;
    char answerofproduct;
    double amount;
    order[id - 1].CustomerID = id;
    int i = order[id - 1].productcount;
    do
    {
        cout << YELLOW << "Please choose a product by entering a number between 1 and 10.\n"
             << RESET;
        cout << YELLOW << "Enter 0 to return to categories.\n"
             << RESET;
        cin >> productInput;

        if ((productInput.length() == 1 && isdigit(productInput[0])))
        {
            number = productInput[0] - '0';
        }
        else if (productInput == "10")
        {
            number = 10;
        }
        else
        {
            cout << RED << "Invalid input. Please enter a valid number.\n"
                 << RESET;
            continue;
        }

        if (number == 0)
        {
            cout << BLUE << "Returning to category menu...\n"
                 << RESET;
            returnToCategoryMenu = true;
            break;
        }

        if (!(number >= 1 && number <= 10))
        {
            cout << RED << "There is no choice like this.\n"
                 << RESET;
            answerofproduct = 'y';
            continue;
        }
        cout << "How many amount do you want?\n";
        cin >> amount;
        order[id - 1].Amount[i] = amount;
        cout << GREEN << "Do you want to choose another product? (y/n)\n"
             << RESET;
        cin >> answerofproduct;

        order[id - 1].Products[i] = product[CategoryCase - 1][number - 1];

        order[id - 1].Products[i].Price = (product[CategoryCase - 1][number - 1].Price) * (order[id - 1].Amount[i]);
        order[id - 1].TotalPrice += order[id - 1].Products[i].Price;
        order[id - 1].productcount++;
        i++;
    } while (answerofproduct == 'y' || answerofproduct == 'Y');
}
void ReviewOrder(ORDER order[numOfCustomers], int &id)
{
    if (order[id - 1].productcount == 10)
    {
        cout << "CAn't add more \n";
        return;
    }

    cout << "\n";
    cout << "|                                ORDER CHEQUE                                 |\n";
    cout << "\n";
    cout << "|  No.  |     Product Name     |  Quantity  |   Price   |\n";
    cout << "-------------------------------------------------------------------------------\n";

    for (int i = 0; i < order[id - 1].productcount; i++)
    {

        cout << "|  " << setw(4) << i + 1 << " | ";
        cout << setw(20) << order[id - 1].Products[i].Name << " | ";
        cout << setw(9) << order[id - 1].Amount[i] << " | ";
        cout << setw(8) << fixed << setprecision(2) << order[id - 1].Products[i].Price << " |\n";
    }
    cout << "-------------------------------------------------------------------------------\n";
    cout << "TOTAL: " << fixed << setprecision(2) << order[id - 1].TotalPrice << " EGP\n";
}
