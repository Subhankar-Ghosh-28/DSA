#include <bits/stdc++.h>
using namespace std;

// Burn the whole tree from a given target tree and give the time need;

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
    Node *markParent(Node *root, unordered_map<Node *, Node *> &parentmap, int start)
    {
        queue<Node *> q;
        q.push(root);

        Node *result;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr->data == start)
                result = curr;

            if (curr->left != NULL)
            {
                parentmap[curr->left] = curr;
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                parentmap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return result;
    }

    int maxDistace(unordered_map<Node *, Node *> parent_track, Node *target)
    {

        unordered_map<Node *, bool> visited;

        queue<Node *> q;
        q.push(target);
        visited[target] = true;

        int maxi = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool fl = false;
            for (int i = 0; i < size; i++)
            {
                Node *current = q.front();
                q.pop();

                if (current->left && !visited[current->left])
                {
                    fl = true;
                    q.push(current->left);
                    visited[current->left] = true;
                }

                if (current->right && !visited[current->right])
                {
                    fl = true;
                    q.push(current->right);
                    visited[current->right] = true;
                }

                if (parent_track[current] && !visited[parent_track[current]])
                {
                    fl = true;
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
            if (fl)
                maxi++;
        }
        return maxi;

        // TC -> O(N) + O(N) + //(log N for hash map oeration) ,, SC->O(N)+O(N)+O(N);
    }

public:
    int timeToBurn(Node *root, int start)
    {

        if (NULL == root)
            return 0;

        unordered_map<Node *, Node *> parent_track;
        Node *target = markParent(root, parent_track, start);

        int maxi = maxDistace(parent_track, target);

        return maxi;
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

    Solution sol;

    cout << "Minimum time to burn the tree: " << sol.timeToBurn(root, target) << endl;

    return 0;
}