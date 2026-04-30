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
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

public:
    int bruteForce(Node *root, int k)
    {
        if (!root)
            return -1;

        vector<int> in;
        inorder(root, in);

        int ans = -1;
        int low = 0, high = in.size() - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (in[mid] >= k)
            {
                high = mid - 1;
            }
            else
            {
                ans = in[mid];
                low = mid + 1;
            }
        }
        return ans;

        // Tc-> O(N) + O(log n);
        // sc-> O(n)
    }

    int optimal(Node *root, int k)
    {
        Node *prede = NULL;

        while (root)
        {
            if (root->data >= k)
            {
                root = root->left;
            }
            else
            {
                prede = root;
                root = root->right;
            }
        }
        return prede == NULL ? -1 : prede->data;

        // Tc-> O(N);
        // sc-> O(1);
    }
};

// inorder print helper
void printInOrder(Node *root)
{
    // base case
    if (root == nullptr)
        return;
    // left
    printInOrder(root->left);
    // node
    cout << root->data << " ";
    // right
    printInOrder(root->right);
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    // show BST inorder
    cout << "BST: ";
    printInOrder(root);
    cout << endl;

    // pick node p (value 4)
    int p = root->left->right->data;

    // compute predecessor
    Solution solution;
    int predecessor = solution.optimal(root, p);

    // print result
    if (predecessor != -1)
    {
        cout << "Inorder predecessor of " << p << " is: " << predecessor << endl;
    }
    else
    {
        cout << "Inorder predecessor of " << p << " does not exist." << endl;
    }
    return 0;
}