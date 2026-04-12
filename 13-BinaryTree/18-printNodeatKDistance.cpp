#include <bits/stdc++.h>
using namespace std;

// print the nodes from the target node at k distance

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

    Node *markParent(Node *root, unordered_map<Node *, Node *> &parent_track, int x)
    {
        queue<Node *> q;
        q.push(root);

        Node *target;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == x)
                target = curr;

            if (curr->left != NULL)
            {
                parent_track[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                parent_track[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return target;
    }

public:
    vector<int> distanceK(Node *root, int x, int k)
    {
        if (NULL == root)
            return {};

        unordered_map<Node *, Node *> parent_track;
        Node *target = markParent(root, parent_track, x);

        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(target);
        visited[target] = true;

        int distance = 0;
        while (!q.empty())
        {
            int size = q.size();

            if (distance++ == k)
                break;

            for (int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();

                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (parent_track[current] && !visited[parent_track[current]])
                {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        vector<int> ans;

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();
            ans.push_back(current->data);
        }

        return ans;

        // TC -> O(N) + O(N) + log N for hash map oeration ,, SC->O(N)+O(N)+O(N);
    }
};

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    // Node with value 5
    int target = root->left->data;
    int k = 2;

    Solution sol;
    vector<int> result = sol.distanceK(root, target, k);

    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}