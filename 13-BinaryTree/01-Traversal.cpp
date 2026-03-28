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

    return 0;
}