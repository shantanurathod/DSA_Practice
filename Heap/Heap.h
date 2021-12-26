#include <iostream>
#include <vector>
#include <cmath>

struct Heap
{
    std::vector<int> v; 

    void insertAt(int n)
    {
        v.push_back(n);
        
        heapify(v.size() - 1);
    }

    int extractAt()
    {
        if(v.size() == 0)
        {
            std::cout << "empty heap can't extract" << std::endl;
            return -1;
        }
        int n = v[0];

        v[0] = v[v.size() - 1];
        v.pop_back();

        heapifyTop();

        return n;
    }

    void print()
    {
        for(int i = 0; i < v.size(); i++)
            std::cout << v[i] << " ";

        std::cout << std::endl;    
    }

    private:

    int parent(int i)
    {
        return (i-1)/2;
    }

    int left(int i)
    {
        return i*2 + 1;
    }

    int right(int i)
    {
        return i*2 + 1;
    }

    void swap(int i1, int i2)
    {
        int temp = v[i1];
        v[i1] = v[i2];
        v[i2] = temp;
    }

    void heapify(int index)
    {
        while(v[index] > v[parent(index)])
        {
            swap(index, parent(index));
            index = parent(index);
        }
    }

    void heapifyTop()
    {   
        int index = 0;

        while(v[index] < std::max(v[left(index)],v[right(index)]))
        {
            if(v[right(index)] >= v[left(index)])
            {
                swap(index, right(index));
                index = right(index);
            }

            else
            {
                swap(index, left(index));
                index = left(index);
            }    
        }
    }
};


