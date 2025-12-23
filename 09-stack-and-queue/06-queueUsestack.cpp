#include<bits/stdc++.h>
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

class Queue {
    stack<int> s1,s2;

    void push(int num) {
        while (s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(num);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
};

int main(){
     

    return 0;
}