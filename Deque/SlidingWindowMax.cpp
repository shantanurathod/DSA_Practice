#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int k = 3;
    int a[] = {-1, 5, 2, 9, 3, -2, -7, 4};
    int n = sizeof(a)/sizeof(a[0]);
    vector<int> res;

    for(int i = 0; i < n - k + 1; i++)
    {
        int max_num = 0;

        for(int j = i; j < i + k; j++)
        {
            max_num = max(a[j],max_num);
        }

        res.push_back(max_num);
    }

    for(auto x: res)
    {
        cout << x << " ";
    }
}