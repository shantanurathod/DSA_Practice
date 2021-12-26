#include <iostream>
#include <stack>
//#include "../Stack/Stack_o.h"

using namespace std;

//template <typename int>
struct Queue
{
    stack<int> stk;

    void enqueue(int n)
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

        int top = stk.top();
        stk.pop();
        dequeue();
        stk.push(top);
    }

    int front()
    {
        if (stk.empty())
        {
            cout << "empty" << endl;
            return -1;
        }
        cout << "stk.size() " << stk.size() << endl;
        if (stk.size() == 1)
        {
            int out = stk.top();
            bool index = stk.empty();
            cout << "out " << out << " bool " << index << endl;
            return 10;
            cout << "return" << endl;
        }

        int top = stk.top();
        cout << "->" << top << " ";
        stk.pop();
        front();
        stk.push(top);
    }

    void print()
    {
        if (stk.empty())
        {
            cout << endl;
            return;
        }

        int top = stk.top();
        stk.pop();
        print();
        cout << top << " ";
        stk.push(top);
    }
};

int main()
{
    Queue q;

    int arr[] = {1, 2, 3, 4, 5};

    for (auto x : arr)
    {
        q.enqueue(x);
    }

    int front = q.front();
    cout << "f" << front << endl;
    
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
    q.print();
}