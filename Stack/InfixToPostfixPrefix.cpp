#include <iostream>
#include "Stack_o.h"

using namespace std;

int prec(char x)
{
    switch (x)
    {
    case '-':
        return 1;

    case '+':
        return 2;

    case '*':
        return 3;

    case '/':
        return 4;
    }

    return -1;
}
string InfixToPostfix(string s)
{
    string result = "";
    Stack<char> stk;

    for (auto x : s)
    {
        if (x == '(')
        {
            stk.push(x);
        }

        else if (x == '+' || x == '-' || x == '*' || x == '/')
        {
            if (stk.isEmpty())
            {
                stk.push(x);
            }

            else
            {
                if (!stk.isEmpty() && prec(stk.top()) > prec(x))
                {
                    result += stk.top();
                    stk.pop();
                    stk.push(x);
                }

                else
                {
                    stk.push(x);
                }
            }
        }

        else if (x == ')')
        {
            while (!stk.isEmpty() && stk.top() != '(')
            {
                result += stk.top();
                stk.pop();
            }

            if (!stk.isEmpty())
            {
                stk.pop();
            }
        }

        else if (x >= 'a' && x <= 'z')
        {
            result += x;
        }
    }

    while(!stk.isEmpty())
    {
        result += stk.top();
        stk.pop();
    }

    return result;
}

string InfixToPrefix(string s)
{
    Stack<char> stk;
    string new_s = "";

    for(auto x: s)
    {
        stk.push(x);
    }

    while(!stk.isEmpty())
    {
        new_s += stk.top();
        stk.pop();
    }

    for(int i = 0; i < new_s.length(); i++)
    {
        if(new_s[i] == '(')
        {
            new_s[i] = ')';
        }

        else if(new_s[i] == ')')
        {
            new_s[i] = '(';
        }
    }
    
    new_s = InfixToPostfix(new_s);

    for(auto x: new_s)
    {
        stk.push(x);
    }

     new_s = "";

    while (!stk.isEmpty())
    {
       new_s += stk.top();
       stk.pop();
    }
    return new_s;
}

int main()
{
    string s = "(a-b/c)*(a/k-l)";

    cout << InfixToPostfix(s) << endl;

    cout << InfixToPrefix(s) << endl;
}