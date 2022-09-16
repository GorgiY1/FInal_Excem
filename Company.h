#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include"Card.h"
#include"Product.h"

using namespace std;

class Company
{
protected:
	multiset<Product*> list_products;
	multiset<Product*>::iterator i = list_products.begin();

	string name_company;
	Card card;
	int phone;

	Product tmp;
public:
	Company();
	Company(string name,Card card, int phone);
	~Company();

	string get_name()const;
	Card get_card()const;
	int get_phone()const;
	Product get_tmp()const;

	void set_name(string name);
	void set_card(Card card);
	void set_phone(int phone);

	//void get_money_from_client(Card card_client);

	void add_product_to_company(Product* obj);
	Product del_prod(string name_prod);

	void show_company()const;
	void show_products_of_company();
};
