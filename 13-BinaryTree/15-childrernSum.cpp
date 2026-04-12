#include <bits/stdc++.h>
using namespace std;

// value of root node is sum of it left and right child node
// increase the value of children node by +1 times anytime

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

class Solution
{
public:
    void changeBT(Node *root)
    {
        if (!root)
            return;

        int child = 0;

        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;

        if (child >= root->data)
            root->data = child;
        else if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;

        changeBT(root->left);
        changeBT(root->right);

        int total = 0;

        if (root->left)
            total += root->left->data;
        if (root->right)
            total += root->right->data;

        if (root->left || root->right)
            root->data = total;
    }
};

void inorderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{

    Node *root = new Node(40);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(2);
    root->left->right = new Node(3);
    root->right->left = new Node(30);
    root->right->right = new Node(10);

    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    Solution sol;

    sol.changeBT(root);

    cout << "Binary Tree after Children Sum Property: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}