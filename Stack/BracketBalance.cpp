#include <iostream>
#include <stack>
#include <string>

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

using namespace std;

bool bracketBalance(string s)
{
    stack<char> stk;

    if(s[0] == ')' || s[0] == ']' || s[0] == '}')
    {
        return false;
    }

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            stk.push(s[i]);
        }

        else if(s[i] == ')')
        {
            if(stk.top() == '(' && !stk.empty())
            {
                stk.pop();
            }
                
        }

        else if(s[i] == ']')
        {
            if(stk.top() == '[' && !stk.empty())
            {
                stk.pop();
            }
                
        }

        else if(s[i] == '}')
        {
            if(stk.top() == '{' && !stk.empty())
            {
                stk.pop();
            }
                
        }

        else
        {
            continue;
        }
    }

    if(!stk.empty())
    {
        return false;
    }

    return true;
}

int main()
{

string input = "";

cin >> input;

    if (bracketBalance(input))
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;


cin.get();
return 0;
}

