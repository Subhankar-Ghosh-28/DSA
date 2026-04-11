// The maximum width of a Binary Tree is the maximum diameter among all its levels.
// The width or diameter of a level is the number of nodes between the leftmost and rightmost nodes.

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
    int widthBt(Node *root)
    {
        if (!root)
            return 0;

        int ans = 0;

        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            int size = q.size();
            int mini = q.front().second;
            int first, last;

            for (int i = 0; i < size; i++)
            {
                int curr = q.front().second - mini;

                Node *node = q.front().first;
                q.pop();

                if (i == 0)
                    first = curr;
                if (i == size - 1)
                    last = curr;

                if (node->left)
                    q.push({node->left, curr * 2 + 1});

                if (node->right)
                    q.push({node->right, curr * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
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

    Solution sol;

    cout << "Maximum width: " << sol.widthBt(root) << endl;

    return 0;
}