#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "..\Entity\Product.h"
#include "LineToProduct.h"
#include "..\Entity\File.h"
using namespace std;

// There should be only one instance of this class
class ProductDatabase
{
private:
    vector<Product *> products;
    inline static shared_ptr<ProductDatabase> _instance = nullptr;
    ProductDatabase();

public:
    Product &getProduct(int id);
    vector<Product *> &getProducts();
    vector<Object *> getObjects();

public:
    static shared_ptr<ProductDatabase> instance();
    // Factory method for creating a new product
    Product createProduct(string name, int price);
    void removeProduct(int id);
    bool loadFromFile(string path);
};