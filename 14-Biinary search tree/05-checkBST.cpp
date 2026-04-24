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
    bool isValid(Node *root)
    {
        return isValid(root, INT_MIN, INT_MAX);
    }

    bool isValid(Node *root, int minval, int maxVal)
    {
        if (root == NULL)
            return true;
        if (root->data >= maxVal || root->data <= minval)
            return false;
        return isValid(root->left, minval, root->data) && isValid(root->right, root->data, maxVal);
    }

    // TC -> O(N) ,, SC-> O(1);
};

int main()
{
    Solution sol;

    // Test Case 1: Valid BST
    //       10
    //      /  \
    //     5    15
    //    / \   / \
    //   3   7 12  20
    Node *root1 = new Node(10);
    root1->left = new Node(5);
    root1->right = new Node(15);
    root1->left->left = new Node(3);
    root1->left->right = new Node(7);
    root1->right->left = new Node(12);
    root1->right->right = new Node(20);

    cout << "Test Case 1 (Valid BST): " << (sol.isValid(root1) ? "TRUE" : "FALSE") << endl;

    // Test Case 2: Invalid BST
    //       10
    //      /  \
    //     5    15
    //    / \   / \
    //   3  20 12  20  <- 20 in left subtree violates BST property
    Node *root2 = new Node(10);
    root2->left = new Node(5);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(20); // Invalid: > 10
    root2->right->left = new Node(12);
    root2->right->right = new Node(20);

    cout << "Test Case 2 (Invalid BST): " << (sol.isValid(root2) ? "TRUE" : "FALSE") << endl;

    // Test Case 3: Single node
    Node *root3 = new Node(5);
    cout << "Test Case 3 (Single node): " << (sol.isValid(root3) ? "TRUE" : "FALSE") << endl;

    // Test Case 4: Invalid - right child smaller than left child
    //       10
    //      /  \
    //     5    3  <- Invalid: right < root
    Node *root4 = new Node(10);
    root4->left = new Node(5);
    root4->right = new Node(3);

    cout << "Test Case 4 (Invalid - right < root): " << (sol.isValid(root4) ? "TRUE" : "FALSE") << endl;

    // Test Case 5: Valid right skewed BST
    //    1
    //     \
    //      2
    //       \
    //        3
    Node *root5 = new Node(1);
    root5->right = new Node(2);
    root5->right->right = new Node(3);

    cout << "Test Case 5 (Right skewed BST): " << (sol.isValid(root5) ? "TRUE" : "FALSE") << endl;

    return 0;
}