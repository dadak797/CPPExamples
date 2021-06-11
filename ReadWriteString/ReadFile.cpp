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

    // Read File Line by Line
    /*std::string line;
    while (!fin.eof())
    {
        getline(fin, line);
        std::cout << line << std::endl;
    }*/

    fin.close();
	
    return 0;
}