#include "Product.h"

Product::Product(string name, int price)
{
    this->name = name;
    this->price = price;
    this->id = idCounter++;
}

string Product::toString()
{
    stringstream ss;
    ss << " " << setw(2) << id << "|" << setw(29) << name << "|" << setw(9) << price << "|";
    return ss.str();
}

string Product::getName()
{
    return name;
}

int Product::getPrice()
{
    return price;
}

int Product::getId()
{
    return id;
}

void Product::setId(int id)
{
    this->id = id;
}

void Product::setName(string name)
{
    this->name = name;
}

void Product::setPrice(int price)
{
    this->price = price;
}