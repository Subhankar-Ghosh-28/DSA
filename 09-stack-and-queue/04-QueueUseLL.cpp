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

class Queue{

    Node* start; Node* end; int size ;
public:

    Queue() {
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void  peek(){
        if (start == nullptr){
            cout<<"Queue is empty.\n";
        }
        else {
            cout<<start->data<< " is peek element.\n";
        }
    }
    void  Enqueue(int num ){
        Node* temp = new Node(num);
        if (temp == nullptr)  //When heap exhausted 
        cout << "Queue is Full" << endl;
        else {
            if(start == NULL) {
                start = temp;
                end = temp;
            }
            else{
                end->next = temp;
                end = temp;
            }
        }
        cout<<num <<" Inserted into Queue "<<endl;
        size++;
    }

    void  Dequeue(){
        if (start == nullptr) {
            cout<<"Queue is empty.\n";
        }
        else {
            Node* temp = start;
            cout<<start->data <<" Removed From Queue"<<endl;
            start = start->next;
            delete(temp);
            size--;
        }
    }

    void  display() {
        if (start == nullptr) {
            cout<<"Queue is empty.\n";
        }
        cout << "Queue elements: ";
        Node *temp = start;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
     Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);

    Q.display();
    Q.Dequeue();
    Q.display();

    Q.peek();
    Q.display();

    return 0;
}