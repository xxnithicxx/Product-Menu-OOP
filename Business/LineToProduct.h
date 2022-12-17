#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "..\Entity\Converter.h"
#include "..\Entity\Product.h"
#include "..\Utils\StringUtils.h"
using namespace std;

class LineToProduct : public Converter
{
private:
    LineToProduct();
    inline static shared_ptr<LineToProduct> _instance = nullptr;

public:
    static shared_ptr<LineToProduct> instance();
    Product *convert(string line);  // Liskov (The return type in a method of a subclass should match or be a subtype of the return type in the method of the superclass.)
    string convert(Object *object); // Liskov (Parameter types in a method of a subclass should match or be more abstract than parameter types in the method of the superclass)
};