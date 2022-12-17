#include "File.h"

File::File(string path, shared_ptr<Converter> lineConverter)
{
    this->path = path;
    this->lineConverter = lineConverter;
}

vector<Object *> File::read()
{
    vector<Object *> objects;
    ifstream file(path);
    string line;
    while (getline(file, line))
    {
        Object *object = lineConverter->convert(line);
        objects.push_back(object);
    }
    file.close();
    return objects;
}

void File::write(vector<Object *> objects)
{
    ofstream file(path);
    
    for (int i = 0; i < objects.size(); i++)
    {
        string line = lineConverter->convert(objects[i]);
        file << line;
        if (i != objects.size() - 1)
        {
            file << endl;
        }
    }

    file.close();
}