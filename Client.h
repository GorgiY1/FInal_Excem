#pragma once
#include<iostream>
#include<string>
#include<set>
#include<algorithm>
#include"Card.h"
#include"Product.h"

using namespace std;

class Client
{
protected:
	multiset<Product*> shopping_cart;
	multiset<Product*>::iterator i = shopping_cart.begin();

	string name_client;
	Card client_card;
	double all_sum; // The cost of all products selected by the client
	int phone;
public:
	Client();
	Client(string name,Card &client_card, int phone);
	Client(const Client &obj);
	~Client();

	string get_name_client()const;
	Card get_client_card()const;
	double get_all_sum()const;
	int get_phone()const;

	void set_name(string name);
	void set_card(Card card);
	void set_phone(int phone);
	void set_all_sum(double all_sum);

	void send_money(Card &card_company); // transfer amount (double all_sum), to the card company(Card &card_company)

	void add_product_to_shopping_cart(Product *obj);

	void show_cliet()const;
	void show_products_of_client();
};

