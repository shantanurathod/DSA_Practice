
template <typename T>
struct Queue
{
    struct Node
    {
        T data;
        Node *next;
    };

    Node *front = nullptr;
    Node *back = nullptr;

    void enqueue(T n)
    {
        Node* newNode = new Node;
        newNode->data = n;

        if (front == nullptr)
        {
            newNode->next = front;
            front = newNode;
            back = front;
            return;
        }

        newNode->next = back->next;
        back->next = newNode;
        back = newNode;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            return;
        }

        Node *temp = front;
        front = front->next;
        delete temp;
    }

    T peek()
    {
        if (front == nullptr)
        {
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == nullptr)
        {
            return true;
        }

        return false;
    }

    void print()
    {
        std::cout << "||->";

        if (front != nullptr)
        {
            Node *temp = front;
            while (temp != nullptr)
            {
                std::cout << temp->data << "->";
                temp = temp->next;
            }
        }

        std::cout << "X" << std::endl;
    }

};