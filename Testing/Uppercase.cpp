#include <iostream>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

int main()
{
    char ch;
    cin >> ch;

    if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        if(ch >= 'A' && ch <= 'Z')
        {
            cout << char(tolower(ch));
        }

        else
        {
            cout << char(toupper(ch));
        }
    }

    else
    {
        cout << "character entered is not alphabate";
    }

return 0;
}