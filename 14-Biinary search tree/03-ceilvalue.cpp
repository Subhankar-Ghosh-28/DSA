#include <bits/stdc++.h>
using namespace std;
// ceil is lowest value >= key

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
    int ceilValue(Node *root, int key)
    {
        int ceil = -1;

        while (root)
        {
            if (root->data == key)
            {
                ceil = root->data;
                return ceil;
            }
            if (root->data >= key)
            {
                ceil = root->data;
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        return ceil;
    }
};

void printInOrder(Node *root)
{

    if (root == nullptr)
        return;

    printInOrder(root->left);

    cout << root->data << " ";

    printInOrder(root->right);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(13);
    root->left->left = new Node(3);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(4);
    root->left->right = new Node(6);
    root->left->right->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(14);

    cout << "Binary Search Tree (Inorder): " << endl;
    printInOrder(root);
    cout << endl;

    Solution solution;

    int target = 8;
    int floorVal = solution.ceilValue(root, target);

    if (floorVal != -1)
    {
        cout << "Ceil of " << target << " is: " << floorVal << endl;
    }
    else
    {
        cout << "No Ceil found!" << endl;
    }

    return 0;
}