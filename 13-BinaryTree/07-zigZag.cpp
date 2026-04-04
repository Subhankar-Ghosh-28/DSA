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
    vector<vector<int>> zigZag(Node *root)
    {
        vector<vector<int>> result;

        if (root == NULL)
        {
            return result;
        }

        queue<Node *> q;

        q.push(root);
        bool flag = true;
        while (!q.empty())
        {
            int size = q.size();

            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();

                int index = (flag) ? i : (size - 1 - i);

                level[index] = curr->data;

                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
            flag = !flag;
            result.push_back(level);
        }
        return result;
    }
};

void printVector(const vector<int> &arr)
{

    for (auto node : arr)
    {
        cout << node << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    Solution sol;

    vector<vector<int>> result = sol.zigZag(root);

    cout << "Zig zag Traversal of Binary Tree: " << endl;

    for (auto x : result)
    {
        printVector(x);
    }
    return 0;
}