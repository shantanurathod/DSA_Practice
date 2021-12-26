#include <iostream>
#include "../Stack/Stack_o.h"

using namespace std;

template <typename T>
struct Queue
{
    Stack<T> stk1;
    Stack<T> stk2;

    void enqueue(T n)
    {
        stk1.push(n);
    }

    void dequeue()
    {
        if (stk1.isEmpty() && stk2.isEmpty())
        {
            return;
        }

        reverse(stk1,stk2);
        stk2.pop();
        reverse(stk1,stk2);
    }

    T front()
    {
        if (stk1.isEmpty())
        {
            return stk2.top();
        }

        reverse(stk1, stk2);

        T res = stk2.top();

        reverse(stk1, stk2);

        return res;
    }

    bool empty()
    {
        if(stk1.isEmpty() && stk2.isEmpty())
        {
            return true;
        }

        return false;
    }

    void print()
    {
        reverse(stk1, stk2);
        stk2.print();
        reverse(stk2, stk1);
    }

private:
    void reverse(Stack<T> &s1, Stack<T> &s2)
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        else
        {
            while (!s2.isEmpty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
};

int main()
{
    Queue<int> q;

    int arr[] = {1, 2, 3, 4, 5};

    for(auto x: arr)
    {
        q.enqueue(x);
    }

    q.print();

    q.dequeue();

    q.print();

    q.dequeue();

    q.print();

    cout << q.front() << endl;

    q.enqueue(6);

    q.print();
    
}