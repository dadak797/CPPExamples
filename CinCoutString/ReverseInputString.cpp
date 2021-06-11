#include <iostream>

using namespace std;


int main()
{
    // Reverse String Example
    cout << "+------------------------------+" << endl;
    cout << "|    Reverse String Example    |" << endl;
    cout << "+------------------------------+" << endl;

    const int LINE_SIZE = 512;
    char line[LINE_SIZE];

    cout << "Please enter a string to reverse" << endl
        << "or EOF to quit: ";

    cin.getline(line, LINE_SIZE);
    if (cin.fail())
    {
        cin.clear();
        cout << "Wrong input!" << endl;
        return -1;
    }

    char* p = line;
    char* q = line + strlen(line) - 1;

    while (p < q)
    {
        char temp = *p;
        *p = *q;
        *q = temp;

        p++;
        q--;
    }

    // My method
    /*size_t len = strlen(line);
    for (int i = 0; i < int(len / 2); i++)
    {
        char tmpChar = line[len - i -1];
        line[len - i - 1] = line[i];
        line[i] = tmpChar;
    }*/

    cout << "Reversed string: " << line << endl;

    return 0;
}