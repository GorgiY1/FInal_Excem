#pragma once
#pragma once
#include<iostream>
#include<string>

#include"Card.h"
#include"Order_exceptions.h"

using namespace std;

class Product
{
	
	string product_name;
	float product_price;
	float weight;

	int product_num;
	static int amount;
public:
	Product();
	Product(string product_name, float product_price, float weight);
	~Product();

	void set_name(string product_name);
	void set_price(float product_price);
	void set_weight(float weight);

	string get_name();
	float get_price();
	float get_weight();

	void show_product();
};

