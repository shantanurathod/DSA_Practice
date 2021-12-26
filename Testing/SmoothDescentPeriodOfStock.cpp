#include <iostream>
#include <vector>
constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

long long getDescentPeriods(std::vector<int> &prices)
{

    long long n = prices.size();
    std::vector<int> v;
    long long count = n;
    int t = 1;
    for (int i = 0; i < n - 1; i++)
    {

        if (prices[i] - prices[i + 1] == 1)
        {
            t++;
        }
        else
        {
            v.push_back(t);
            t = 1;
        }
    }

    for(int x: v)
    {
        count += (x*(x-1))/2;
    }

    return count;
}
int main()
{
    std::vector<int> prices{8,6,7,7};
    cout << getDescentPeriods(prices);
    return 0;
}