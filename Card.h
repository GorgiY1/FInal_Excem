#pragma once
#include<iostream>
using namespace std;

class Card
{
	unsigned long long int card_number;
	double cash;

public:
	Card();
	Card(double cash);
	Card(const Card& obj);

	unsigned long long int get_card_number()const;
	double get_cash()const;

	void set_cash(double cash);
	void add_cash(double sum_add_cash);
	void spend_cash(double sum_spend);

	void show_card()const;
};

