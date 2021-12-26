#include "linkedlist.h"

void insertFront(Node **myhead, int newData)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->next = *myhead;
    newNode->data = newData;

    *myhead = newNode;
}

void insert(Node **headref, int newData)
{
    if (*headref == nullptr)
    {
        insertFront(&(*headref), newData);
        //std::cout << "In if";
        return;
    }

    Node * temp = *headref;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    insertFront(&(temp->next), newData);
}

void insert(Node *temp, int newData, int pos, Node **myhead)
{
    if (pos == 0)
    {
        insertFront(myhead, newData);
        return;
    }

    for (int i = 0; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));

    newNode->next = temp->next;

    temp->next = newNode;

    newNode->data = newData;

    return;
}

void overwrite(Node *temp, int pos, int newData)
{
    for (int i = 0; temp != nullptr && i < pos; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return;
    }

    temp->data = newData;
    return;
}

void printList(Node *temp)
{

    std::cout << "|| head -> ";
    while (temp != nullptr)
    {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "|| XX " << ENDL;
}

Node *build(int n)
{
    Node *head = nullptr;
    insertFront(&head, 1);
    Node *tail = head;

    for (int i = 2; i <= n; i++)
    {
        insertFront(&(tail->next), i);
        tail = tail->next;
    }

    return head;
}

void deleteNode(Node **myhead, int pos)
{
    if (*myhead == nullptr)
    {
        return;
    }

    Node *temp = *myhead;

    if (pos == 0)
    {

        *myhead = temp->next;
        free(temp);

        return;
    }

    for (int i = 0; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }

    Node *next = temp->next;

    temp->next = temp->next->next;
    free(next);

    return;
}
