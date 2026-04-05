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

/*
add vertical element from left to right
*/

void printResult(const vector<int> &result)
{
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}

class verticalTraverse
{
public:
    vector<vector<int>> antiClock(Node *root)
    {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        // push vertical position level position with every level node
        // multi set for store same value node
        map<int, map<int, multiset<int>>> nodes;

        // push to q node and its x and y position
        queue<pair<Node *, pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty())
        {
            auto it = todo.front();
            todo.pop();

            Node *node = it.first;

            int x = it.second.first;
            int y = it.second.second;

            nodes[x][y].insert(node->data);

            if (node->left != NULL)
            {
                todo.push({node->left, {x - 1, y + 1}});
            }

            if (node->right != NULL)
            {
                todo.push({node->right, {x + 1, y + 1}});
            }
        }

        for (auto p : nodes)
        {
            vector<int> col;
            for (auto q : p.second)
            {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;

        // TC-> O(N * log²N * log²N * log²N)
        // SC-> O(N + N/2)
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    // Create solution object
    verticalTraverse solution;

    // Call vertical order traversal
    vector<vector<int>> verticalTraversal = solution.antiClock(root);

    // Print result
    cout << "Vertical Traversal:" << endl;
    for (auto level : verticalTraversal)
    {
        for (auto node : level)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}