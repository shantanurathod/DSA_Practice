#include <iostream>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;
 // no. of ways to reach at top of n stairs if you're allowed to take 1 step and 2step

long double fac(int n)
{
    if(n == 0)
    {
        return 1;
    }

    long double fac = n;
    for(int i = 1; i < n; i++)
    {   
        //cout << fac << " ";
        fac *= n - i;
    }

    //cout << endl;
    return fac;
}
int ways(int n)
{
    int ways = 0;

    for(int i = 0; i <= n/2; i++)
    {
        ways += fac(n - i)/(fac(n - (2*i))*fac(i));
        //cout << ways << "+";
    }

    //cout << endl;
    return ways;
}

int main()
{

for(int i = 1; i <= 100; i++)
    cout << i << ": " << ways(i) << endl;

return 0;
}