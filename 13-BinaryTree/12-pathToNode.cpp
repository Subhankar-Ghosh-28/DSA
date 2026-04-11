// print root to give leaf node path in BT

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

bool getPath(Node *root, vector<int> &arr, int x)
{
    if (root == NULL)
        return false;

    arr.push_back(root->data);

    if (root->data == x)
        return true;

    if (getPath(root->left, arr, x) || getPath(root->right, arr, x))
        return true;

    arr.pop_back();

    return false;
}

class Solution
{
public:
    vector<int> Solve(Node *root, int b)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        getPath(root, ans, b);

        return ans;

        // TC-> O(N) SC-> O(H);
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
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    Solution sol;

    int targetLeafValue = 7;

    vector<int> path = sol.Solve(root, targetLeafValue);

    // Print the path
    cout << "Path from root to node with value ";
    cout << targetLeafValue << ": ";

    for (int i = 0; i < path.size(); ++i)
    {
        cout << path[i];
        if (i < path.size() - 1)
        {
            cout << " -> ";
        }
    }
    return 0;
}