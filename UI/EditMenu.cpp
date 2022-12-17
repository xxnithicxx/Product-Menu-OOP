#include "EditMenu.h"

EditMenu::EditMenu(MyConsole *console, Product *product)
{
    this->console = console;
    this->product = product;
}

void EditMenu::show()
{
    lines.push_back("Name: " + product->getName());
    lines.push_back("Price: " + to_string(product->getPrice()));

    lines.push_back("Press arrow keys to navigate");
    lines.push_back("Enter to edit product");

    this->cursor = 0;
    for (int i = 0; i < lines.size(); i++)
    {
        if (i == this->cursor)
        {
            ConsoleUtils::highlight(lines[i]);
            continue;
        }
        cout << lines[i] << endl;
    }
}

void EditMenu::handleInput(string input)
{
    int oldCursor = cursor;
    if (input == "keydown")
    {
        cursor++;
        if (cursor >= lines.size())
        {
            cursor = 0;
        }
    }
    else if (input == "keyup")
    {
        cursor--;
        if (cursor < 0)
        {
            cursor = lines.size() - 2;
        }
    }
    else if (input == "enter")
    {
        if (cursor == 0)
        {
            ConsoleUtils::clearLine(0);
            ConsoleUtils::gotoLine(0);
            ConsoleUtils::changeColor(Color::RED);
            cout << "Enter new name: ";
            ConsoleUtils::changeColor(Color::WHITE);
            string name;
            getline(cin, name);
            product->setName(name);
            lines[0] = "Name: " + name;
            ConsoleUtils::clearLine(0);
        }
        else if (cursor == 1)
        {
            ConsoleUtils::clearLine(1);
            ConsoleUtils::gotoLine(1);
            ConsoleUtils::changeColor(Color::RED);
            cout << "Enter new price: ";
            ConsoleUtils::changeColor(Color::WHITE);
            string price;
            getline(cin, price);
            product->setPrice(stoi(price));
            lines[1] = "Price: " + price;
            ConsoleUtils::clearLine(1);
        }
    }
    else if (input == "escape")
    {
        console->setMenu(new DisplayMenu(console));
    }

    ConsoleUtils::restoreLine(oldCursor, lines[oldCursor]);
    ConsoleUtils::gotoLine(cursor);
    ConsoleUtils::highlight(lines[cursor]);
}

string EditMenu::toString()
{
    return "EditMenu";
}