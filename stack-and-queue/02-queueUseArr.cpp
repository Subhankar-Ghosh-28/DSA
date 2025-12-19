#include<bits/stdc++.h>
using namespace std;

#define size 10

class Queue {
    int q[size];
    int start = -1 ; int end = -1; int currSize = 0;

public:
    void push(int data) {
        if (currSize == size) cout<<"Queue is full. \n";
        if (currSize == 0) {
            start = 0, end = 0;
        }
        else 
            end = (end + 1)%size;
        
        q[end] = data , currSize++;
        cout << data << " pushed into Queue.\n";
    }

    void pop(){
        if (currSize == 0) cout<<"Queue is empty. \n";
        int ele = q[start];
        if(currSize == 1) start = end = -1;
        else 
            start = start + 1;
            currSize--;
        
        cout<<ele<<" element is pop.\n";
    }

    void top() {
        if(currSize == 0) cout<<"No top! Queue is empty.\n";
        cout<<"Top element is "<<q[start]<<endl;

    }

    void display() {
        if (currSize == 0) cout<<"Queue is empty.";
        cout << "Queue elements: ";
        for (int i = start; i <= end; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main(){

     Queue q;
     q.push(4);
     q.push(5);
     q.push(2);
     q.push(7);

     q.display();

     q.pop();
     q.pop();

     q.display();
    

return 0;
}