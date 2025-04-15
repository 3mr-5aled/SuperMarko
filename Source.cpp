#include <iostream>
#include <string>
#include <fstream>
#include "lib/struct.h"
#include "lib/menu_functions.h"
#include "lib/registeration.h"
#include "lib/edit_functions.h"
#include "lib/addtional_features.h"
#include "lib/read_functions.h"
#include "lib/get_functions.h"
#include "lib/save_functions.h"

using namespace std;

int main()
{
	// Set the console to UTF-8 encoding
	// This is important for displaying Unicode characters correctly
	// system("chcp 65001 > nul");

	fstream myfile("customers.txt", ios::in | ios::out);
	if (!myfile.is_open())
	{
		cout << RED << "Error opening the file." << RESET << endl;
		return 1;
	}

	read_product_from_file(product, numOfCategories, numOfProducts);
	read_customer_from_file(customers, numOfCustomers, myfile);

	int id = 0;
	bool exitProgram = false;

	while (!exitProgram)
	{
		cout << "\n═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
		cout << ORANGE << R"(

		⠀⠀⠈⠛⠻⠶⣶⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠈⢻⣆⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⢻⡏⠉⠉⠉⠉⢹⡏⠉⠉⠉⠉⣿⠉⠉⠉⠉⠉⣹⠇⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠈⣿⣀⣀⣀⣀⣸⣧⣀⣀⣀⣀⣿⣄⣀⣀⣀⣠⡿⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⠀⠀⠀⢸⡇⠀⠀⠀⠀⣿⠁⠀⠀⠀⣿⠃⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⣤⣤⣼⣧⣤⣤⣤⣤⣿⣤⣤⣤⣼⡏⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⠀⠀⢸⡇⠀⠀⠀⠀⣿⠀⠀⢠⡿⠀⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣷⠤⠼⠷⠤⠤⠤⠤⠿⠦⠤⠾⠃⠀⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⣷⢶⣶⠶⠶⠶⠶⠶⠶⠶⣶⠶⣶⡶⠀⠀⠀⠀⠀⠀
		⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣧⣠⡿⠀⠀⠀⠀⠀⠀⢷⣄⣼⠇⠀⠀⠀⠀⠀⠀⠀

		Welcome to the Grocery Store Management System
		)" << RESET;
		cout << BOLD << TEAL <<
			R"(███████╗██╗   ██╗██████╗ ███████╗██████╗     ███╗   ███╗ █████╗ ██████╗ ██╗  ██╗ ██████╗ 
		██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗    ████╗ ████║██╔══██╗██╔══██╗██║ ██╔╝██╔═══██╗   
		███████╗██║   ██║██████╔╝█████╗  ██████╔╝    ██╔████╔██║███████║██████╔╝█████╔╝ ██║   ██║
		╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗    ██║╚██╔╝██║██╔══██║██╔══██╗██╔═██╗ ██║   ██║
		███████║╚██████╔╝██║     ███████╗██║  ██║    ██║ ╚═╝ ██║██║  ██║██║  ██║██║  ██╗╚██████╔╝
		╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ 
		                                                              made by: real developers🧑🏻‍💻
		)" << RESET
			 << endl;

		int flag = menu_logging_in(customers, numOfCustomers, myfile, id);

		if (!flag)
		{
			exitProgram = true;
			break;
		}

		int number;
		char choice;
		bool loggedIn = true;

		while (loggedIn)
		{
			number = bigmenu();
			switch (number)
			{
			case 1:
				cout << CYAN << "\nYou selected: Edit your information\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				editUserInformation(customers, id, numOfCustomers);
				choice = 'y';
				continue;
			case 2:
				cout << CYAN << "\nYou selected: View product menu\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				Categories(product, numOfCategories, numOfProducts);
				choice = 'y';
				continue;

			case 3:
				cout << CYAN << "\nYou selected: Add goods\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case 4:
				cout << CYAN << "\nYou selected: Review your order\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case 5:
				cout << CYAN << "\nYou selected: Modify your order\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case 6:
				cout << CYAN << "\nYou selected: View total price\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				break;
			case 0:
				cout << RED << "\nLogging out...\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				id = 0;
				loggedIn = false;
				break;
			default:
				cout << RED << "\nInvalid input, please enter a number between 1 and 6.\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				choice = 'y';
				continue;
			}
			if (loggedIn)
			{
				while (true)
				{
					cout << YELLOW << "Do you want another operation? (y/n): " << RESET;
					cin >> choice;

					if (choice == 'y' || choice == 'Y')
					{
						// valid, continue with operations
						break;
					}
					else if (choice == 'n' || choice == 'N')
					{
						loggedIn = false;
						id = 0;
						break;
					}
					else
					{
						cout << RED << "Invalid choice! Please enter 'y' or 'n'." << RESET << endl;
					}
				}
						}
		}
	}

	myfile.close(); // Close read file

	save_customers(customers);

	return 0;
}