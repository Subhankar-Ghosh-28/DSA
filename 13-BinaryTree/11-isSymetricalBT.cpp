#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int key)
    {
       data = key;
       left = nullptr;
       right = nullptr;
    }

};

// If we were to draw a verti line through the centre of the tree, 
// the nodes on the left and right side would be mirror images of each other.

class Solution{
    bool isSymmetricHelp(Node* left, Node* right){
        if(left == NULL || right == NULL){
            return left == right;
        }

        if(left->data != right->data) return false;

        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
    public:
    bool isSymmetric(Node* root){
        return root == NULL || isSymmetricHelp(root->left,root->right);
    }
};

// Function to print the Inorder
// Traversal of the Binary Tree
void printInorder(Node* root){
    if(!root){
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}


int main(){
Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);

    Solution solution;
    
    cout << "Binary Tree (Inorder): ";
    printInorder(root);
    cout << endl;

    bool res;
    res = solution.isSymmetric(root);
    
    if(res){
        cout << "This Tree is Symmetrical" << endl;
    }
    else{
        cout << "This Tree is NOT Symmetrical" << endl;
    }

return 0;
}