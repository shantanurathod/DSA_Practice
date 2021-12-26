#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int solve(std::vector<std::string> &sentences)
{

    // your code goes here
    std::vector<int> v2;
   
    for(std::string x: sentences)
    {
        int count = 1;
        for(char y: x)
        {
            if(y == ' ' || y == '\0')
            {
                count++;
            }
        }

        v2.push_back(count);
    }

    sort(v2.begin(),v2.end());

    return v2.back();
}

int main()
{
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         solve();
//     }

    vector<string> sentences{"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

    cout << solve(sentences) << endl;

    return 0;
}