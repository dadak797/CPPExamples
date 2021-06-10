#include <iostream>

using namespace std;


int main()
{
    cout << "+------------------------------+" << endl;
    cout << "|     Add Integers Example     |" << endl;
    cout << "+------------------------------+" << endl;

    int number;
    int sum = 0;

    while (true)
    {
        cout << "Please enter an integer or EOF: ";
        cin >> number;

        if (cin.eof())  // Check eof character (Ctrl+Z in window)
        {
            break;
        }

        if (cin.fail())  // Clear wrong input and set to clean state
        {
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore(LLONG_MAX, '\n');
            continue;
        }
        sum += number;
    }
    cin.clear();  // Set to clean state

    cout << "The sum is " << sum << endl;

    return 0;
}