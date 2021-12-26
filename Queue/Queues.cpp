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

        if (stk.size() == 1)
        {
            return stk.top();
        }

        int top = stk.top();
        stk.pop();
        int front_ = front();
        stk.push(top);

        return front_;
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

    q.print();
    
    q.dequeue();

    q.print();
    
    cout << endl;

    cout << q.front();
}