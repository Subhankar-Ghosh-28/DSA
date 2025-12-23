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

Node *Reverse(Node *head)
{

  Node *temp = head;
  Node *prev = NULL;

  while (temp != NULL)
  {
    Node *front = temp->next;
    temp->next = prev;

    prev = temp;
    temp = front;
  }
  return prev;
}

Node *findKthNode(Node *temp, int k)
{
  k -= 1;
  while (k > 0 && temp != NULL)
  {
    k--;
    temp = temp->next;
  }
  return temp;
}

Node *kthreverse(Node *head, int k)
{
  Node *temp = head;
  Node *nextNode;
  Node *prevNode = NULL;
  while (temp)
  {
    Node *kthNode = findKthNode(temp, k);
    if (kthNode == NULL)
    {
      if (prevNode)
        prevNode->next = temp;
      break;
    }
    nextNode = kthNode->next;
    kthNode->next = NULL;
    Reverse(temp);

    if (temp == head)
      head = kthNode;
    else
    {
      prevNode->next = kthNode;
    }

    prevNode = temp;
    temp = nextNode;
  }

  return head;
}

Node *convertArrLL(vector<int> &arr)
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

Node *print(Node *head)
{
  Node *temp = head;
  while (temp != nullptr)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *head = convertArrLL(arr);
  cout << "Original Linked List: ";
  print(head);
  head = kthreverse(head, 3);
  print(head);
  return 0;
}