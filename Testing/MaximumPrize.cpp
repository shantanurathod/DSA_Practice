#include <iostream>
#include <vector>
#include <algorithm>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

long long solve()
{
    size_t size = 0;
    cin >> size;
    std::vector<int> A(size);

    long long maxPrize = 0;
    for(size_t i = 0; i < size; i++)
    {
        cin >> A[i];
        maxPrize += A[i];
    }

    maxPrize -= *min_element(A.begin(), A.end());

    return maxPrize;
}

int main()
{

int testcase;
cin >> testcase;

std::vector<long long> v;
while(testcase--)
{
   v.push_back(solve());
}

for(long long x: v)
{
    cout << x << endl;
}

return 0;
}