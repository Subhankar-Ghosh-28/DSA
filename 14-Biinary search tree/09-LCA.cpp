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
    Node *LCAiterative(Node *root, Node *p, Node *q)
    {
        if (!root)
            return NULL;

        Node *curr = root;
        while (curr)
        {
            if (curr->data < p->data && curr->data < q->data)
            {
                curr = curr->right;
            }
            else if (curr->data > p->data && curr->data > q->data)
            {
                curr = curr->left;
            }
            else
            {
                return curr;
            }
        }
        return NULL;

        // TC->O(H),, SC->O(1);
    }

    Node *LCARecursive(Node *root, Node *p, Node *q)
    {
        if (!root)
            return NULL;
        int curr = root->data;
        if (curr < p->data && curr < q->data)
        {
            return LCARecursive(root->right, p, q);
        }
        if (curr > p->data && curr > q->data)
        {
            return LCARecursive(root->left, p, q);
        }
        return root;
        // TC->O(H),, SC->O(n) stack space;
    }
};

int main()
{
    Solution sol;

    // Create a sample BST
    //       6
    //      / \
    //     2   8
    //    / \
    //   0   4

    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);

    Node *p = root->left->left;  // Node with value 0
    Node *q = root->left->right; // Node with value 4

    Node *lca = sol.LCARecursive(root, p, q);

    cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    // Test case 2: LCA of 0 and 8
    p = root->left->left; // Node with value 0
    q = root->right;      // Node with value 8

    lca = sol.LCARecursive(root, p, q);
    cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}