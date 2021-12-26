#include <iostream>
#include <vector>
constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

std::string firstPalindrome(std::vector<std::string> &words)
{
    for (std::string x : words)
    {
        //cout << x << x.size() << endl;
        std::string y = "";
        for (int i = x.size() - 1; i >= 0; i--)
        {
            //cout << x[i] << endl;
            y += x[i];
        }

        //cout << y << endl;
        if (y == x)
        {
            return x;
        }
    }

    return "";
}
int main()
{
    std::vector<std::string> words{"abc", "car", "ada", "racecar", "cool"};

    cout << firstPalindrome(words);

    return 0;
}