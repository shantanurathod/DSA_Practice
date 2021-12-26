#include <iostream>
#include "Stack_o.h"
#include <cstdlib>
#include <string>

using namespace std;

int postfix(string s)
{   
    //string s = "4 6 + 2 / 5 * 7 +";
    Stack<int> stk;

    int op1,op2,result;
    for (auto x: s)
    {
        string num = "";
        if(x == ' ')
        {
            cout << "space" << endl;
            stk.push(stoi(num));
            stk.print();
        }

        else if(x == '+' || x == '-' || x == '*' || x == '/')
        {
            op1 = stk.top();
            stk.pop();
            op2 = stk.top();
            stk.pop();

            switch (x)
            {
            case '+':
                result = op2 + op1;
                break;
            
            case '-':
                result = op2 - op1;
                break;

            case '*':
                result = op2 * op1;
                break;

            case '/':
                result = op2 / op1;
                break;    
            }

            stk.push(result);
            stk.print();
        }

        else
        {
            num += x;
        }
    }

    stk.print();
    return stk.top();
}

int main()
{
    string s = "14 6 + 2 / 5 * 7 +";

    cout << postfix(s) << endl;
}