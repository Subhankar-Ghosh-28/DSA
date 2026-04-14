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

class Solution1
{

    Node *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &inorderMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        Node *root = new Node(preorder[preStart]);

        int inRoot = inorderMap[root->data];

        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inorderMap);

        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

public:
    Node *FromPreAndInorder(vector<int> preorder, vector<int> inorder)
    {
        map<int, int> inorderMap;

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        Node *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);

        return root;

        // TC-> O(N) sc-> O(N)
    }
};

class Solution2
{
    Node *buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postOrder, int postStart, int postEnd, map<int, int> &inorderMap)
    {
        if (inStart > inEnd || postStart > postEnd)
        {
            return NULL;
        }

        Node *root = new Node(postOrder[postEnd]);

        int inRoot = inorderMap[root->data];

        int numsLeft = inRoot - inStart;

        root->left = buildTree(inorder, inStart, inRoot - 1, postOrder, postStart, postStart + numsLeft - 1, inorderMap);

        root->right = buildTree(inorder, inRoot + 1, inEnd, postOrder, postStart + numsLeft, postEnd - 1, inorderMap);

        return root;
    }

public:
    Node *FromInAndPostorder(vector<int> inorder, vector<int> postorder)
    {
        map<int, int> inorderMap;

        for (int i = 0; i < inorder.size(); i++)
        {
            inorderMap[inorder[i]] = i;
        }
        Node *root = buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);

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
    vector<int> postorder = {9, 15, 7, 20, 3};

    Solution1 sol1;
    Node *root1 = sol1.FromPreAndInorder(preorder, inorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root1);
    cout << endl;

    Solution2 sol2;
    Node *root2 = sol2.FromInAndPostorder(inorder, postorder);

    cout << "Inorder of Unique Binary Tree Created:\n";
    printInorder(root2);
    cout << endl;
    return 0;
}