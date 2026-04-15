#include <bits/stdc++.h>
using namespace std;
// flattern BT to LL
//  arrange the BT nodes to preorder linked list the node right and left is null;

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

class flattern
{
public:
    Node *prev = nullptr;
    void recursive(Node *root)
    {
        if (root == nullptr)
            return;

        recursive(root->right);
        recursive(root->left);

        root->right = prev;
        root->left = nullptr;
        prev = root;

        // TC-> O(N) sc-> O(N)
    }

    void iterative(Node *root)
    {
        if (root == nullptr)
            return;

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {
            Node *curr = st.top();
            st.pop();

            if (curr->right)
            {
                st.push(curr->right);
            }

            if (curr->left)
            {
                st.push(curr->left);
            }

            if (!st.empty())
            {
                curr->right = st.top();
                curr->left = nullptr;
            }
        }
        // TC-> O(N) sc-> O(N)
    }

    void optimal(Node *root)
    {
        if (root == nullptr)
            return;

        Node *curr = root;

        while (curr)
        {
            if (curr->left)
            {
                Node *prev = curr->left;

                while (prev->right)
                {
                    prev = prev->right;
                }

                prev->right = curr->right;
                curr->right = curr->left;
            }

            curr = curr->right;
        }
        // TC-> O(N) sc-> O(1)
    }
};

void printPreorder(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    printPreorder(root->left);

    printPreorder(root->right);
}

void printFlattenTree(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";

    printFlattenTree(root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(8);

    flattern sol;

    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    sol.optimal(root);

    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout << endl;
    return 0;
}