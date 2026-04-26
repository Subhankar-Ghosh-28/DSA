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
public:
    Node *insertNode(Node *root, int key)
    {
        if (root == NULL)
            return new Node(key);

        Node *curr = root;

        while (true)
        {
            if (curr->data > key)
            {
                if (curr->left)
                    curr = curr->left;
                else
                {
                    curr->left = new Node(key);
                    break;
                }
            }
            else
            {
                if (curr->right)
                    curr = curr->right;
                else
                {
                    curr->right = new Node(key);
                    break;
                }
            }
        }
        return root;

        // TC -> O(N) ,, SC-> O(N)
    }

    Node *insertNodeRecursive(Node *root, int val)
    {
        if (!root)
            return new Node(val);

        if (val < root->data)
            root->left = insertNode(root->left, val);
        else
            root->right = insertNode(root->right, val);

        return root;
    }
};

void printInOrder(Node *root)
{

    if (root == nullptr)
        return;

    printInOrder(root->left);

    cout << root->data << " ";

    printInOrder(root->right);
}

// Function to build initial BST
Node *buildInitialBST()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(15);
    return root;
}

// Function to display menu
void displayMenu()
{
    cout << "\n========== BST INSERT MENU ==========" << endl;
    cout << "1. Insert a single node" << endl;
    cout << "2. Insert multiple nodes" << endl;
    cout << "3. Display current BST (InOrder)" << endl;
    cout << "4. Exit" << endl;
    cout << "====================================" << endl;
}

int main()
{
    cout << "===== Binary Search Tree - Insert Node =====" << endl;

    Node *root = buildInitialBST();
    Solution sol;

    cout << "\nInitial BST (InOrder): ";
    printInOrder(root);
    cout << "\n"
         << endl;

    int choice = 0;
    while (choice != 4)
    {
        displayMenu();
        cout << "Enter your choice (1-4): ";

        // Validate input
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
        {
            int key;
            cout << "\nEnter the key to insert: ";

            if (!(cin >> key))
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter a valid integer." << endl;
                break;
            }

            cout << "Before insertion: ";
            printInOrder(root);

            root = sol.insertNode(root, key);

            cout << "\nAfter insertion of " << key << ": ";
            printInOrder(root);
            cout << "\n"
                 << endl;
            break;
        }

        case 2:
        {
            int count;
            cout << "\nHow many nodes do you want to insert? ";

            if (!(cin >> count) || count <= 0)
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input! Please enter a positive number." << endl;
                break;
            }

            cout << "Before insertion: ";
            printInOrder(root);
            cout << "\n";

            for (int i = 0; i < count; i++)
            {
                int key;
                cout << "Enter key " << (i + 1) << ": ";

                if (!(cin >> key))
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid input! Skipping this entry." << endl;
                    i--;
                    continue;
                }

                root = sol.insertNode(root, key);
                cout << "Inserted " << key << endl;
            }

            cout << "\nAfter insertion: ";
            printInOrder(root);
            cout << "\n"
                 << endl;
            break;
        }

        case 3:
        {
            cout << "\nCurrent BST (InOrder traversal): ";
            printInOrder(root);
            cout << "\n"
                 << endl;
            break;
        }

        case 4:
        {
            cout << "\nThank you for using BST Insert! Exiting..." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice! Please select 1-4." << endl;
        }
        }
    }

    return 0;
}