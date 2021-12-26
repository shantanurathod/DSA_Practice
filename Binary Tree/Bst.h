#include <iostream>

struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node *parent;
    };

struct Bst
{
    
    Node *root = nullptr;

    void insert(int n)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node;
            newNode->data = n;
            newNode->left = newNode->right = newNode->parent = nullptr;
            root = newNode;
            return;
        }

        Node *temp = root;

        while (temp->left != nullptr || temp->right != nullptr)
        {
            if (n <= temp->data)
            {
                temp = temp->left;
            }

            else
            {
                temp = temp->right;
            }
        }

        Node *newNode = new Node;
        newNode->data = n;
        newNode->left = newNode->right = nullptr;
        newNode->parent = temp;
        if(n <= temp->data)
        {
            temp->left = newNode;
        }

        else
        {
            temp->right = newNode;
        }
    }

    Node* search(int n)
    {
        Node *temp = root;

        while (temp->left != nullptr || temp->right != nullptr)
        {

            if(n == temp->data)
            {
                return temp;
            }

            else if (n < temp->data)
            {
                temp = temp->left;
            }

            else
            {
                temp = temp->right;
            }
        }

        if(temp->data == n)
        {
            return temp;
        }

        return nullptr;
    }

    void deleteNode(int n)
    {

    }

    static void print(Node* root_)
    {

        if(root_ == nullptr)
        {
            std::cout << "recursive" << std::endl;
            return;
        }

        std::cout << "start" << std::endl;
        print(root_->left);
        std::cout << root_->data << " ";
        print(root_->right);

    }

};


