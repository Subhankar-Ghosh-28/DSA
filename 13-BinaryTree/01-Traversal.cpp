#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int key) : data(key), left(nullptr), right(nullptr) {}

    Node() : data(0), left(nullptr), right(nullptr) {}
};

class Recursive
{
private:
    void preHelper(Node *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        arr.push_back(root->data);
        preHelper(root->left, arr);
        preHelper(root->right, arr);
    }

    void inHelper(Node *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        inHelper(root->left, arr);
        arr.push_back(root->data);
        inHelper(root->right, arr);
    }

    void postHelper(Node *root, vector<int> &arr)
    {
        if (root == NULL)
            return;

        postHelper(root->left, arr);
        postHelper(root->right, arr);
        arr.push_back(root->data);
    }

public:
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;

        preHelper(root, ans);
        return ans;
    }

    vector<int> inOrder(Node *root)
    {
        vector<int> ans;

        inHelper(root, ans);
        return ans;
    }

    vector<int> postOrder(Node *root)
    {
        vector<int> ans;

        postHelper(root, ans);
        return ans;
    }
};

class LevelOrderTravarse
{
public:
    vector<vector<int>> LevelOrder(Node *root)
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

        // TC-> O(N)  sc -> O(n)
    }
};

class Iterative
{
public:
    vector<int> preOrder(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<Node *> st;
        st.push(root);

        while (!st.empty())
        {

            Node *node = st.top();
            st.pop();

            ans.push_back(node->data);

            if (node->right != nullptr)
            {
                st.push(node->right);
            }
            if (node->left != nullptr)
            {
                st.push(node->left);
            }
        }
        return ans;
    }

    // TC-> O(N)  sc -> O(h)

    vector<int> inOrder(Node *root)
    {
        stack<Node *> st;
        Node *node = root;

        vector<int> ans;

        while (true)
        {
            if (node != NULL)
            {
                st.push(node);
                node = node->left;
            }

            else
            {
                if (st.empty())
                    break;

                else
                {
                    node = st.top();
                    st.pop();

                    ans.push_back(node->data);
                    node = node->right;
                }
            }
        }
        return ans; // TC-> O(N)  sc -> O(h)
    }

    vector<int> postOrder(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;

        vector<int> ans;

        while (curr != NULL || !st.empty())
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                Node *temp = st.top()->right;
                if (temp == NULL)
                {
                    temp = st.top();
                    st.pop();

                    ans.push_back(temp->data);

                    while (!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top(); // <---- O(N)
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                else
                {
                    curr = temp;
                }
            }
        }
        return ans;

        // TC-> O(N+N)  sc -> O(h)
    }

    // postorder using two stack

    vector<int> postOrder2stack(Node *root)
    {

        stack<Node *> st1, st2;
        vector<int> ans;

        st1.push(root);

        while (!st1.empty())
        {
            Node *node = st1.top();
            st1.pop();

            st2.push(node);

            if (node->left != nullptr)
            {
                st1.push(node->left);
            }
            if (node->right != nullptr)
            {
                st1.push(node->right);
            }
        }

        while (!st2.empty())
        {
            ans.push_back(st2.top()->data);
            st2.pop();
        }
        return ans;

        // TC-> O(N)  sc -> O(2n)
    }
};

int main()
{

    Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    Iterative sol;

    cout << "Pre-order traversal : ";
    for (auto node : sol.preOrder(root))
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "In-order traversal : ";
    for (auto node : sol.inOrder(root))
    {
        cout << node << " ";
    }
    cout << endl;

    cout << "Post-order traversal : ";
    for (auto node : sol.postOrder(root))
    {
        cout << node << " ";
    }
    cout << endl;

    LevelOrderTravarse solu;

    vector<vector<int>> result = solu.LevelOrder(root);

    cout << "Level Order Traversal of Tree: " << endl;

    for (auto x : result)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}