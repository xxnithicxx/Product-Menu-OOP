#include "AddMenu.h"

AddMenu::AddMenu(MyConsole *console)
{
    this->console = console;
    this->name = "";
    this->price = "";
}

void AddMenu::show()
{
    cout << "Enter product name: ";
    getline(cin, this->name);
    cout << "Enter product price: ";
    getline(cin, this->price);

    if (this->name == "" || this->price == "")
    {
        cout << "Invalid input!" << endl;
        return;
    }

    regex priceRegex("[0-9]{1,10}");
    if (!regex_match(this->price, priceRegex))
    {
        cout << "Invalid price!" << endl;
        return;
    }

    Product *product = new Product(this->name, stoi(this->price));
    ProductDatabase *productDatabase = console->getProductDatabase();
    productDatabase->getProducts().push_back(product);

    cout << "Product added!" << endl;
}

void AddMenu::handleInput(string input)
{
    console->setMenu(new DisplayMenu(console));
}

string AddMenu::toString()
{
    return "AddMenu";
}