#include "Entity\Product.h"
#include "Business\ProductDatabase.h"
#include "Business\LineToProduct.h"
#include "Entity\File.h"
#include "Entity\Console.h"
#include "UI\MainMenu.h"
#include "Utils\ConsoleUtils.h"
using namespace std;

int main()
{
    shared_ptr<ProductDatabase> productDatabase = ProductDatabase::instance();
    productDatabase->loadFromFile("Resource\\products.txt");

    productDatabase->createProduct("Dell Inspiron 15", 15000000);

    MyConsole console(productDatabase.get());

    console.show();
    console.run();

    return 0;
}