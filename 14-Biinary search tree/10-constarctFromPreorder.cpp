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
    Node *insertNode(Node *root, int data)
    {
        if (!root)
            return new Node(data);

        if (root->data > data)
        {
            root->left = insertNode(root->left, data);
        }
        else
        {
            root->right = insertNode(root->right, data);
        }
        return root;
        // tc->O(n)
    }

    Node *bulid(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, map<int, int> &inorderMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        Node *root = new Node(pre[preStart]);

        int inRoot = inorderMap[root->data];

        int numsLeft = inRoot - inStart;

        root->left = bulid(pre, preStart + 1, preStart + numsLeft, in, inStart, numsLeft - 1, inorderMap);

        root->right = bulid(pre, preStart + numsLeft + 1, preEnd, in, inRoot + 1, inEnd, inorderMap);

        return root;
    }

public:
    Node *bruteForce(vector<int> &nums)
    {
        int n = nums.size();

        Node *root = new Node(nums[0]);

        for (int i = 1; i < n; i++)
        {
            insertNode(root, nums[i]);
        }

        return root;
        // tc->O(N*N);
    }

    Node *better(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> preorder = nums;
        vector<int> inorder = nums;
        sort(inorder.begin(), inorder.end());

        map<int, int> inorderMap;

        for (int i = 0; i < n; i++)
        {
            inorderMap[inorder[i]] = i;
        }

        Node *root = bulid(preorder, 0, n - 1, inorder, 0, n - 1, inorderMap);
        return root;

        // O(nlog n) for sorting its may different;
        // O(n) for bulid tree;
        // TC-> O(n log n) + O(n)
        // Sc->O(N)
    }
    Node *optimal(vector<int> &nums)
    {
        int i = 0;
        return buildHelper(nums, i, INT_MAX);

        // TC-> O(3N) bcoz we travel a node 3 times max
        // SC-> O(1), no external space need use stack space for recursion
    }

    Node *buildHelper(vector<int> &nums, int &i, int boundary)
    {
        if ((i == nums.size()) || (nums[i] > boundary))
            return NULL;

        Node *root = new Node(nums[i++]);
        root->left = buildHelper(nums, i, root->data);
        root->right = buildHelper(nums, i, boundary);
        return root;
    }
};

void printInOrder(Node *root)
{
    if (!root)
        return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

int main()
{
    vector<int> arr = {8, 5, 1, 7, 10, 12};

    Solution sol;
    Node *root = sol.optimal(arr);
    cout << "\nInitial BST (InOrder): ";
    printInOrder(root);
    cout << "\n"
         << endl;
    return 0;
}