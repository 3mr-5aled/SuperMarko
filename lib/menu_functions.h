#include "struct.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
const int  CATEGORY = 10;
const int  NUMBEROFPRODUCT = 10;



char bigmenu()
{
	char number;



	cout << "            =============================================\n";
	cout << "                        # WELCOME TO OUR SYSTEM #        \n";
	cout << "            =============================================\n";
	cout << endl;

	cout << "\n";
	cout << "\n";
	cout << "*  press (1) to edit your information.                                   * \n";
	cout << "*  press (2) to view your product menu.                                  * \n";
	cout << "*  press (3) to add goods.                                               * \n";
	cout << "*  press (4) to review your order.                                       * \n";
	cout << "*  press (5) to modify your order.                                       *\n";
	cout << "*  press (6) to view your total price.                                   * \n";
	cout << "*  press (7) to log out.                                                 * \n";
	cout << "\n";
	cout << "\n";
	cout << "Please enter the number  you want to choose from the  above list (1-7) :";

	cin >> number;


	return number;

}



void Categories(PRODUCT product[CATEGORY][NUMBEROFPRODUCT],const int CATEGORY,const int NUMBEROFPRODUCT) {
	int numberofcategory;
	char choice;
	while (true) {
		cout << endl;
		cout << "\n========= SUPERMARKET CATEGORIES =========\n";
		cout << "1. Fresh Produce (fruits)\n";
		cout << "2. Fresh Produce (vegetable)\n";
		cout << "3. Dairy & Eggs\n";
		cout << "4. Butcher Shop\n";
		cout << "5. Seafood\n";
		cout << "6. Poultry\n";
		cout << "7. Bakery & Bread\n";
		cout << "8. Snacks & Sweets\n";
		cout << "9. Household & Cleaning Supplies\n";
		cout << "10.Pet Supplies\n";
		cout << "11.Return to big menu.\n";
		cout << "===========================================\n";
		cout << "Please enter the category number: ";

		cin >> numberofcategory;

		if (numberofcategory > 0 && numberofcategory < 11)
		{
			cout << "\n\t\t\t\tYou selected : " << product[numberofcategory - 1][0].Category << " of category.\n";
			cout << "\t\t\t\t**";
			cout << endl;
			cout << endl;
			for (int numberOfProductIndex = 0; numberOfProductIndex < NUMBEROFPRODUCT; numberOfProductIndex++)
			{
				if (!product[numberofcategory - 1][numberOfProductIndex].Code.empty())
				{
					cout << "Number of product:" << numberOfProductIndex + 1 << " \t|";
					cout << "Name: " << product[numberofcategory - 1][numberOfProductIndex].Name << "  \t|";
					
					cout << "Code: " << product[numberofcategory - 1][numberOfProductIndex].Code << endl;
					

					cout << "Production Date: " << product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Day << "-"
						<< product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Month << "-"
						<< product[numberofcategory - 1][numberOfProductIndex].ProductionDate.Year << " \t|";

					cout << "Expired Date: " << product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Day << "-"
						<< product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Month << "-"
						<< product[numberofcategory - 1][numberOfProductIndex].ExpiredDate.Year << " \t|";


					cout << "Price : " << product[numberofcategory - 1][numberOfProductIndex].Price << " EGP/Kg" << endl;
					cout << "\t================================================================\n";
				}
			}
			int number;
			char answerofproduct;
			do
			{
				cout << "Please choose a product by entering a number betwen 1 and 10.\n";
				cin >> number;
                if (!(number >=1 && number <= 10))
                {
                    cout<<"there is no choice like this"<<endl;
                    answerofproduct ='y';
                    continue;
                }
                

				cout << "Do you want choose another product?\n";
				cin >> answerofproduct;
			} while (answerofproduct=='y'||answerofproduct=='Y');

		}
		else if (numberofcategory == 11)
		{
			return;
		}
		else
		{
			cout << "\nInvalid input, please enter a number between 1 and 10.\n";
			continue;
		}

		cout << "Do you want to continue? (y/n)" << endl;
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
				cout << "\nInvalid input, please enter 'y' or 'n'.\n";
				cout << "Do you want to continue? (y/n): ";
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

