#include "linkedlist.h"
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

int count(Node *temp, int a)
{
    int count = 0;
    while (temp != nullptr)
    {
        if (temp->data == a)
        {
            count++;
        }

        temp = temp->next;
    }

    return count;
}

int getNth(Node *temp, int index)
{
    for (int i = 0; temp != nullptr && i < index; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

void deleteList(Node **myhead)
{
    while (*myhead != nullptr)
    {
        Node *pre = *myhead;
        *myhead = (*myhead)->next;
        free(pre);
    }
}

int pop(Node **headref)
{
    int data = (*headref)->data;
    Node *pre = *headref;
    *headref = (*headref)->next;

    free(pre);

    return data;
}

void sortedInsert(Node *temp, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));

    while ((temp->next)->data <= data)
    {
        temp = temp->next;
    }

    newNode->data = data;
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertSort(Node *temp)
{
    for (Node *i = temp; i->next != nullptr; i = i->next)
    {
        for (Node *j = i->next; j != nullptr; j = j->next)
        {
            if (j->data < i->data)
            {
                int temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
}

void append(Node **headref1, Node **headref2)
{
    Node *i = *headref1;
    while (i->next != nullptr)
    {
        i = i->next;
    }

    i->next = *headref2;
    *headref2 = nullptr;
}

int length(Node *i)
{
    int n = 1;

    while (i->next != nullptr)
    {
        n++;
        i = i->next;
    }

    return n;
}

Node *frontbackSplit(Node **headref)
{
    int n = length(*headref);

    if (n % 2 == 0)
    {
        Node *temp = *headref;
        for (int i = 0; i < n / 2 - 1; i++)
        {
            temp = temp->next;
        }

        Node *back = temp->next;
        temp->next = nullptr;

        return back;
    }

    else
    {
        Node *temp = *headref;
        for (int i = 0; i < n / 2; i++)
        {
            temp = temp->next;
        }

        Node *back = temp->next;
        temp->next = nullptr;

        return back;
    }
}

void removeDuplicate(Node *temp)
{
    for (; temp->next != nullptr; temp = temp->next)
    {
        for (Node *j = temp; j->next != nullptr; j = j->next)
        {
            Node *ahead = j->next;
            if (temp->data == ahead->data)
            {
                j->next = ahead->next;
                free(ahead);
                ahead = j->next;

                if (j->next == nullptr)
                {
                    break;
                }
            }
        }
    }
}

void moveNode(Node **headref1, Node **headref2)
{
    Node *temp = *headref2;
    *headref2 = (*headref2)->next;

    temp->next = *headref1;
    *headref1 = temp;
}

void alternateSpilt(Node **source, Node **headref1, Node **headref2)
{

    int n = length(*source);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            moveNode(&(*headref2), &(*source));
        }

        else
        {
            moveNode(&(*headref1), &(*source));
        }
    }
}

void shuffleMerge(Node **headref1, Node **headref2, Node **des)
{

    int n = std::min(length(*headref1), length(*headref2));
    bool m = length(*headref1) >= length(*headref2);
    int l = length(*headref1) + length(*headref2);
    for (int i = 1; i <= l; i++)
    {

        if (i <= 2 * n)
        {
            if (i % 2 == 0)
            {
                moveNode(&(*des), &(*headref1));
            }

            else
            {
                moveNode(&(*des), &(*headref2));
            }
        }

        else
        {

            if (m)
            {
                moveNode(&(*des), &(*headref1));
            }

            else
            {
                moveNode(&(*des), &(*headref2));
            }
        }
    }
}

Node *sortedMerge(Node **headref1, Node **headref2)
{
    Node *des = nullptr;
    shuffleMerge(&(*headref1), &(*headref2), &des);
    insertSort(des);

    return des;
}

Node *sortedIntersect(Node *temp1, Node *temp2)
{

    Node *des = nullptr;
    // for (Node *i = temp1; i != nullptr; i = i->next)
    // {
    //     //cout << i->data << ENDL;
    //     for (Node *j = temp2; j != nullptr; j = j->next)
    //     {
    //         // cout << i->data << " " << j->data << ENDL;
    //         if (i->data == j->data)
    //         {
    //             insert(&des, j->data);
    //             count++;
    //         }
    //     }
    // }
    // complexity = n*m
    //
    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->data == temp2->data)
        {
            insert(&des, temp2->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        else if (temp1->data > temp2->data)
        {
            temp2 = temp2->next;
        }

        else
        {
            temp1 = temp1->next;
        }
    }

    //complexity of just above code = n + m
    return des;
}

void reverse(Node **headref)
{
    Node *t1 = *headref;
    Node *t2 = (*headref)->next;
    Node *t3 = t2->next;

    int n = length(*headref);

    (*headref)->next = nullptr;

    if (n % 3 == 0)
    {
        while (t1 != nullptr)
        {
            t2->next = t1;
            t1 = t3->next;
            t3->next = t2;

            if (t1 == nullptr)
            {
                *headref = t3;
            }

            else
            {
                t2 = t1->next;
                t1->next = t3;
                t3 = t2->next;
            }
        }
    }

    else if ((n + 2) % 3 == 0)
    {
        while (t2 != nullptr)
        {
            t2->next = t1;
            t1 = t3->next;
            t3->next = t2;
            t2 = t1->next;
            t1->next = t3;

            if (t2 == nullptr)
            {
                *headref = t1;
            }

            else
            {
                t3 = t2->next;
            }
        }
    }

    else if((n+1)%3 == 0)
    {
        while (t3 != nullptr)
        {
            t2->next = t1;
            t1 = t3->next;
            t3->next = t2;
            t2 = t1->next;
            t1->next = t3;
            t3 = t2->next;
            t2->next = t1;

            if (t3 == nullptr)
            {
                *headref = t2;
            }
        }
    }
}

int main()
{
    Node *head1 = nullptr;
    Node *head2 = nullptr;

    insert(&head1, 1);
    insert(&head1, 2);
    insert(&head1, 4);
    insert(&head1, 9);
    insert(&head1, 15);
    insert(&head1, 67);

    insert(&head2, 15);
    insert(&head2, 37);
    insert(&head2, 55);
    insert(&head2, 67);
    insert(&head2, 90);

    Node *des = sortedIntersect(head1, head2);

    printList(des);
    printList(head1);
    printList(head2);

    Node *source = build(19);

    reverse(&source);

    printList(source);

    cin.get();
    return 0;
}
