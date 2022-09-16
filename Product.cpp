#include "Product.h"

Product::Product()
{
	product_name = "";
	product_price = 0;
	weight = 0;
	amount = 0;
}

Product::Product(string product_name, float product_price, float weight)
{
	this->product_name = product_name;
	set_price(product_price);
	this->weight = weight;
	product_num = ++amount;
}

Product::~Product()
{
}

void Product::set_name(string product_name)
{
	this->product_name = product_name;
}

void Product::set_price(float product_price)
{
	if (product_price >= 0)
	{
		this->product_price = product_price;
	}
	else
		throw new Price_exception;
}

void Product::set_weight(float weight)
{
	if (weight > 0)
	{
		this->weight = weight;
	}
	else cout << "Weight cannot be less than zero or equals zero!\n";
	//else throw new Weight_exception;
}

string Product::get_name()
{
	return product_name;
}

float Product::get_price()
{
	return product_price;
}

float Product::get_weight()
{
	return weight;
}

void Product::show_product()
{
	cout << "product_name: " << product_name << endl;
	cout << "product_price: " << product_price << endl;
	cout << "weight: " << weight << endl << endl;
}
