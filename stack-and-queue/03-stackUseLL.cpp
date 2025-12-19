#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    Node *next;
    int data;

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

class Stack
{

    Node *top = nullptr;
    int size = 0;

public:
    void push(int num)
    {
        Node *temp = new Node(num);
        temp->next = top;
        top = temp;
        size++;
        cout << num << " is pushed into stack \n";
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "stack is empty.\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << " is poped out.\n";
        delete (temp);
        size--;
    }

    void gettop()
    {
        if (size == 0)
        {
            cout << "stack is empty.\n";
            return;
        }
        cout << top->data << " is top.\n";
    }

    void display()
    {
        if (size == 0)
        {
            cout << "stack is empty.";
            return;
        }
        cout << "Stack elements: ";
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.gettop();

    s.display();
    return 0;
}
