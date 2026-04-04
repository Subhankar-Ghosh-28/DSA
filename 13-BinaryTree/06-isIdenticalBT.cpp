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

class Solution
{
public:
    bool isIdentical(Node *p, Node *q)
    {
        if (p == NULL || q == NULL)
        {
            return p == q;
        }
        return ((p->data == q->data) && (isIdentical(p->left, q->left)) && (isIdentical(p->right, q->right)));
    }

    //TC->O(N)
};

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);

    Solution solution;

    if (solution.isIdentical(root1, root2))
    {
        cout << "The binary trees are identical." << endl;
    }
    else
    {
        cout << "The binary trees are not identical." << endl;
    }
    return 0;
}