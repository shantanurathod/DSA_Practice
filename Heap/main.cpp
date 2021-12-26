#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
    Heap h;
    int a[] = {52, 47, 40, 33, 29, 19, 25, 27};

    for(int i = 0; i < sizeof(a)/sizeof(int); i++)
    {
        h.insertAt(a[i]);
    }

    h.print();

    h.insertAt(63);

    h.print();

    cout << h.extractAt() << endl;

    h.print();
}