#include <iostream>

struct Node
{
    int data;
    Node *next;
    
};

struct Stack
{
     Node * head = nullptr;

  void push(Node **headref, int newData)
    {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = *headref;
        *headref = newNode;
    }

    void pop(Node **headref)
    {
        if(*headref == nullptr)
            return;

        Node *temp = *headref;
        *headref = (*headref)->next;
        delete temp;    
    }

    int top(Node **headref)
    {
        return (*headref)->data;
    }

    bool isEmpty(Node **headref)
    {
        return (*headref == nullptr);
    }

    int size(Node **headref)
    {
        int count = 0;
        Node *temp = *headref;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }
        
        return count;
    }

    void print(Node **headref)
    {
        Node *temp = *headref;
        std::cout << "||->";

        while(temp != nullptr)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }

        std::cout << "X" <<std::endl;
    }

};


