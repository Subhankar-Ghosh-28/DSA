// print root to give leaf node path in BT

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

    bool getPath(Node* root, vector<int> &arr, int x){
        if(root == NULL) return false;

        arr.push_back(root->data);

        if(root->data == x) return true;

        if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;

        arr.pop_back();

        return false;
    }

class Solution{
    vector<int> Solution::Solve(Node* root, int b){
        vector<int> ans;

        if(root == NULL) return ans;

        getPath(root,ans,b);

        return ans;

        // TC-> O(N) SC-> O(H);
    }
};

int main(){

return 0;
}