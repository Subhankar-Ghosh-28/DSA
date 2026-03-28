#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int key)
    {
        data = key;
        left = nullptr;
        right = nullptr;
    }
};

class Recursive
{
public:
    void PreOrder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right); //
    }

    void Inorder(Node *root)
    {
        if (root == NULL)
            return;

        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    void PostOrder(Node *root)
    {
        if (root == NULL)
            return;

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
};

class LevelOrderTravarse
{
public:
    vector<vector<int>> LevelOrder(Node *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<Node *> q;

        q.push(root);

        while (!q.empty())
        {
            int size = q.size();

            vector<int> level;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                level.push_back(node->data);

                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            ans.push_back(level);
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

    root->right->left = new Node(8);

    Recursive sol;

    cout << "Pre-order traversal : ";
    sol.PreOrder(root);
    cout << endl;

    cout << "In-order traversal : ";
    sol.Inorder(root);
    cout << endl;

    cout << "Post-order traversal : ";
    sol.PostOrder(root);
    cout << endl;

    LevelOrderTravarse solu;

    vector<vector<int>> result = solu.LevelOrder(root);

    cout << "Level Order Traversal of Tree: ";

    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout<<endl;
    }

    return 0;
}