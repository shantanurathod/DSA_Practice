#include <iostream>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

long double fac(int n)
{
    if (n <= 1)
        return 1;

    long double res = 1;
    while (n >= 1)
    {
        res *= n;
        n--;
    }

    return res;
}

int uniquePath(int m, int n)
{
    long double res = fac(m + n - 2) / (fac(m - 1) * fac(n - 1));

    return round(res);
}
int main()
{
    cout << uniquePath(3,7) << endl;
    return 0;
}