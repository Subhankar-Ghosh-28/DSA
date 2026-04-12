#include <bits/stdc++.h>
using namespace std;

// check a tree is complete binary tree or not

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
    bool isCBT(Node *root)
    {
        if (!root)
            return true;

        queue<Node *> q;
        q.push(root);
        bool nullSeen = false;
        while (!q.empty())
        {
            Node *curr = q.front();

            q.pop();

            if (curr == nullptr)
                nullSeen = true;

            else
            {
                if (nullSeen)
                    return false;

                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Solution sol;

    if (sol.isCBT(root))
    {
        cout << "The tree is a complete binary tree." << endl;
    }
    else
    {
        cout << "The tree is not a complete binary tree." << endl;
    }
    return 0;
}