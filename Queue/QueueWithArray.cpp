#include <iostream>
#define n 20
using namespace std;

struct Queue
{
    int *arr = new int[n];
    int front = -1;
    int back = -1;

    void enqueue(int num)
    {
        if (back < n - 1)
        {
            back++;
            arr[back] = num;

            if (front == -1)
            {
                front++;
            }
        }
    }

    void dequeue()
    {
        if(front != -1 || front <= back)
        {
        front++;
        }
    }

    int peek()
    {
        if(front != -1 || front <= back)
        {
        return arr[front];
        }
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    void print()
    {
        if (front != -1)
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Queue q;

    int a[] = {1, 2, 3, 4, 5};

    for (auto x : a)
    {
        q.enqueue(x);
    }

    q.print();

    q.dequeue();

    q.print();

    cout << q.empty() << " " << q.peek();
}