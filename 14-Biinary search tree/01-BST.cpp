#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

// BSt is a  special type of bianry tree where the left node value is less than parent
// and right node value is > parent;

int main()
{
    Node *root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);

    return 0;
}