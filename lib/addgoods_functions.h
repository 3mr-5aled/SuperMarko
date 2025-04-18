#include <iostream>
#include "struct.h"
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void addProducts (ORDER order[numOfCustomers],PRODUCT product[numOfCategories][numOfProducts],int& id,int CategoryCase,bool& returnToCategoryMenu ){
    int number;
			string productInput;
			char answerofproduct;
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

				cout << GREEN << "Do you want to choose another product? (y/n)\n"
					 << RESET;
				cin >> answerofproduct;

			} while (answerofproduct == 'y' || answerofproduct == 'Y');
		}
		else if (numberofcategory == 0)
		{
			return;
		}
		else
		{
			cout << RED << "\nInvalid input, please enter a number between 1 and 10.\n"
				 << RESET;
			continue;
		}

		if (returnToCategoryMenu)
			continue;

		cout << GREEN << "Do you want to continue? (y/n)" << RESET << endl;
		cin >> choice;

		if (choice == 'n' || choice == 'N')
		{
			return;
		}
		else if (choice == 'y' || choice == 'Y')
		{
			continue;
		}
		else
		{
			while (true)
			{
				cout << RED << "\nInvalid input, please enter 'y' or 'n'.\n"
					 << RESET;
				cout << YELLOW << "Do you want to continue? (y/n): " << RESET;
				cin >> choice;

				if (choice == 'y' || choice == 'Y')
				{
					break;
				}
				else if (choice == 'n' || choice == 'N')
				{
					return;
				}
			}
		}
	


