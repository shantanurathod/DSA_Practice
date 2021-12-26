#include <iostream>
#include <vector>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

std::string addSpaces(std::string s, std::vector<int> &spaces)
{

    char c = ' ';
    std::string put = "";
    int n = s.size();
    auto j = spaces.begin();

    for (int i = 0; i < n; i++)
    {
        if (j != spaces.end() && *j == i)
        {
            put.push_back(c);
            j++;
        }

        put.push_back(s[i]);
    }

    return put;
}
int main()
{

    cin.get();
    return 0;
}