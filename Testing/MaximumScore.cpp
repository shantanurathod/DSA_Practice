#include <iostream>
#include <vector>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

long long solve(int N, std::vector<long long> &v)
{
    int k = 1;
    
    std::vector<long long> maxArr;
    while (k <= N)
    {
        long long maxScore = 0;
        for (int i = 1; i <= N && k*i <= N; i++)
        {
            maxScore += v[k*i];
        }
        maxArr.push_back(maxScore);
        k++;
    }

    long long maxScore2 = 0;
    for(long long x: maxArr)
    {
        maxScore2 = std::max(x,maxScore2);
    }

    long long k_final = -2;
    for(size_t i = 0; i < maxArr.size(); i++)
    {
        if(maxArr[i] == maxScore2)
        {
            k_final = i+1;
        }
    }

    return k_final;
}

int main()
{
    std::vector<long long> v{-3, -2, -1};
    int N = static_cast<int> (v.size());
    cout << solve(N, v) << endl;
    return 0;
}