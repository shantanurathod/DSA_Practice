#include <iostream>
#include "Stack_o.h"
#include <vector>

void reverse(std::string s)
{
    Stack<std::string> stk;

    for(int i = 0; i < s.length(); i++)
    {
        
        std::string word = "";

        while(s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;  
        }

        stk.push(word);
    }

    while(!stk.isEmpty())
    {
    std::cout << stk.top() << " ";
    stk.pop();
    }
}

int main()
{
    std::string s = "hey, how you doing?";

    reverse(s);
}