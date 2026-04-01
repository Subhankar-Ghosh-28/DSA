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
    int dfs(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        return max(lh, rh) + 1;
    }

public:
    int diameter = 0;
    void bruteForce(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        diameter = max(diameter, lh + rh);
        bruteForce(root->left);
        bruteForce(root->right);

        // TC -> O(N*N)
    }

    int optimal(Node *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = optimal(root->left, diameter);
        int rh = optimal(root->right, diameter);

        diameter = max(diameter, lh + rh);

        return max(lh, rh) + 1;

        // TC-> O(N);
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    solution.bruteForce(root);
    // int diameter = solutiom.diameter
    int diameter = 0;

    solution.optimal(root, diameter);

    cout << "The diameter of the binary tree is: " << diameter << endl;
    return 0;
}