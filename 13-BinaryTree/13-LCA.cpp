#include <bits/stdc++.h>
using namespace std;
// longest common ancestor
// The lowest common ancestor is defined between two nodes p and q as the lowest ancestor node in T
// that has both p and q as descendants (where we allow a node to be a descendant of itself).

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
    Node *LCA(Node *root, Node *p, Node *q)
    {
        if (!root || root == p || root == q)
            return root;

        Node *Left = LCA(root->left, p, q);
        Node *Right = LCA(root->right, p, q);

        if (Left == NULL)
            return Right;
        if (Right == NULL)
            return Left;
        return root;
    }
};

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    Solution solution;
    Node *p = root->left;  // Node with value 5
    Node *q = root->right; // Node with value 1

    Node *lca = solution.LCA(root, p, q);
    cout << "Lowest Common Ancestor: " << lca->data << endl;

    return 0;
}