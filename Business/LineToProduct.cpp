#include "LineToProduct.h"

Product *LineToProduct::convert(string line)
{
    vector<string> tokens = StringUtils::split(line, ",");
    string name = tokens[0];
    int price = stoi(tokens[1]);
    return new Product(name, price);
}

string LineToProduct::convert(Object *object)
{
    Product *product = dynamic_cast<Product *>(object);
    return product->getName() + "," + to_string(product->getPrice());
}

LineToProduct::LineToProduct()
{
}

shared_ptr<LineToProduct> LineToProduct::instance()
{
    if (_instance == nullptr)
    {
        LineToProduct* temp = new LineToProduct();
        _instance = shared_ptr<LineToProduct>(temp);
    }
    return _instance;
}