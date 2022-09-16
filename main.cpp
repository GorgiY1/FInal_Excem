#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include<ctime>

#include "Card.h"
#include "Product.h"
#include "Client.h"
#include "Company.h"

#include"Order.h"
#include"Ordinary_order.h"
#include"Express_Order.h"
#include"Order_exceptions.h"

#include"All_orders.h"


using namespace std;

int Order :: amount = 0;
int Product::amount = 0;

int main()
{
	setlocale(0, "ru");
	srand(time(0));

	/*Card privat(5000);
	privat.show_card();*/
	try
	{
		//temporary variables for app
		

		int number = 0;
		Date order_date = Date(0, 0, 0);
		Time order_time = Time(0, 0, 0);
		string description = "";
		float price = 0;
		string courier = "";
		int days_to_deliver = 0;
		string name_company = "";
		float money_amount = 0;

		string type = "";

		int menu = 0;
		int type_menu = 0;

		Card privat(20000);
		Card privat_company(0);

		Company comp1("Rozetca", privat_company, 681524856);
		
		Product p1("computer", 30000, 7);
		Product p2("cable", 250, 1);
		Product p3("monitor", 4000, 4);
		Product p4("keyboard", 450, 1);

		comp1.add_product_to_company(&p1);
		comp1.add_product_to_company(&p2);
		comp1.add_product_to_company(&p3);
		comp1.add_product_to_company(&p4);
		

		cout << "Input your name: ";
		cin >> description; // This is name of client
		cout << "Input your phone number: ";
		cin >> number;
		cout << endl;


		Client cl1(description, privat, number);
		Client cl2("Clarck", privat, number);
		cl2.set_all_sum(2150);
		Client cl3("Kara", privat, number);
		cl3.set_all_sum(1556);

		cout << "Select products for buy: \n";
		comp1.show_products_of_company();

		do
		{
			cout << "1. Show company products: \n";
			cout << "2. Select products for buy: \n";
			cout << "3. Show cliet data and selected products: \n";
			cout << "4. Send money to company:\n";
			cout << "5. Show card client:\n";
			cout << "6. Show card company:\n";
			cout << "0. Exit\n";

			cin >> type_menu;

			/*Product tmp_prod;

			switch (type_menu)
			{
			case 1:
				comp1.show_products_of_company();
				break;
			case 2:
				cout << "input name product: ";
				cin.ignore();
				getline(cin, courier);

				tmp_prod = comp1.del_prod(courier);
				cl1.add_product_to_shopping_cart(&tmp_prod);
				cl1.show_cliet();
				cl1.show_products_of_client();
				break;
			case 3:
				cl1.show_cliet();
				cl1.show_products_of_client();
				break;
			case 4:
				cl1.send_money(privat_company);
				break;
			default:
				break;
			}*/


			if (type_menu == 1)
			{
				comp1.show_products_of_company();
			}
			if (type_menu == 2)
			{
				cout << "input name product: ";
				cin.ignore();
				cin >> courier;

				Product tmp_prod = comp1.del_prod(courier);
				cl1.add_product_to_shopping_cart(new Product(tmp_prod.get_name(), tmp_prod.get_price(), tmp_prod.get_weight()));
				cl1.show_cliet();
				cl1.show_products_of_client();
			}
			if (type_menu == 3)
			{
				cl1.show_cliet();
				cl1.show_products_of_client();
			}
			if (type_menu == 4)
			{
				privat.spend_cash(cl1.get_all_sum());
				cl1.send_money(privat_company);
			}
			if (type_menu == 5)
			{
				privat.show_card();
			}
			if (type_menu == 6)
			{
				privat_company.show_card();
			}

			/*cl1.show_cliet();
			cl1.show_products_of_client();*/

		} while (type_menu != 0);

	All_orders allOrd;

	Ordinary_order ord(Date(2022, 10, 18), Time(8, 59, 3), "electronica", cl1);
	allOrd.add_order(&ord);
	Express_Order d(Date(2022, 11, 5), Time(10, 57,3), "eat", "pit", 2, cl2);
	Insured_order d2(Date(2022, 12, 2), Time(6, 56, 3), "devices", "MeastExcpress", 500, cl3);
	allOrd.add_order(&d);
	allOrd.add_order(&d2);

	/*Ordinary_order ord(Date(2025, 12, 18), Time(18, 59, 5), "ajhf", 85);
		ord.set_description("kjhf");
		ord.show();
		allOrd.add_order(&ord);*/

	
	do
	{
		cout << "1. Add order: \n";
		cout << "2. Show all orders: \n";
		cout << "3. Search the order by fields: \n";
		cout << "4. Sort orders by fields:\n";
		cout << "5. Deleting orders by fields:\n";
		cout << "6. Save to file:\n";
		cout << "7. Load from file:\n";

		/*cout << "6. show all users\n";
		cout << "7. Get edition\n";*/
		cout << "0. Exit\n";
		cin >> menu;

		switch (menu)
		{
		case 1:

			cout << "input type Ordinary_order, Express_Order, or Insured_order for addind: ";
			cin >> type;

			cout << "\ninput date: ";
			cin >> order_date;
			cout << "\ninput time: ";
			cin >> order_time;
			cout << "\ninput description: ";
			cin.ignore();
			getline(cin, description);
		
			if (type == "Ordinary_order")
			{
				allOrd.add_order(new Ordinary_order(order_date, order_time, description,cl1));
				allOrd.show_syst();
				break;
			}
			if (type == "Express_Order")
			{
				cout << "\ninput courier name: ";
				cin >> courier;
				cout << "\ninput days_to_deliver: ";
				cin >> days_to_deliver;

				allOrd.add_order(new Express_Order(order_date, order_time, description, courier, days_to_deliver,cl1));
				allOrd.show_syst();
				break;
			}
			if (type == "Insured_order")
			{
				string name_company = "";
				float money_amount = 0;
				cout << "\ninput name_company: ";
				cin >> name_company;
				cout << "\n money_amount: ";
				cin >> money_amount;

				allOrd.add_order(new Insured_order(order_date, order_time, description, name_company, money_amount,cl1));
				allOrd.show_syst();
				break;
			}
		case 2:
			allOrd.show_syst();
			break;
		case 3:
			do
			{
				cout << "1. search_by_date: \n";
				cout << "2. search_by_time: \n";
				cout << "3. search_by_description: \n";
				cout << "4. search_by_price: \n";
				cout << "5. search_by_courier: \n";
				cout << "6. search_by_days_to_deliver: \n";
				cout << "7. search_by_name_company: \n";
				cout << "8. search_by_days_money_amount: \n";
				cout << "9. search_by_type: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					cout << "Input search date: \n";
					cin >> order_date;
					allOrd.search_by_date(order_date);
					type_menu = 0;
					break;
				case 2:
					cout << "Input search time: \n";
					cin >> order_time;
					allOrd.search_by_time(order_time);
					type_menu = 0;
					break;
				case 3:
					cout << "Input search description: \n";
					cin >> description;
					allOrd.search_by_description(description);
					type_menu = 0;
					break;
				case 4:
					cout << "Input search price: \n";
					cin >> price;
					allOrd.search_by_price(price);
					type_menu = 0;
					break;
				case 5:
					cout << "Input search courier: \n";
					cin >> courier;
					allOrd.search_by_courier(courier);
					type_menu = 0;
					break;
				case 6:
					cout << "Input search days_to_deliver: \n";
					cin >> days_to_deliver;
					allOrd.search_by_days_to_deliver(days_to_deliver);
					type_menu = 0;
					break;
				case 7:
					cout << "Input search name_company: \n";
					cin >> name_company;
					allOrd.search_by_name_company(name_company);
					type_menu = 0;
					break;
				case 8:
					cout << "Input search money_amount: \n";
					cin >> money_amount;
					allOrd.search_by_days_money_amountr(money_amount);
					type_menu = 0;
				case 9:
					cout << "Input search type: \n";
					cin >> name_company;
					allOrd.search_by_type(name_company);
					type_menu = 0;
					break;
					
				default:
					break;
				}
			} while (type_menu != 0);
			break;
		case 4:
			do
			{
				cout << "1. sort_by_date: \n";
				cout << "2. sort_by_time: \n";
				cout << "3. sort_by_description: \n";
				cout << "4. sort_by_price: \n";
				cout << "5. sort_by_number: \n";
				cout << "6. sort_by_priority: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					allOrd.sort_by_date();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 2:
					allOrd.sort_by_time();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 3:
					allOrd.sort_by_description();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 4:
					allOrd.sort_by_price();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 5:
					allOrd.sort_by_number();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				case 6:
					allOrd.sort_by_priority();
					type_menu = 0;
					cout << "\nSorting is compleate!\n";
					break;
				default:
					break;
				}
			} while (type_menu != 0);
			break;
		case 5:
			do
			{
				cout << "1. del_by_date: \n";
				cout << "2. del_by_time: \n";
				cout << "3. del_by_description: \n";
				cout << "4. del_by_price: \n";
				cout << "5. del_by_number: \n";
				cout << "6. del_by_type: \n";
				cout << "0. Exit from the menu for searching: \n";

				cout << "input category sort, by this changes: ";
				cin >> type_menu;
				switch (type_menu)
				{
				case 1:
					cout << "Input remove date: \n";
					cin >> order_date;
					allOrd.del_by_date(order_date);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 2:
					cout << "Input remove time: \n";
					cin >> order_time;
					allOrd.del_by_time(order_time);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 3:
					cout << "Input remove description: \n";
					cin >> description;
					allOrd.del_by_description(description);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 4:
					cout << "Input remove price: \n";
					cin >> price;
					allOrd.del_by_price(price);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 5:
					cout << "Input remove number: \n";
					cin >> number;
					allOrd.del_by_number(number);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				case 6:
					cout << "Input remove type: \n";
					cin >> description;
					allOrd.del_by_type(description);
					type_menu = 0;
					cout << "\nDeletihg is compleate!\n";
					break;
				default:
					break;
				}
			} while (type_menu != 0);
			
			break;

		case 6:
			allOrd.save("orders"); // save to file by file name (create name)
			break;
		case 7:
			allOrd.load("orders"); // load from file by file name
			break;
		default:
			break;
		}
	} while (menu != 0);

	/*ofstream file("orders.txt")
		if (file.is_open())
		{
			d.save(file);
		}
	ifstream file("orders.txt");
	
	if (file.is_open())
	{
		d2.load(file);
	}

	file.close();
	d2.show();*/

	}
	catch (Order_exceptions* exc)
	{
		exc->show_message();
	}

	return 0;
}