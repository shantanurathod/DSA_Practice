#include <iostream>
#include <vector>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

int missingNum(std::vector<int> num)
{
    int n = num.size();

    int sum = (n*(n-1))/2;

    for(int x: num)
    {
        sum -= x;
    }

    return sum;

} 

int main()
{

    cin.get();
    return 0;
}