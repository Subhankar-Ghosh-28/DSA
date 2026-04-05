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

class LeftView
{
private:
    void leftRecursive(Node *root, int level, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == arr.size())
        {
            arr.push_back(root->data);
        }
        leftRecursive(root->left, level + 1, arr);
        leftRecursive(root->right, level + 1, arr);
    }

public:
    vector<vector<int>> levelOrder(Node *root)
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

public:
    // recursive approach
    vector<int> leftviewRecursive(Node *root)
    {
        // code here
        vector<int> arr;
        int level = 0;

        leftRecursive(root, level, arr);
        return arr;

        // TC-> O(N) , SC->O(H);
    }

    // Iterative approach using level order traversal;

    vector<int> leftviewIterative(Node *root)
    {
        vector<vector<int>> levels = levelOrder(root);

        vector<int> left;

        for (auto &level : levels)
        {
            left.push_back(level[0]);
        }

        return left; // TC-> O(N)  sc -> O(n)
    }
};

class RightView
{
    void rightRecursive(Node *root, int level, vector<int> &arr)
    {
        if (root == NULL)
        {
            return;
        }

        if (level == arr.size())
        {
            arr.push_back(root->data);
        }
        rightRecursive(root->right, level + 1, arr);
        rightRecursive(root->left, level + 1, arr);
    }

public:
    vector<int> rightViewRecursive(Node *root)
    {
        vector<int> arr;
        int level = 0;

        rightRecursive(root, level, arr);
        return arr;

        // TC-> O(N) , SC->O(H);
    }

    // Iterative approach using level order traversal;

    vector<int> rightviewIterative(Node *root)
    {
        LeftView level;
        vector<vector<int>> levels = level.levelOrder(root);

        vector<int> right;

        for (auto &level : levels)
        {
            right.push_back(level.back());
        }

        return right; // TC-> O(N)  sc -> O(n)
    }
};

class TopView
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        // first is line and second Node data
        map<int, int> mpp;

        // store node and corresponding vertical position
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

class BottomView
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        map<int, int> mpp;
        queue<pair<Node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            Node *node = it.first;
            int line = it.second;

            mpp[line] = node->data;

            if (node->left != NULL)
            {
                q.push({node->left, line - 1});
            }

            if (node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }

        for (auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    LeftView sol1;
    cout << "The Left view is: ";
    printResult(sol1.leftviewIterative(root));
    cout << endl;

    RightView sol2;
    cout << "The Right view is: ";
    printResult(sol2.rightviewIterative(root));
    cout << endl;

    TopView sol3;
    cout << "The Top view is: ";
    printResult(sol3.topView(root));
    cout << endl;

    BottomView sol4;
    cout << "The Bottom view is: ";
    printResult(sol4.bottomView(root));
    cout << endl;
    return 0;
}