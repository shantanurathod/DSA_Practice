#include <iostream>
#include <ios>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

int fib(int n)
{
    int pre = 1, current = 1, out = 0; // out is zero just for initialisation

    if (n == 0)
    {
        return 1;
    }

    if (n == 1)
    {
        return 1;
    }

    for (int i = 2; i <= n; i++)
    {
        out = current + pre;
        pre = current;
        current = out;
    }

    return out;
}

int main()
{

    cout.setf(std::ios::fixed);
    cout.precision(10);
    // cout.setf(ios::fixed, ios::floatfield);
    // cout.setf(ios::showpoint);

    cout << fib(46);

    return 0;
}