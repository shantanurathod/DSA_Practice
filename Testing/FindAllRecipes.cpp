#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> solve(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
{
    // your code goes here
    for(string x: recipes)
    {
        for(vector<string> y: ingredients)
        {
            for(string z: y)
            {
                for(string a: supplies)
                {
                    if(z == a)
                    {
                        
                    }
                }
               
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}