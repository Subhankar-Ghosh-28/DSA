#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertToLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main()
{
    vector<int> arr;
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements:" << "\n";
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    Node *head = convertToLL(arr);
    Node *mover = head;

    cout << "The linked list: " << endl;

    while (mover)
    {
        cout << mover->data << "->";
        mover = mover->next;
    }
    cout << "NULL";
    return 0;
}