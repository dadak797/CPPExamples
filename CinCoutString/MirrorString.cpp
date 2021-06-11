#include <iostream>
#include <string>

using namespace std;


int main()
{
    // C++Style
    cout << "+------------------------------+" << endl;
    cout << "|    Mirror String Example     |" << endl;
    cout << "+------------------------------+" << endl;

    string line = "Hello World!";

    cout << "String to mirror: " << line << endl;

    for (int i = (int)line.size() - 1; i >= 0; --i)
    {
        line += line[i];
    }
    cout << "Mirrored string: " << line << endl << endl;

    // C-Style
    const int LINE_SIZE = 512;
    char line2[LINE_SIZE] = "Mirror";

    cout << "String to mirror (C-Style): " << line2 << endl;

    char* p = line2 + strlen(line2);
    char* q = line2 + strlen(line2) - 1;

    while (q >= line2)
    {
        *p = *q;

        p++;
        q--;
    }
    *p = 0;  // Null character

    cout << "Mirrored string (C-Style): " << line2 << endl;

    return 0;
}