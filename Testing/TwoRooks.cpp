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
    int x1,y1,x2,y2;

    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2 || y1 == y2)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}


return 0;
}