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
    int dfs(Node *root, int &maxSum)
    {
        if (!root)
            return 0;

        int left = max(0, dfs(root->left, maxSum));
        int right = max(0, dfs(root->right, maxSum));

        maxSum = max(maxSum, left + right + root->data);

        return max(left, right) + root->data;
    }

public:
    int maxPathSum(Node *root)
    {
        int maxi = INT_MIN;
        dfs(root, maxi);
        return maxi;
    }

    //TC -> O(N)  SC-> O(H)
};

int main()
{
    Node *root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    Solution obj;
    cout << "Maximum Path Sum: "
         << obj.maxPathSum(root) << endl;
    return 0;
}