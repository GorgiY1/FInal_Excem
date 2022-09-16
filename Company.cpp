#include "Company.h"

Company::Company()
{
	name_company = "";
	card = Card();
	phone = 0;
}

Company::Company(string name, Card card, int phone)
{
	this->name_company = name;
	this->card = card;
	this->phone = phone;
}

Company::~Company()
{
	for (i = list_products.begin(); i != list_products.end(); i++)
	{
		(*(i))->~Product();
	}
	list_products.erase(list_products.begin(), list_products.end());
}

string Company::get_name() const
{
	return name_company;
}

Card Company::get_card() const
{
	return card;
}

int Company::get_phone() const
{
	return phone;
}

Product Company::get_tmp() const
{
	return tmp;
}

void Company::set_name(string name)
{
	this->name_company = name;
}

void Company::set_card(Card card)
{
	this->card = card;
}

void Company::set_phone(int phone)
{
	this->phone = phone;
}

void Company::add_product_to_company(Product* obj)
{
	list_products.emplace(obj);
}

Product Company::del_prod(string name_prod)
{
	for (i = list_products.begin(); i != list_products.end(); i++)
	{
		multiset<Product*>::iterator del = i; 
		
		if ((*(del))->get_name() == name_prod)
		{
			i++;
			this->tmp.set_name((*(del))->get_name());
			this->tmp.set_price((*(del))->get_price());
			this->tmp.set_weight((*(del))->get_weight());
			//Product tmp((*(del))->get_name(), (*(del))->get_price(), (*(del))->get_weight()); //return object for adding to shopping cart of client
			list_products.erase(del);
			return tmp;
			break;
		}
		/*else if(i == list_products.end())
		{
			Product tmp;
			return tmp;
		}*/
	}
}

void Company::show_company() const
{
	cout << "\n=============================\n";
	cout << "name_client: " << name_company << endl;
	cout << "company_card: \n";
	card.show_card();
	cout << "phone: " << phone << endl;
	cout << "=============================\n\n\n";
}

void Company::show_products_of_company()
{
	for (i = list_products.begin(); i != list_products.end(); i++)
	{
		(*(i))->show_product();
	}
}
