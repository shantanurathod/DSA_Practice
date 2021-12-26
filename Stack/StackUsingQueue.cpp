#include <iostream>
#include "../Queue/Queue.h"

using namespace std;

//this method make push operation costly
// algo(push): 
//      insert element in q2,
//      insert all elements of q1 into q2,
//      swap q1 and q2
// algo(pop):
//      simply pop from q1

//another method which makes pop operation costly
// algo(push):
//      simply insert element in q1
// algo(pop):
//      insert element from q1 to q2 except last one
//      pop the remaining element in q1
//      swap q1 and q2

template <typename T>
struct Stack
{
    Queue<T> q1;
    Queue<T> q2;

    void push(T n)
    {
        q2.enqueue(n);

        while (!q1.empty())
        {
            q2.enqueue(q1.peek());
            q1.dequeue();
        }

        swap(q1, q2);
    }

    void pop()
    {
        if(q1.empty())
        {
            return;
        }

        q1.dequeue();
    }

    T top()
    {
        return q1.peek();
    }

    bool isEmpty()
    {
        if(q1.empty())
        {
            return true;
        }

        return false;
    }

    void print()
    {
        q1.print();
    }

    private:

    void swap(Queue<T> &q1, Queue<T> &q2)
    {
        while(!q2.empty())
        {
            q1.enqueue(q2.peek());
            q2.dequeue();
        }
    }
};

int main()
{
    Stack<int> stk;

    int a[] = {1, 2, 3, 4, 5};

    for(auto x: a)
    {
        stk.push(x);
    }

    stk.print();

    stk.pop();

    stk.print();
}