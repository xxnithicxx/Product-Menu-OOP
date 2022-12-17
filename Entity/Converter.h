#pragma once

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

// Interface for converting a line to an object
class Converter
{
public:
    virtual Object *convert(string line) = 0;
    virtual string convert(Object *object) = 0;
};