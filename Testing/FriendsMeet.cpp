#include <iostream>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

int main()
{
int testcase;
cin >> testcase;

for(int i = 0; i < testcase; i++)
{
    int x1,x2,t = 0;

    cin >> x1 >> x2;

    while(x1 >= x2)
    {
        x1 += t;
        x2 += 2*t;

        t++;

        if(x1 == x2)
        {
            break;
        }
    }

    if(x1 == x2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}


cin.get();
return 0;
}