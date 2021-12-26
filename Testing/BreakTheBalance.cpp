#include <iostream>
#include <stack>
#include <vector>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

void solve(std::vector<int> &v)
{
    std::string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == ')')
        {
            if(i%2 == 0 || i == 1)
            {
                v.push_back(i);
            return;
            }
            else
            {
                v.push_back(i - 1);
                return;
            }
            
        }
    }
}

int main()
{
int testcase;
cin >> testcase;

std::vector<int> v;

while(testcase--)
{
    solve(v);
}

for(int x: v)
{
    cout << x << endl;
}

return 0;
}