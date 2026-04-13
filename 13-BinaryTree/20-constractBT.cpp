#include <bits/stdc++.h>
using namespace std;

// constarct binary tree from preorder and inorder traverse array;

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

    Node *bulidTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorderMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        Node *root = new Node(preorder[preStart]);

        int inRoot = inorderMap[root->data];

        int numsLeft = inRoot - inStart;

        root->left = bulidTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderMap);

        root->right = bulidTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

public:
    Node *FromPreAndInorer(vector<int> preorder, vector<int> inorder)
    {
        map<int, int> inorderMap;

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        Node *root = bulidTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);

        return root;

        // TC-> O(N) sc-> O(N)
    }
};

void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};

    Solution sol;
    Node *root = sol.FromPreAndInorer(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root);
    cout << endl;
    return 0;
}