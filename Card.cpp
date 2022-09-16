#include "Card.h"

Card::Card()
{
    card_number = 0;
    cash = 0;
}

Card::Card(double cash)
{
    card_number = rand() % (long)899999999999999 + (long)1000000000000000;
    //card_number = 0;
    this->cash = cash;
}

Card::Card(const Card& obj)
{
    this->card_number = obj.card_number;
    this->cash = obj.cash;
}

unsigned long long int Card::get_card_number() const
{
    return card_number;
}

double Card::get_cash() const
{
    return cash;
}

void Card::set_cash(double cash)
{
    if (cash >= 0)
        this->cash = cash;
}


void Card::add_cash(double cash)
{
   // this->cash += cash;
     set_cash(get_cash()+cash);
}

void Card::spend_cash(double sum_spend)
{
    if (sum_spend > get_cash()) {
        std::cout << "Not enough money\n"; // throw
        return;
    }
    else
    {
        this->cash -= sum_spend;
        set_cash(cash);
    }
       
}

void Card::show_card() const
{
    cout << "Card number: " << card_number << endl;
    cout << "Amount maney: " << cash << endl;
}
