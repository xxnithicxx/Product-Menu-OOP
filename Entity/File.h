#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>
#include "..\Entity\Converter.h"
#include "Object.h"
using namespace std;

class File
{
private:
    string path;
    vector<string> lines;
    shared_ptr<Converter> lineConverter;
    // Storage* storage;

public:
    File(string path, shared_ptr<Converter> lineConverter);
    vector<Object *> read();
    void write(vector<Object *> objects);
};