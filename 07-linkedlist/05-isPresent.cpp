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

bool checkIFpresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Linked List: 10 -> 20 -> 30 -> 40" << endl;
    cout << "Searching for 20: " << checkIFpresent(head, 20) << endl;
    cout << "Searching for 50: " << checkIFpresent(head, 50) << endl;
    cout << "Searching for 30: " << checkIFpresent(head, 30) << endl;
    cout << "Searching for 10: " << checkIFpresent(head, 10) << endl;

    return 0;
}