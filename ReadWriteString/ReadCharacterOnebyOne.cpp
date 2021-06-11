#include <fstream>
#include <iostream>


int main()
{
    std::ifstream fin;
    fin.open("Test.txt");

    char character;
    while (true)
    {
        fin.get(character);
        if (fin.fail())
        {
            break;
        }
        std::cout << character;
    }

    return 0;
}