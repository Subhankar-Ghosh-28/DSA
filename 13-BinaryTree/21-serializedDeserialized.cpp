#include <bits/stdc++.h>
using namespace std;

// serialize = convert the tree to string , where '#' = NULL;
// deserialize = convert string to tree

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

void inorder(Node *root)
{

    if (!root)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

class Solution
{
public:
    string serialize(Node *root)
    {
        if (root == NULL)
            return "";

        string ans = "";
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            if (curr == NULL)
                ans.append("#,");
            else
            {
                ans.append(to_string(curr->data) + ",");
            }

            if (curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ans;
        // TC-> O(N) ,,sc-> O(N)
    }

    Node *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        stringstream s(data);

        string str;

        getline(s, str, ',');
        Node *root = new Node(stoi(str));

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *node = q.front();
            q.pop();
            getline(s, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                Node *leftNode = new Node(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                Node *rightNode = new Node(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
        // TC-> O(N) ,,sc-> O(N)
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    Solution solution;

    cout << "Orignal Tree: ";
    inorder(root);
    cout << endl;

    string serialized = solution.serialize(root);
    cout << "Serialized: " << serialized << endl;

    Node *deserialized = solution.deserialize(serialized);

    cout << "Tree after deserialisation: ";
    inorder(deserialized);
    cout << endl;
    return 0;
}