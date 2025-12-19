#include <bits/stdc++.h>
using namespace std;

// stack using array
#define size 10

class Stack
{
    int top = -1;
    int st[size];

public:
    void push(int n)
    {
        if (top >= size)
            cout << "stack is full";
        top = top + 1;
        st[top] = n;
        cout << n << " pushed into stack.\n";
    }

    void gettop() {
        if (top == -1) cout<<"stack is empty.";
        cout<<"stack top is "<<st[top]<<endl;
    }
    
    void pop() {
        if (top == -1) cout<<"stack is empty.";
        top = top-1;
        cout<<st[top]<<" is poped out.\n";
    }
    int Size(){
        return top+1;
    }

    void display () {
        if (top == -1) cout<<"stack is empty.";
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << st[i] << " ";
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