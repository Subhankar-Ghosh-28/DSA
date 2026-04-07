#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int key) : data(key), left(nullptr), right(nullptr) {}
};

class Solution
{
    int getHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        return max(lh, rh) + 1;
    }

public:
    bool bruteForce(Node *root)
    {
        if (root == nullptr)
        {
            return true;
        }

        int lh = getHeight(root->left);
        int rh = getHeight(root->right);

        if (abs(lh - rh) <= 1 && bruteForce(root->left) && bruteForce(root->right))
        {
            return true;
        }

        return false;

        // TC-> O(N*N) n for height and n for every time check left and right;
        // sc -> O(H)
    }

    bool optimal(Node *root)
    {
        return dfsHeight(root) != -1; // if height not  balanced it produces -1 other wise the height of the BT
    }

    int dfsHeight(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = dfsHeight(root->left);
        if (lh == -1)
            return -1;

        int rh = dfsHeight(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;
        return max(lh, rh) + 1;
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

    if (solution.optimal(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }
    return 0;
}