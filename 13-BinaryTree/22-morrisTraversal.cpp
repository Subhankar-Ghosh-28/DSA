#include <bits/stdc++.h>
using namespace std;

// it is based on threaded binary tree theory connect left subtree right most connect to root nodes
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
    vector<int> morrisPreorder(Node *root)
    {
        if (NULL == root)
            return {};
        Node *curr = root;
        vector<int> ans;

        while (curr != NULL)
        {
            if (NULL == curr->left)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (NULL == prev->right)
                {
                    prev->right = curr;
                    ans.push_back(curr->data);
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

    vector<int> morrisInorder(Node *root)
    {
        if (NULL == root)
            return {};
        Node *curr = root;
        vector<int> ans;

        while (curr != NULL)
        {
            if (NULL == curr->left)
            {
                ans.push_back(curr->data);
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (NULL == prev->right)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        return ans;
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

    Solution sol;

    vector<int> preorder = sol.morrisPreorder(root);

    cout << "Binary Tree Morris Preorder Traveral: ";
    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }
    cout << endl;

    vector<int> inorder = sol.morrisInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}