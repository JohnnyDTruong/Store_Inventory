/*
	Jonathan Truong
	CPSC 121-19
	Assignment 2 - Object Oriented Programming (Inventory Managment System)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Items
{
	//public members can be used by functions outside of the class
	public:
	string name;
	int PMid;
	double RetailVal;
	double Quantity;
	double discount = 1.0;

	//prints out a discounted list of the 4 items
	void print()
	{
		cout << Quantity << ' ' << name << " left in stock at $" << RetailVal * (1.0 - discount)
			<< ' ' << " item id " << PMid;
	}

	//prints out a list of the 4 items
	void printprice()
	{
		cout << Quantity << ' ' << name << " left in stock at $" << RetailVal
			<< ' ' << " item id " << PMid;
	}
};

int main()
{
	cout << fixed << setprecision(2);

	//Initializes inventory, the items name, the quantity available,
	//the ID, and the retail value
	Items inventory[4];
	string item_name;
	int qAvail, ID;
	double retail_value;

	cout << "===Welcome to the inventory helper===" << endl;
	cout << "-store hours will begin shortly" << endl;
	cout << "Please update your inventory..." << endl;

	//this allows the user to enter the items
	//this provides the user to add in the product's name, Production
	//manufacturer's ID, retail price, and the quantity available
	for (int i = 0; i < 4; ++i)
	{
		cout << "Enter item " << i + 1 << " to add to inventory" << endl;
		cout << "Please enter the product name. " << endl;
		cin >> item_name;
		inventory[i].name = item_name;
		cout << "Enter product manufacturer's id." << endl;
		cin >> ID;
		inventory[i].PMid = ID;
		cout << "Enter the retail value" << endl;
		cin >> retail_value;
		inventory[i].RetailVal = retail_value;
		cout << "Enter quantity available" << endl;
		cin >> qAvail;
		inventory[i].Quantity = qAvail;
	}

	//this prints out the product's name, Production
	//manufacturer's ID, retail price, and the quantity available for all
	//4 items
	for (int i = 0; i < 4; ++i)
	{
		cout << '\n' << endl;
		inventory[i].printprice();
		cout << '\n' << endl;
	}

	char user_input = ' ';
	int sold_items = 0;
	int item_choice = 0;
	int item_quantity = 0;

	cout << "Business hours are now open" << endl;

	//this allows the user to make a transaction by choosing 'y' or 'n'
	do
	{
		cout << "Would you like to perform a transaction? (y/n)" << endl;
		cin >> user_input;

		//if the user chooses 'y' then they continue on
		if (user_input != 'y')
		{
			continue;
		}

		cout << "====Menu====" << endl;
		cout << "Enter which item you would like to purchase " << endl;

		//this prints out all the items available
		for (int i = 0; i < 4; ++i)
		{
			cout << i + 1 << ". ";
			inventory[i].printprice();
			cout << "\n" << endl;
		}

		cin >> item_choice;
		cout << "How many would you like to buy?" << endl;
		cin >> item_quantity;

		//The condition below is done for making sure that you don't put
		//more than you have
		//"make sure item_quantity from user is less than the quantity on hand"
		do
		{
			if (item_quantity > inventory[item_choice - 1].Quantity)
			{
				cout << "Not enough " << inventory[item_choice - 1].name << endl;
				cout << " in stock " << "(" << inventory[item_choice - 1].Quantity << ")" << " total stock" << endl;
				cout << "Enter new amount " << endl;
				cin >> item_quantity;
			}
		} while (item_quantity > inventory[item_choice - 1].Quantity);

		inventory[item_choice - 1].Quantity -= item_quantity;

		sold_items++;
		cout << "SOLD " << item_quantity << " " << inventory[item_choice - 1].name << " for $"
			<< inventory[item_choice - 1].RetailVal * item_quantity << endl;
	} while (user_input == 'y');
	cout << sold_items << " items sold.\n" << endl;
	cout << "Sale starting!!!" << endl;

	//this is where the discount option will be made
	double discount = 1.0;
	//this will ask for the discount
	cout << "Would you like to enter a discount %? (y/n)" << endl;
	cin >> user_input;

	//this allows the user to enter the custom discount
	if (user_input == 'y')
	{ 
	cout << "Enter the custom discount percentage." << endl;
	cin >> discount;
	}

	//this applies the discount to the items retail prices
	for (int i = 0; i < 4; ++i)
	{
		inventory[i].discount = discount;
	}
	//this prints out all the items left including the
	//new sales price from the discount
	for (int i = 0; i < 4; ++i)
	{
		cout << "Price for " << inventory[i].name << " on sale for $" <<
			inventory[i].RetailVal * (1 - discount);
		cout << '\n' << endl;
	}

	//this allows the user to perform another transaction
	//but this one is for the discounted items
	do
	{
		cout << "Would you like to perform another transaction? (y/n)" << endl;
		cin >> user_input;

		//continues if 'y' is chosen
		if (user_input != 'y')
		{
			continue;
		}

		cout << "====Menu====" << endl;
		cout << "Enter which item you would like to purchase " << endl;

		//prints out the discounted items
		for (int i = 0; i < 4; ++i)
		{
			cout << i + 1 << ". ";
			inventory[i].print();
			cout << "\n" << endl;
		}

		cin >> item_choice;
		cout << "How many would you like to buy?" << endl;
		cin >> item_quantity;

		//this does not allow the user to buy any of the 4 products
		//pass the limit of the stock for each product
		//it allows the user to enter a new amount after
		do
		{
			if (item_quantity > inventory[item_choice - 1].Quantity)
			{
				cout << "Not enough " << inventory[item_choice - 1].name << endl;
				cout << " in stock " << "(" << inventory[item_choice - 1].Quantity << ")" << " total stock" << endl;
				cout << "Enter new amount " << endl;
				cin >> item_quantity;
			}

			//The condition below is done for making sure that you don't put
			//more than what you have
			// "make sure item_quantity from user is less than the quantity on hand"
		} while (item_quantity > inventory[item_choice - 1].Quantity);

		inventory[item_choice - 1].Quantity -= item_quantity;

		//prints out the amount of items sold
		sold_items++;
		cout << "SOLD " << item_quantity << " " << inventory[item_choice - 1].name << " for $"
			<< inventory[item_choice - 1].RetailVal * item_quantity * (1 - discount) << endl;
	} while (user_input == 'y');

	//closing shop -- inventory left
	//this shows the closing shop
	//this shows the amount of inventory left
	cout << "\n" << endl;
	cout << "Closing Shop -- inventory left" << endl;
	for (int i = 0; i < 4; i++)
	{
		inventory[i].print();
		cout << '\n' << endl;
	}

	system("PAUSE");
	return 0;
}
/*
===Welcome to the inventory helper===
-store hours will begin shortly
Please update your inventory...
Enter item 1 to add to inventory
Please enter the product name.
Milk
Enter product manufacturer's id.
6019
Enter the retail value
4.65
Enter quantity available
11
Enter item 2 to add to inventory
Please enter the product name.
Cookies
Enter product manufacturer's id.
4118
Enter the retail value
2.49
Enter quantity available
40
Enter item 3 to add to inventory
Please enter the product name.
TeaBags
Enter product manufacturer's id.
8934
Enter the retail value
1.05
Enter quantity available
23
Enter item 4 to add to inventory
Please enter the product name.
Donuts
Enter product manufacturer's id.
0031
Enter the retail value
.68
Enter quantity available
15


11.00 Milk left in stock at $4.65  item id 6019



40.00 Cookies left in stock at $2.49  item id 4118



23.00 TeaBags left in stock at $1.05  item id 8934



15.00 Donuts left in stock at $0.68  item id 31

Business hours are now open
Would you like to perform a transaction? (y/n)
y
====Menu====
Enter which item you would like to purchase
1. 11.00 Milk left in stock at $4.65  item id 6019

2. 40.00 Cookies left in stock at $2.49  item id 4118

3. 23.00 TeaBags left in stock at $1.05  item id 8934

4. 15.00 Donuts left in stock at $0.68  item id 31

1
How many would you like to buy?
14
Not enough Milk
 in stock (11.00) total stock
Enter new amount
2
SOLD 2 Milk for $9.30
Would you like to perform a transaction? (y/n)
y
====Menu====
Enter which item you would like to purchase
1. 9.00 Milk left in stock at $4.65  item id 6019

2. 40.00 Cookies left in stock at $2.49  item id 4118

3. 23.00 TeaBags left in stock at $1.05  item id 8934

4. 15.00 Donuts left in stock at $0.68  item id 31

2
How many would you like to buy?
7
SOLD 7 Cookies for $17.43
Would you like to perform a transaction? (y/n)
n
2 items sold.

Sale starting!!!
Would you like to enter a discount %? (y/n)
y
Enter the custom discount percentage.
.40
Price for Milk on sale for $2.79

Price for Cookies on sale for $1.49

Price for TeaBags on sale for $0.63

Price for Donuts on sale for $0.41

Would you like to perform another transaction? (y/n)
y
====Menu====
Enter which item you would like to purchase
1. 9.00 Milk left in stock at $2.79  item id 6019

2. 33.00 Cookies left in stock at $1.49  item id 4118

3. 23.00 TeaBags left in stock at $0.63  item id 8934

4. 15.00 Donuts left in stock at $0.41  item id 31

3
How many would you like to buy?
12
SOLD 12 TeaBags for $7.56
Would you like to perform another transaction? (y/n)
n


Closing Shop -- inventory left
9.00 Milk left in stock at $2.79  item id 6019

33.00 Cookies left in stock at $1.49  item id 4118

11.00 TeaBags left in stock at $0.63  item id 8934

15.00 Donuts left in stock at $0.41  item id 31

Press any key to continue . . .
*/