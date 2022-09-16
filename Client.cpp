#include "Client.h"

Client::Client()
{
	name_client = "";
	client_card = 0;
	all_sum = 0;
	phone = 0;
}

Client::Client(string name, Card &client_card, int phone)
{
	this->name_client = name;
	this->client_card = client_card;
	this->phone = phone;
	all_sum = 0;
}

Client::Client(const Client& obj)
{
	this->name_client = obj.name_client;
	this->client_card = obj.client_card;
	this->phone = obj.phone;
	this->all_sum = obj.all_sum;
}

Client::~Client()
{
	for (i = shopping_cart.begin(); i != shopping_cart.end(); i++)
	{
		(*(i))->~Product();
	}
	shopping_cart.erase(shopping_cart.begin(),shopping_cart.end());
}

string Client::get_name_client() const
{
	return name_client;
}

Card Client::get_client_card() const
{
	return client_card;
}

double Client::get_all_sum() const
{
	return all_sum;
}

int Client::get_phone() const
{
	return phone;
}

void Client::set_name(string name)
{
	this->name_client = name;
}

void Client::set_card(Card card)
{
	this->client_card = card;
} 

void Client::set_phone(int phone)
{
	this->phone = phone;
}

void Client::set_all_sum(double all_sum)
{
	this->all_sum = all_sum;
}

void Client::send_money(Card &card_company)
{
	if (client_card.get_cash() >= all_sum)
	{
		this->client_card.spend_cash(all_sum);
		card_company.add_cash(all_sum);
	}
	else
	{
		cout << "Error! Not enough money!\n";
	}
}

void Client::add_product_to_shopping_cart(Product *obj)
{
	shopping_cart.emplace(obj);
	if (shopping_cart.size()!= 0)
	{
		all_sum += obj->get_price();
	}
}

void Client::show_cliet() const
{
	cout << "=============================\n";
	cout << "name_client: " << name_client << endl;
	//cout << "client_card: \n"; 
	client_card.show_card();
	cout << "all_sum: " << all_sum << endl;
	cout << "phone: " << phone << endl;
	cout << "=============================\n\n\n";
}

void Client::show_products_of_client()
{
	for (i = shopping_cart.begin(); i != shopping_cart.end(); i++)
	{
		(*(i))->show_product();
	}
}