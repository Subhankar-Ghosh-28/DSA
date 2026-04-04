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
    bool isLeaf(Node *node)
    {
        if (node->left == nullptr && node->right == nullptr)
            return true;
        return false;
    }
    void addLeftBoundary(Node *root, vector<int> &arr)
    {
        Node *curr = root->left;

        while (curr)
        {
            if (!isLeaf(curr))
                arr.push_back(curr->data);
            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void addLeaves(Node *root, vector<int> &arr)
    {
        if (isLeaf(root))
        {
            arr.push_back(root->data);
            return;
        }
        if (root->left)
            addLeaves(root->left, arr);
        if (root->right)
            addLeaves(root->right, arr);
    }

    void addRightboundaryReverse(Node *root, vector<int> &arr)
    {
        Node *curr = root->right;
        vector<int> temp;
        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);
            if (curr->left)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size() - 1; i >= 0; i--)
        {
            arr.push_back(temp[i]);
        }
    }

public:
    vector<int> boudaryTraverse(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;
        if (!isLeaf(root))
            result.push_back(root->data);
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightboundaryReverse(root, result);
        return result;
    }
    void printResult(const vector<int> &result)
    {
        for (int val : result)
        {
            cout << val << " ";
        }
        cout << endl;
    }  //TC->O(N) SC-> O(N)
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    vector<int> result = solution.boudaryTraverse(root);

    cout << "Boundary Traversal: ";
    solution.printResult(result);
    return 0;
}