#include <fstream>
#include <iostream>


int main()
{
    std::ifstream fin;
    fin.open("Test.txt");

	// Read File Character by Character
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

    fin.close();
	
    return 0;
}