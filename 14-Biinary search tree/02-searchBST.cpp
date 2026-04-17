#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int key)
    {
        val = key;
        left = nullptr;
        right = nullptr;
    }
};

Node *searchBST(Node *root, int data)
{
    while (root != NULL && root->val != data)
    {
        root = data < root->val ? root->left : root->right;
    }
    return root;

    // TC-> O(log n)
    // sc-> O(1)
}

int main()
{
    Node *root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(15);

    // Test searchBST function
    int searchVal = 4;
    Node *result = searchBST(root, searchVal);

    if (result != NULL)
        cout << "Value " << searchVal << " found in BST" << endl;
    else
        cout << "Value " << searchVal << " NOT found in BST" << endl;

    // Test with another value
    searchVal = 10;
    result = searchBST(root, searchVal);

    if (result != NULL)
        cout << "Value " << searchVal << " found in BST" << endl;
    else
        cout << "Value " << searchVal << " NOT found in BST" << endl;

    // Test with non-existing value
    searchVal = 8;
    result = searchBST(root, searchVal);

    if (result != NULL)
        cout << "Value " << searchVal << " found in BST" << endl;
    else
        cout << "Value " << searchVal << " NOT found in BST" << endl;

    return 0;
}