#include <iostream>
#include <queue>

constexpr char ENDL = '\n';
using std::cin;
using std::cout;
using std::endl;

class Node
{
public:
    int data;
    Node *right;
    Node *left;

    Node() : data(0), right(nullptr), left(nullptr) {}

    Node(int d) : data(d), right(nullptr), left(nullptr) {}
};

Node *BuildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return nullptr;
    }

    Node *new_node = new Node(d);
    new_node->left = BuildTree();
    new_node->right = BuildTree();
    return new_node;
}

void PrintPre(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    cout << temp->data << " ";
    PrintPre(temp->left);
    PrintPre(temp->right);
}

void PrintIn(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    PrintIn(temp->left);
    cout << temp->data << " ";
    PrintIn(temp->right);
}

void PrintPost(Node *temp)
{
    if (temp == nullptr)
    {
        return;
    }

    PrintPost(temp->left);
    PrintPost(temp->right);
    cout << temp->data << " ";
}
void PrintLevel(Node *root)
{
    std::queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp != nullptr)
        {
            cout << temp->data << " ";
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }

            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
        }

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
    }
}

Node* LevelOrderBuild()
{
    std::queue<Node*> q;
    Node *root = nullptr;

    int n;
    cin >> n;

    if(n >= 0)
    {
        root = new Node;
        root->data = n;
        q.push(root);
    }
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cin >> n;

        if (n >= 0)
        {
           temp->left = new Node;
           temp->left->data = n;
           q.push(temp->left);
        }
        else
        {
            temp->left = nullptr;
        }

        cin >> n;

        if (n >= 0)
        {
           temp->right = new Node;
           temp->right->data = n;
           q.push(temp->right);
        }
        else
        {
            temp->left = nullptr;
        }
    }

    return root;
}
// 1 2 3 4 -1 -1 5 7 -1 8 9
// 1 2 -1 -1 3 4 -1 -1 5 -1 -1
// 1 2 3 -1 -1  4 5 -1 -1  -1 -1
// 1 2 3 4 5 -1 -1 -1 -1 -1 -1
int main()
{
    //Node *root = BuildTree();
    Node* root = LevelOrderBuild();
    PrintPre(root);
    cout << endl;
    // PrintIn(root);
    // cout << endl;
    // PrintPost(root);
    // cout << endl;
    // PrintLevel(root);
    return 0;
}
