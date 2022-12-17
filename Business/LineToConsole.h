#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <sstream>
#include "..\Entity\Product.h"
#include "..\Entity\Converter.h"
using namespace std;

class LineToConsole : public Converter
{
private:
    LineToConsole();
    inline static shared_ptr<LineToConsole> _instance = nullptr;

public:
    static shared_ptr<LineToConsole> instance();
    Object *convert(string line);
    string convert(Object *object);
};
