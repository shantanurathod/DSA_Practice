#include <iostream>
#include "Bst.h"
constexpr char ENDL = '\n';
using std::cout;
using std::cin;
using std::endl;

int main()
{

Bst tree;

tree.insert(100);
tree.insert(90);
tree.insert(300);

cout << tree.root->data << endl;
// cout << tree.root->right->data << endl;
// cout << tree.root->right->right->data << endl;

Bst::print(tree.root);

cout << tree.search(300) << endl;
return 0;
}