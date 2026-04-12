#include <bits/stdc++.h>
using namespace std;

// count node of a complete binary tree;

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
    int heightLeft(Node *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;

        // TC -> O(log N), SC -> O(log N)
    }

    int heightRight(Node *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->right;
        }
        return height;

        // TC -> O(log N), SC -> O(log N)
    }

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

    int countNode(Node *root)
    {
        if (root == NULL)
            return 0;

        int lh = heightLeft(root);
        int rh = heightRight(root);

        if (lh == rh)
            return (1 << lh) - 1;

        return 1 + countNode(root->left) + countNode(root->right);

        // TC -> O(log N)*(log N), SC -> O(N)
    }

    int cntNodeCBT(Node *root)
    {

        if (!isCBT(root))
            return -1;

        int x = countNode(root);

        return x;

        // TC ->O(N) + O(log N)*(log N), SC -> O(N)
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
        cout << "Total node of the Complete tree is: " << sol.cntNodeCBT(root) << endl;
    }
    else
    {
        cout << "The tree is not a complete binary tree." << endl;
        cout << "Total node of the Complete tree is: " << sol.countNode(root) << endl;
    }
    return 0;
}