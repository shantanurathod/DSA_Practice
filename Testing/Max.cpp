#include <iostream>
#include <vector>

constexpr char ENDL = '\n';
using std::cin;

using std::cout;
using std::endl;

void print(std::vector<int> &v)
{
    for (int x : v)
    {
        cout << x << " ";
    }

    cout << endl;
}

int main()
{
    std::vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::vector<int> maxLeft;

    print(height);
    int maxnum = 0;

    for (int i = 0; i < height.size(); i++)
    {
        // if (maxnum <= v[i])
        // {
        //     maxnum = v[i];
        // }

        maxnum = std::max(maxnum, height[i]);

        maxLeft.push_back(maxnum);
    }

    print(maxLeft);
    maxnum = 0;

    std::vector<int> maxRight(height.size());
    // cout << maxRight.capacity() << endl;

    for (int i = height.size() - 1; i >= 0; i--)
    {
        if (maxnum <= height[i])
        {
            maxnum = height[i];
        }

        maxRight[i] = maxnum;
    }

    print(maxRight);
    int res = 0;
    for (int i = 0; i < height.size(); i++)
    {
        res += std::max(0, std::min(maxRight[i], maxLeft[i]) - height[i]);
    }

    cout << res << endl;
    return 0;
}