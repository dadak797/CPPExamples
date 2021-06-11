#include <fstream>
#include <iostream>
#include <string>


int main()
{
    std::ifstream fin;
    fin.open("Test.txt");

    int number;
    std::string trash;

    while (true)
    {
        fin >> number;

        if (!fin.fail())
        {
            std::cout << number << std::endl;
            continue;
        }

        if (fin.eof())
        {
            break;
        }

        fin.clear();
        fin >> trash;
    }

    fin.close();

    return 0;
}