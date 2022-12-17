#include "DisplayMenu.h"

DisplayMenu::DisplayMenu(MyConsole *console)
{
    this->console = console;
}

void DisplayMenu::show()
{
    ProductDatabase *productDatabase = console->getProductDatabase();
    vector<Product *> products = productDatabase->getProducts();

    if (products.size() == 0)
    {
        cout << "No products found" << endl;
        return;
    }

    for (int i = 0; i < products.size() / MAX_LINES + 1; i++)
    {
        lines.push_back(vector<string>());

        stringstream ss;
        ss << "All products. Page " << i + 1 << "/" << products.size() / MAX_LINES + 1 << ". Displays " << (i + 1) * MAX_LINES << " of " << products.size() << " products";
        lines[i].push_back(ss.str());
        ss.str(std::string());
        ss << " ID|" << setw(30) << "Name|" << setw(10) << "Price|";
        lines[i].push_back(ss.str());
        ss.str(std::string());
        ss << "---|" << setw(30) << "--------------------|" << setw(10) << "---------|";
        lines[i].push_back(ss.str());

        for (int j = 0; j < MAX_LINES; j++)
        {
            if (i * MAX_LINES + j < products.size() && products[i * MAX_LINES + j] != nullptr)
                lines[i].push_back(products[i * MAX_LINES + j]->toString());

            if (i * MAX_LINES + j == products.size() - 1)
                break;
        }

        lines[i].push_back("Press arrow keys to navigate");
        lines[i].push_back("Enter to edit product, 'd' to delete product");
        lines[i].push_back("Press escape to go back to main menu");
    }

    cursor = 3;
    for (int i = 0; i < lines[0].size(); i++)
    {
        if (i == cursor)
            ConsoleUtils::highlight(lines[0][i]);
        else
            cout << lines[0][i] << endl;
    }

    page = 0;
}

void DisplayMenu::handleInput(string input)
{
    int oldCursor = cursor;
    if (input == "keydown")
    {
        if (cursor < lines[page].size() - 4)
        {
            cursor++;
        }
        else
        {
            cursor = 3;
        }
    }
    else if (input == "keyup")
    {
        if (cursor > 3)
        {
            cursor--;
        }
        else
        {
            cursor = lines[page].size() - 4;
        }
    }
    else if (input == "d") 
    {
        if (cursor >= 3 && cursor < lines[page].size() - 4)
        {
            ProductDatabase *productDatabase = console->getProductDatabase();
            vector<Product *> products = productDatabase->getProducts();
            products.erase(products.begin() + cursor - 3);
            lines[0].erase(lines[0].begin() + cursor);
            cursor--;
        }
    }
    else if (input == "enter")
    {
        if (cursor >= 3 && cursor < lines[page].size() - 3)
        {
            ProductDatabase *productDatabase = console->getProductDatabase();
            vector<Product *> products = productDatabase->getProducts();
            int index = cursor - 3 + page * MAX_LINES;
            console->setMenu(new EditMenu(console, products[index]));
        }
    }
    else if (input == "escape")
    {
        console->setMenu(new MainMenu(this->console));
    }
    else if (input == "keyleft")
    {
        if (page > 0)
        {
            page--;
            changePage(page);
        }
    }
    else if (input == "keyright")
    {
        if (page < lines.size() - 1)
        {
            page++;
            changePage(page);
        }
    }

    ConsoleUtils::restoreLine(oldCursor, lines[page][oldCursor]);
    ConsoleUtils::gotoLine(cursor);
    ConsoleUtils::highlight(lines[page][cursor]);
}

void DisplayMenu::changePage(int page)
{
    ConsoleUtils::clearScreen();

    for (int i = 0; i < lines[page].size(); i++)
    {
        if (i == cursor)
            ConsoleUtils::highlight(lines[page][i]);
        else
            cout << lines[page][i] << endl;
    }
}

string DisplayMenu::toString()
{
    return "DisplayMenu";
}