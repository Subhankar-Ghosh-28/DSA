#include<bits/stdc++.h>
using namespace std;

class Stack {

public:
    queue<int> q;
    void push(int value) {
        int size = q.size();
            q.push(value);
        for (int i = 0; i < size; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << " pushed into stack.\n";
    }

    void pop(){
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout<<q.front() <<" is poped out.\n";
        q.pop();
    }

    void top(){
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout<<"Top is : "<<q.front()<<endl;
    }
    void display() {
        if (q.empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        queue<int> temp = q;
        cout << "Stack elements: ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.top();

    s.pop();
    s.top();

    s.display();
    return 0;
}