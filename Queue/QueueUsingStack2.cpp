#include <iostream>
#include <stack>
//#include "../Stack/Stack_o.h"

using namespace std;

template <typename T>
struct Queue
{
    stack<T> stk;

    void enqueue(T n)
    {
        stk.push(n);
    }

    void dequeue()
    {
        if (stk.empty())
        {
            return;
        }

        if (stk.size() == 1)
        {
            stk.pop();
            return;
        }

        T top = stk.top();
        stk.pop();
        dequeue();
        stk.push(top);
    }

    T front()
    {
        if (stk.empty())
        {
            cout << "empty" << endl;
            return -1;
        }

        if (!stk.size() == 1)
        {
            T top = stk.top();
            cout << "->" << top << " ";
            stk.pop();
            front();
            stk.push(top);
        }

        T out = stk.top();
        bool index = stk.empty();
        cout << "out " << out << " bool " << index << endl;
        return out;
    }

    void print()
    {
        if (stk.empty())
        {
            cout << endl;
            return;
        }

        T top = stk.top();
        stk.pop();
        print();
        cout << top << " ";
        stk.push(top);
    }
};

int main()
{
    Queue<int> q;

    int arr[] = {1, 2, 3, 4, 5};

    for (auto x : arr)
    {
        q.enqueue(x);
    }

    cout << "f" << (q.front()) << endl;

    q.print();

    q.print();

    cout << endl;

    q.dequeue();

    q.print();
    cout << endl;

    q.dequeue();

    q.print();
    cout << endl;

    cout << q.front() << endl;

    q.enqueue(6);

    q.print();
    q.enqueue(7);
    cout << q.front() << endl;
    ;
    q.print();
}