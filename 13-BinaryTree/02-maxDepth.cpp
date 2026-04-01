#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key) : data(key), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);

        // Tc-> O(N),, SC -> O(n) // auxilary spacce we also use level order traversal and count max height
        // recursive is most optimal solution
    }
    
};

int main()
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution sol;

    cout << "Max depth of the bianry tree : " << sol.maxDepth(root);
    return 0;
}