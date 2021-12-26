#include <iostream>
#include "Stack_o.h"

using namespace std;

void insertbottom(Stack<int> &s, int top)
{
    if (s.isEmpty())
    {
        s.push(top);
        return;
    }

    int top_int = s.top();
    s.pop();
    insertbottom(s, top);
    s.push(top_int);
}

void reverse(Stack<int> &s)
{
    if (s.isEmpty())
    {
        return;
    }

    int element = s.top();
    s.pop();
    reverse(s);
    insertbottom(s, element);
}

int main()
{
    Stack<int> stk;
    int a[] = {1, 2, 3, 4, 5};

    for (int i : a)
    {
        stk.push(i);
    }

    stk.print();

    reverse(stk);

    //cout << stk.isEmpty() << endl;
    stk.print();
}