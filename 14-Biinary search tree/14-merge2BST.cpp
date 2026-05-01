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
private:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

        vector<int> merge(vector<int> &arr1, vector<int> &arr2)
    {

        int n = arr1.size(), m = arr2.size();
        vector<int> merged;

        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                merged.push_back(arr1[i++]);
            }
            else
            {
                merged.push_back(arr2[j++]);
            }
        }
        while (i < n)
            merged.push_back(arr1[i++]);
        while (j < m)
            merged.push_back(arr2[j++]);
        
        return merged;
    }

public:
    vector<int> bruteForce(Node *root1, Node *root2)
    {
        vector<int> element;

        inorder(root1, element);
        inorder(root2, element);

        sort(element.begin(), element.end());
        return element;

        // TC->O(n+m)* log(n+m) for sort
        // SC->O(n+m);
    }

    vector<int> mergeBSTs(Node *root1, Node *root2)
    {
        vector<int> arr1, arr2;

        inorder(root1, arr1);
        inorder(root2, arr2);

        return merge(arr1, arr2);

        // TC->O(n+m) + O(m+n);
        // SC->O(n+m);
    }
};

int main()
{
    // Create first BST
    //     5
    //    / \
    //   3   7
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);

    // Create second BST
    //     4
    //    / \
    //   2   6
    Node *root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Solution sol;

    // Merge BSTs using mergeBSTs
    vector<int> result = sol.mergeBSTs(root1, root2);

    cout << "Merged BSTs (Optimal): ";
    for (int num : result)
    {
        cout << num << " ";
    }
    cout << endl;

    // Using brute force
    vector<int> result2 = sol.bruteForce(root1, root2);

    cout << "Merged BSTs (Brute Force): ";
    for (int num : result2)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}