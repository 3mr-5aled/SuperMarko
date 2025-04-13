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

using namespace std;

int main()
{
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
		)" << RESET
			 << endl;

		cout << BOLD << GREEN << R"(
		███████╗██╗   ██╗██████╗ ███████╗██████╗     ███╗   ███╗ █████╗ ██████╗ ██╗  ██╗ ██████╗ 
		██╔════╝██║   ██║██╔══██╗██╔════╝██╔══██╗    ████╗ ████║██╔══██╗██╔══██╗██║ ██╔╝██╔═══██╗   
		███████╗██║   ██║██████╔╝█████╗  ██████╔╝    ██╔████╔██║███████║██████╔╝█████╔╝ ██║   ██║
		╚════██║██║   ██║██╔═══╝ ██╔══╝  ██╔══██╗    ██║╚██╔╝██║██╔══██║██╔══██╗██╔═██╗ ██║   ██║
		███████║╚██████╔╝██║     ███████╗██║  ██║    ██║ ╚═╝ ██║██║  ██║██║  ██║██║  ██╗╚██████╔╝
		╚══════╝ ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ 
		                                                              made by: real developers
		)" << RESET
			 << endl;

		int flag = menu_logging_in(customers, numOfCustomers, myfile, id);

		if (!flag)
		{
			exitProgram = true;
			break;
		}

		char number;
		char choice;
		bool loggedIn = true;

		while (loggedIn)
		{
			number = bigmenu();
			switch (number)
			{
			case '1':
				cout << CYAN << "\nYou selected: Edit your information\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				editUserInformation(customers, id, numOfCustomers);
				choice = 'y';
				continue;
			case '2':
				cout << CYAN << "\nYou selected: View product menu\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				Categories(product, numOfCategories, numOfProducts);
				choice = 'y';
				continue;

			case '3':
				cout << CYAN << "\nYou selected: Add goods\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case '4':
				cout << CYAN << "\nYou selected: Review your order\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case '5':
				cout << CYAN << "\nYou selected: Modify your order\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;

				break;
			case '6':
				cout << CYAN << "\nYou selected: View total price\n"
					 << RESET;
				cout << "═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════\n";
				cout << endl;
				break;
			case '0':
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
				cout << YELLOW << "Do you want another operation? (y/n): " << RESET;
				cin >> choice;
				if (choice != 'y' && choice != 'Y')
				{
					loggedIn = false;
					id = 0;
				}
			}
		}
	}

	myfile.close(); // Close read file

	ofstream outFile("customers.txt", ios::out | ios::trunc);
	if (!outFile.is_open())
	{
		cout << RED << "Error: Could not write to customers.txt" << RESET << endl;
		return 1;
	}

	for (int i = 0; i < numOfCustomers; i++)
	{
		if (customers[i].ID == 0)
			continue;
		outFile << customers[i].ID << '\n';
		outFile << customers[i].Name << '\n';
		outFile << customers[i].PhoneNumber << '\n';
		outFile << customers[i].Location << '\n';
		outFile << customers[i].Password << '\n';
	}

	outFile.close();

	return 0;
}