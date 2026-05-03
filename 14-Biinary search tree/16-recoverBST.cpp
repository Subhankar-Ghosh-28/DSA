#include <bits/stdc++.h>
using namespace std;

// in BST there is swap to node, we correct the node

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
private:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    void inorderhelp(Node *root, vector<int> inorder, int &i)
    {
        if (!root)
            return;

        inorderhelp(root->left, inorder, i);
        root->data = inorder[i++];
        inorderhelp(root->right, inorder, i);
    }

public:
    void bruteForce(Node *root)
    {
        if (!root)
            return;

        vector<int> arr1;
        inorder(root, arr1);

        sort(arr1.begin(), arr1.end());

        int i = 0;
        inorderhelp(root, arr1, i);

        // TC-> O(2N) + O(nlog N);
    }

private:
    Node *first = nullptr;
    Node *prev = nullptr;
    Node *middle = nullptr;
    Node *last = nullptr;

    void inorder(Node *root)
    {
        if (!root)
            return;

        inorder(root->left);

        if (prev != NULL && (root->data < prev->data))
        {

            // first violateion
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            // second violation
            else
                last = root;
        }
        prev = root;
        inorder(root->right);
    }

public:
    void optimal(Node *root)
    {
        if (!root)
            return;

        first = middle = last = NULL;

        prev = new Node(INT_MIN);
        inorder(root);

        // if the swaped gay at different
        if (first && last)
            swap(first->data, last->data);

        // if the 2 swapped are adjacent
        else if (first && middle)
            swap(first->data, middle->data);

        // TC-> O(N)
        // Sc-> O(1) exclude stack reecursive space
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
    // Create a sample BST with swapped nodes
    //       7
    //      / \
    //     9   15
    //    / \   / \
    //   1   5 3  20

    Node *root = new Node(7);
    root->left = new Node(9);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(3);
    root->right->right = new Node(20);

    Solution sol;

    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << "\n";

    sol.optimal(root);

    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << "\n";

    return 0;
}