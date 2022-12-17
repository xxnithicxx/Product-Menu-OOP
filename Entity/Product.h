#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "Object.h"
using namespace std;

class Product : public Object
{
private:
    int id;
    string name;
    int price;
    inline static int idCounter = 0;

public:
    void setId(int id);
    void setName(string name);
    void setPrice(int price);

    string getName();
    int getPrice();
    int getId();

public:
    Product(string name, int price);
    string toString();
};