#include <bits/stdc++.h>
using namespace std;

// first it constactor BSt iterator in root
// and next return the next node->data
// hasnext is bool fn thats tell next elemnt exicts or not

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

class BSTIterator
{
    // TC: O(1) for hasNext() and next() for n(total operation) / n = 1
    // SC: O(h) where h is height of BST for stack
private:
    stack<Node *> myStack;

public:
    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        return !myStack.empty();
    }

    int next()
    {
        Node *tmpNode = myStack.top();
        myStack.pop();
        pushAll(tmpNode->right);
        return tmpNode->data;
    }

    void pushAll(Node *node)
    {
        for (; node != NULL; myStack.push(node), node = node->left)
            ;
    }
};

int main()
{
    // Create a sample BST
    //       7
    //      / \
    //     3   15
    //    / \   / \
    //   1   5 9  20

    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->left->left = new Node(1);
    root->left->right = new Node(5);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    // Create iterator and traverse in-order
    BSTIterator iterator(root);

    cout << "BST In-Order Traversal using Iterator: ";
    while (iterator.hasNext())
    {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}