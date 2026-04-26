#include <bits/stdc++.h>
using namespace std;

/*
1. if the node at leaf just delete it
2. if the node have one child connect it to the parent
3. if the node have 2 child then conncet inorder predessecor to node right subtree
*/

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
public:
    Node *deleteNode(Node *root, int key)
    {
        if (!root)
            return NULL;

        if (root->data == key)
        {
            return helper(root);
        }

        Node *dummy = root;

        while (true)
        {
            if (root->data > key)
            {
                if (root->left != NULL && root->left->data == key)
                {
                    Node *rootLeft = helper(root->left);
                    root->left = rootLeft;
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != NULL && root->right->data == key)
                {
                    root->right = helper(root->right);
                    break;
                }
                else
                {
                    root = root->right;
                }
            }
        }
        return dummy;

        //TC-> O(log n)
    }

    Node *helper(Node *root)
    {
        // if the root left is null means one child condition
        if (root->left == NULL)
            return root->right;
        // if root right is null
        else if (root->right == NULL)
            return root->left;

        Node *rightChild = root->right;
        Node *predessecor = findRightMost(root->left);
        predessecor->right = rightChild;
        return root->left;
    }

    Node *findRightMost(Node *root)
    {
        if (root->right == NULL)
            return root;
        return findRightMost(root->right);
    }

    // Inorder traversal to display tree
    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Check if a node exists in the tree
    bool nodeExists(Node *root, int key)
    {
        if (!root)
            return false;
        if (root->data == key)
            return true;
        if (key < root->data)
            return nodeExists(root->left, key);
        return nodeExists(root->right, key);
    }
};

Node *insertNode(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
        root->left = insertNode(root->left, val);
    else
        root->right = insertNode(root->right, val);

    return root;
}

void displayMenu()
{
    cout << "\n========== BST DELETE OPERATION MENU ==========\n";
    cout << "1. Insert a node\n";
    cout << "2. Insert multiple nodes\n";
    cout << "3. Delete a node\n";
    cout << "4. Display BST (Inorder)\n";
    cout << "5. Exit\n";
    cout << "=============================================\n";
    cout << "Enter your choice: ";
}

int main()
{
    Solution sol;
    Node *root = nullptr;
    int choice, value;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Enter value to insert: ";
            cin >> value;
            root = insertNode(root, value);
            cout << "Node " << value << " inserted successfully!\n";
            break;
        }

        case 2:
        {
            int count;
            cout << "How many nodes do you want to insert? ";
            cin >> count;
            for (int i = 0; i < count; i++)
            {
                cout << "Enter value " << (i + 1) << ": ";
                cin >> value;
                root = insertNode(root, value);
                cout << "Node " << value << " inserted!\n";
            }
            cout << count << " nodes inserted successfully!\n";
            break;
        }

        case 3:
        {
            if (!root)
            {
                cout << "Tree is empty! Cannot delete.\n";
                break;
            }
            cout << "Current BST: ";
            sol.inorder(root);
            cout << "\n";
            cout << "Enter value to delete: ";
            cin >> value;

            // Check if node exists before deleting
            if (!sol.nodeExists(root, value))
            {
                cout << "ERROR: Node with value " << value << " does not exist in the tree!\n";
                break;
            }

            root = sol.deleteNode(root, value);
            cout << "Node " << value << " deleted successfully!\n";
            break;
        }

        case 4:
        {
            if (!root)
            {
                cout << "Tree is empty!\n";
            }
            else
            {
                cout << "BST (Inorder traversal): ";
                sol.inorder(root);
                cout << "\n";
            }
            break;
        }

        case 5:
        {
            cout << "Exiting... Thank you!\n";
            return 0;
        }

        default:
        {
            cout << "Invalid choice! Please try again.\n";
        }
        }
    }

    return 0;
}