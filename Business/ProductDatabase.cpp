#include "ProductDatabase.h"

ProductDatabase::ProductDatabase()
{
}

shared_ptr<ProductDatabase> ProductDatabase::instance()
{
    if (_instance == nullptr)
    {
        ProductDatabase *temp = new ProductDatabase();
        _instance = shared_ptr<ProductDatabase>(temp);
    }
    return _instance;
}

Product &ProductDatabase::getProduct(int id)
{
    return *products[id];
}

vector<Product *> &ProductDatabase::getProducts()
{
    return products;
}

vector<Object *> ProductDatabase::getObjects()
{
    vector<Object *> objects;
    for (Product *product : products)
    {
        objects.push_back(product);
    }
    return objects;
}

Product ProductDatabase::createProduct(string name, int price)
{
    Product *p = new Product(name, price);
    products.push_back(p);
    return *p;
}

void ProductDatabase::removeProduct(int id)
{
    products.erase(products.begin() + id);
}

bool ProductDatabase::loadFromFile(string path)
{
    shared_ptr<LineToProduct> lineConverter = LineToProduct::instance();
    File file(path, lineConverter);
    vector<Object *> objects = file.read();

    for (Object *object : objects)
    {
        Product *product = dynamic_cast<Product *>(object);
        if (product != nullptr)
        {
            products.push_back(product);
        }
    }

    return true;
}