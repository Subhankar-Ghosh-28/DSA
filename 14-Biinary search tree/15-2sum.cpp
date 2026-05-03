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

class BSTIterator
{
    // TC: O(1) for hasNext() and next() for n(total operation) / n = 1
    // SC: O(h) where h is height of BST for stack
private:
    stack<Node *> myStack;
    // reverse->true->before;
    //  reverse->false->next;
    bool reverse = true;

public:
    BSTIterator(Node *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        Node *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse)
            pushAll(tmpNode->right);
        else
            pushAll(tmpNode->left);
        return tmpNode->data;
    }

    void pushAll(Node *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            if (!reverse)
                node = node->left;
            else
                node = node->right;
        }
    }
};

class Solution
{
private:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    bool twoSum(vector<int> &arr, int key)
    {
        int n = arr.size();

        int l = 0, r = n - 1;

        while (l < r)
        {
            int sum = arr[l] + arr[r];

            if (sum == key)
            {
                return true;
            }
            else if (sum > key)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return false;
    }

public:
    bool bruteForce(Node *root, int k)
    {
        if (!root)
            return true;

        vector<int> ans;

        inorder(root, ans);

        return twoSum(ans, k);

        // TC-> O(n) + O(n);
        // SC->O(N);
    }

    bool optimal(Node *root, int k)
    {
        if (!root)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next(), j = r.next();

        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (j + j < k)
                i = l.next();
            else
                j = r.next();
        }
        return false;

        // TC-> O(n);
        // SC->O(H);
    }
};

int main()
{
    // Create a sample BST
    //       7
    //      / \
    //     3   15
    //    / \   / \
    //   1   5 9  20

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    Solution sol;

    int k = 200;
    bool flag = sol.optimal(root, k);

    if (flag)
        cout << "The sum of the " << k << " is present in the BST" << endl;
    else
        cout << "The sum of the " << k << " is not present in the BST" << endl;
    return 0;
}