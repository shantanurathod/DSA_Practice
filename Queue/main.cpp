#include <iostream>
#include "Queue.h"

constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

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

cout << q.peek() << " " << q.empty() << endl;

cin.get();
return 0;
}