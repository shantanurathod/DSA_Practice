#include <iostream>
#include <vector>
#include <cmath>
constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

int minCostClimbingStairs(std::vector<int> &cost)
{
    int n = cost.size();

    int price = 0;

    for(int i = 0; i < n;)
    {
        price += std::min(cost[i],cost[i+1]); 

        if(cost[i] <= cost[i+1])
            i++;

        else
            i += 2;
    }

    return price;
    
}

int main()
{
    std::vector<int> cost{1,100,1,1,1,100,1,1,100,1};

    cout << minCostClimbingStairs(cost);
    return 0;
}