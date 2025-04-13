#include <iostream>
#include<fstream>
#include <string>
#include "struct.h"
using namespace std;


void read_product_from_file(PRODUCT product[CATEGORY][NUMBEROFPRODUCT],const int CATEGORY,const int NUMBEROFPRODUCT)
{
	fstream myfile;
	myfile.open("productmenu.txt", ios::in);
	if (!myfile)
	{
		cout << "Error: Could not open product file!\n";
		return;
	}
	for (int categoryIndex = 0; categoryIndex < CATEGORY; categoryIndex++)
	{
		for (int numberOfProductIndex = 0; numberOfProductIndex < NUMBEROFPRODUCT; numberOfProductIndex++)
		{
			myfile >> product[categoryIndex][numberOfProductIndex].Code;
			myfile >> product[categoryIndex][numberOfProductIndex].Name;
			myfile >> product[categoryIndex][numberOfProductIndex].Category;
			myfile >> product[categoryIndex][numberOfProductIndex].ProductionDate.Day;
			myfile >> product[categoryIndex][numberOfProductIndex].ProductionDate.Month;
			myfile >> product[categoryIndex][numberOfProductIndex].ProductionDate.Year;
			myfile >> product[categoryIndex][numberOfProductIndex].ExpiredDate.Day;
			myfile >> product[categoryIndex][numberOfProductIndex].ExpiredDate.Month;
			myfile >> product[categoryIndex][numberOfProductIndex].ExpiredDate.Year;
			myfile >> product[categoryIndex][numberOfProductIndex].Price;
		}
	}
	myfile.close();
}


void read_customer_from_file(CUSTOMER customers[], const int numerofcustomers,fstream &myfile){
    
	myfile.clear(); // clear any flags
    myfile.seekg(0); // move to beginning of file

    for (int i = 0; i < numerofcustomers; i++) {
        if (!(myfile >> customers[i].ID)) break;
        myfile.ignore();
        getline(myfile, customers[i].Name);
        myfile >> customers[i].PhoneNumber;
        myfile.ignore();
        getline(myfile, customers[i].Location);
        myfile >> customers[i].Password;
    }
}