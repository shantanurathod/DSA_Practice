#include <iostream>
#include <queue>
#include <vector>

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
std::vector<std::vector<int>> PrintLevel(Node *root)
{
    std::vector<std::vector<int>> v_big;
    std::vector<int> v_in;
    std::queue<Node *> q;

    q.push(root);
    q.push(nullptr);

    if (root != nullptr)
    {
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp != nullptr)
            {
                v_in.push_back(temp->data);
                // cout << temp->data << " ";
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
                v_big.push_back(v_in);
                v_in.clear();
                // cout << endl;
                if (!q.empty())
                {
                    q.push(nullptr);
                }
            }
        }
    }

    return v_big;
}

// 1 2 3 4 -1 -1 5 7 -1 8 9
// 1 2 -1 -1 3 4 -1 -1 5 -1 -1
int main()
{
    Node *root = BuildTree();
    PrintPre(root);
    cout << endl;
    PrintIn(root);
    cout << endl;
    PrintPost(root);
    cout << endl;
    PrintLevel(root);
    return 0;
}
