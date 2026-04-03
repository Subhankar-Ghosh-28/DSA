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
    int dfs(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        return max(lh, rh) + 1;
    }

public:
    int diameter = 0;
    void bruteForce(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        int lh = dfs(root->left);
        int rh = dfs(root->right);

        diameter = max(diameter, lh + rh);
        bruteForce(root->left);
        bruteForce(root->right);

        // TC -> O(N*N)
    }

    int optimal(Node *root, int &diameter)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = optimal(root->left, diameter);
        int rh = optimal(root->right, diameter);

        diameter = max(diameter, lh + rh); // count edge

        return max(lh, rh) + 1;

        // TC-> O(N);
    }

    vector<int> bestPath;

    // Function returns the longest downward path from root
    vector<int> solve(Node *root, int &diameter)
    {
        if (!root)
            return {};

        vector<int> left = solve(root->left, diameter);
        vector<int> right = solve(root->right, diameter);

        // Current diameter (nodes count)
        int currDiameter = left.size() + right.size() + 1;

        if (currDiameter > diameter)
        {
            diameter = currDiameter;

            bestPath.clear();

            // left path (reverse)
            for (int i = left.size() - 1; i >= 0; i--)
            {
                bestPath.push_back(left[i]);
            }

            // root
            bestPath.push_back(root->data);

            // right path
            for (int x : right)
            {
                bestPath.push_back(x);
            }
        }

        if (left.size() > right.size())
        {
            vector<int> temp = left;
            temp.insert(temp.begin(), root->data); // root at front
            return temp;
        }
        else
        {
            vector<int> temp = right;
            temp.insert(temp.begin(), root->data);
            return temp;
        }
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;

    solution.bruteForce(root);
    // int diameter = solutiom.diameter
    int diameter = 0;

    solution.optimal(root, diameter);

    cout << "The diameter of the binary tree is (edge): " << diameter << endl;

    solution.solve(root, diameter);
    cout << "Diameter path: ";
    for (int x : solution.bestPath)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}