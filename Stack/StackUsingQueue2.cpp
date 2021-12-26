#include <iostream>
#include "../Queue/Queue.h"

using namespace std;

template <typename T>
struct Stack
{
    Queue<T> q;

    void push(T n)
    {
        q.enqueue(n);
    }

    void pop()
    {
        if (q.empty())
        {
            return;
        }

        if (!(q.front == q.back))
        {
            T last = q.peek();
            q.dequeue();
            pop();
            q.enqueue(last);
        }

        q.dequeue();
        return;
    }

    T top()
    {
        if (q.empty())
        {
            return -1;
        }

        if (q.front == q.back)
        {
            T last = q.peek();
            q.dequeue();
            pop();
            q.enqueue(last);
        }

        return q.peek();
    }

    void print()
    {
        q.print();
    }
};

int main()
{
    Stack<int> stk;

    int a[] = {1, 2, 3, 4, 5};

    for (auto x : a)
    {
        stk.push(x);
    }

    stk.print();

    stk.pop();

    stk.print();

    stk.pop();

    stk.print();

    cout << stk.top();
}