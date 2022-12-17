#include "Console.h"

MyConsole::MyConsole(ProductDatabase *productDatabase)
{
    this->productDatabase = productDatabase;
    this->menu = new MainMenu(this);
    this->changeConsole = false;
    this->keyboard = Keyboard::instance();
}

void MyConsole::setMenu(Menu *menu)
{
    this->menu = menu;
    this->changeConsole = true;
}

ProductDatabase *MyConsole::getProductDatabase()
{
    return productDatabase;
}

void MyConsole::show()
{
    ConsoleUtils::clearScreen();
    this->menu->show();
}

void MyConsole::run()
{
    do
    {
        string input = keyboard->getInput();
        this->menu->handleInput(input);

        if (changeConsole && this->menu != nullptr)
        {
            changeConsole = false;
            show();
        }
    } while (this->menu != nullptr);
}