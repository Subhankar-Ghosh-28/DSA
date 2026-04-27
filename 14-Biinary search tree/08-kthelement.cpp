#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// kth smallest element in the BST 1 base indexing
class kTHSmallest
{
private:
    void inorder(Node *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    int k;
    int result;
    void inorder(Node *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            if (--k == 0)
            {
                result = node->data;
                return;
            }
            inorder(node->right);
        }
    }

    friend class kTHlargest;

public:
    int bruteForce(Node *root, int k)
    {
        // inorder approach bcoz in BST inorder give sorted node
        if (!root)
            return -1;

        vector<int> ans;
        inorder(root, ans);
        return ans[k - 1];

        // TC-> O(N), SC->O(N);
    }

    int optimal(Node *root, int k)
    {
        // in this we optimized space
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
        // TC-> O(N), SC->O(H);
    }
};

class kTHlargest
{
private:
    void inorder(Node *root, vector<int> &ans)
    {

        kTHSmallest sol;
        sol.inorder(root, ans);
    }

    int k;
    int result;
    void reverse_inorder(Node *node)
    {
        if (node != nullptr)
        {
            reverse_inorder(node->right);
            if (--k == 0)
            {
                result = node->data;
                return;
            }
            reverse_inorder(node->left);
        }
    }

public:
    int bruteForce(Node *root, int k)
    {
        // inorder approach bcoz in BST inorder give sorted node
        if (!root)
            return -1;

        vector<int> ans;
        inorder(root, ans);
        return ans[ans.size() - k];

        // TC-> O(N), SC->O(N);
    }

    int optimal(Node *root, int k)
    {
        // in this we optimized space
        this->k = k;
        this->result = -1;
        reverse_inorder(root);
        return result;

        // TC-> O(N), SC->O(H);
    }
};

int main()
{
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

    kTHSmallest smallest;
    kTHlargest largest;

    int k = 3;

    cout << "Testing kTH Smallest Element (k=" << k << "):" << endl;
    cout << "Brute Force: " << smallest.bruteForce(root1, k) << endl;
    cout << "Optimal: " << smallest.optimal(root1, k) << endl;

    cout << "\nTesting kTH Largest Element (k=" << k << "):" << endl;
    cout << "Brute Force: " << largest.bruteForce(root1, k) << endl;
    cout << "Optimal: " << largest.optimal(root1, k) << endl;

    return 0;
}