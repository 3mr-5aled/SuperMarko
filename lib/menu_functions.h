#include "struct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int CATEGORY = 10;
const int NUMBEROFPRODUCT = 10;

int bigmenu()
{
	string input;
	int number;
	while (true)
	{
		cout << BOLD << CYAN;
		cout << "            =============================================\n";
		cout << "                        # WELCOME TO OUR SYSTEM #        \n";
		cout << "            =============================================\n";
		cout << RESET << endl;

		cout << "\n";
		cout << "\n";
		cout << GREEN << "*  Press (1) to edit your information.                                   *\n";
		cout << "*  Press (2) to view your product menu.                                  *\n";
		cout << "*  Press (3) to add goods.                                               *\n";
		cout << "*  Press (4) to review your order.                                       *\n";
		cout << "*  Press (5) to modify your order.                                       *\n";
		cout << "*  Press (6) to view your total price.                                   *\n";
		cout << "*  Press (0) to log out.                                                 *\n";
		cout << RESET << "\n";
		cout << "\n";
		cout << YELLOW << "Please enter the number you want to choose from the above list (1-6): " << RESET;

		cin >> input;
		if (input.length() == 1 && isdigit(input[0]))
		{
			number = input[0] - '0';
			if (number >= 0 && number <= 6)
				return number;
			else
				cout << RED << "\nInvalid input, number must be between 0 and 6.\n"
					 << RESET;
		}
		else
		{
			cout << RED << "\nINVALID CHOICE. Please enter a valid number.\n"
				 << RESET;
		}
	}

	return number;
}

void Categories(PRODUCT product[CATEGORY][NUMBEROFPRODUCT], const int CATEGORY, const int NUMBEROFPRODUCT)
{
	int numberofcategory;
	char choice;
	string input;
	while (true)
	{
		bool returnToCategoryMenu = false;
		cout << endl;
		cout << BOLD << BLUE << "\n========= SUPERMARKET CATEGORIES =========\n"
			 << RESET;
		cout << GREEN << "1.  Fresh Produce (fruits)\n";
		cout << "2.  Fresh Produce (vegetable)\n";
		cout << "3.  Dairy & Eggs\n";
		cout << "4.  Butcher Shop\n";
		cout << "5.  Seafood\n";
		cout << "6.  Poultry\n";
		cout << "7.  Bakery & Bread\n";
		cout << "8.  Snacks & Sweets\n";
		cout << "9.  Household & Cleaning Supplies\n";
		cout << "10. Pet Supplies\n";
		cout << "0. Return to big menu.\n"
			 << RESET;
		cout << BOLD << BLUE << "===========================================\n"
			 << RESET;
		cout << YELLOW << "Please enter the category number: " << RESET;

		cin >> input;
		if ((input.length() == 1 && isdigit(input[0])))
		{
			numberofcategory = input[0] - '0';
		}
		else if (input == "10")
		{
			numberofcategory = 10;
		}
		else
		{
			cout << RED << "\nInvalid input, please enter a number between 0 and 10.\n"
				 << RESET;
			continue;
		}

		if (numberofcategory > 0 && numberofcategory < 11)
		{
			cout << PURPLE << "\n\t\t\t    You selected: " << product[numberofcategory - 1][0].Category << " of category.\n"
				 << RESET;

			cout << "******************************************************************************************\n";
			cout << "|                                      PRODUCT LIST                                     |\n";
			cout << "******************************************************************************************\n";
			cout << "|  No.  |        Name        |   Code    | Production Date | Expired Date  |   Price    |\n";
			cout << "------------------------------------------------------------------------------------------\n";

			for (int numberOfProductIndex = 0; numberOfProductIndex < NUMBEROFPRODUCT; numberOfProductIndex++)
			{
				if (!product[numberofcategory - 1][numberOfProductIndex].Code.empty())
				{
					cout << CYAN;
					cout << "|  " << setw(2) << numberOfProductIndex + 1 << "   | ";
					cout << left << setw(18) << product[numberofcategory - 1][numberOfProductIndex].Name << " | ";
					cout << setw(9) << product[numberofcategory - 1][numberOfProductIndex].Code << " |   ";
					cout << right << setw(2) << setfill('0') << product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Day << "-"
						 << setw(2) << setfill('0') << product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Month << "-"
						 << setw(4) << setfill(' ') << product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Year << "    |  ";
					cout << setw(2) << setfill('0') << product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Day << "-"
						 << setw(2) << setfill('0') << product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Month << "-"
						 << setw(4) << setfill(' ') << product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Year << "   | ";
					cout << right << setw(6) << product[numberofcategory - 1][numberOfProductIndex].Price << " EGP |\n";
					cout << RESET;
					cout << "------------------------------------------------------------------------------------------\n";
				}
			}

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
	}
}
