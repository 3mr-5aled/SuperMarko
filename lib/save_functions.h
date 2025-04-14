#include <iostream>
#include <fstream>
#include "struct.h"

int save_customers(CUSTOMER customers[])
{
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