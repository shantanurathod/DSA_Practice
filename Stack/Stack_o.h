#include <iostream>

template <typename T>
struct Stack
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *head = nullptr;

    void push(T newData)
    {
        Node *newNode = new Node;
        newNode->data = newData;
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (head == nullptr)
            return;

        Node *temp = head;
        head = (head)->next;
        delete temp;
    }

    T top()
    {
        return head->data;
    }

    bool isEmpty()
    {
        return (head == nullptr);
    }

    T size()
    {
        T count = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void print()
    {
        Node *temp = head;
        std::cout << "||->";

        while (temp != nullptr)
        {
            std::cout << temp->data << "->";
            temp = temp->next;
        }

        std::cout << "X" << std::endl;
    }
};
