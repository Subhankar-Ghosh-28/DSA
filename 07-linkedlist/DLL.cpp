#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1 , Node* next1,Node* back1){
         data = data1;
         next = next1;
         back = back1;
    }

    public:
    Node(int data1){
         data = data1;
         next = nullptr;
         back = nullptr;
    }
};

Node* print(Node* head){
     Node* temp = head;
      while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
 }
 
}

Node* convertArrLL( vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for( int i = 1 ; i < arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr,mover);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// Delection

Node* delectionHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    return head;
}
Node* delectionLast(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;
    return head;

}
Node* delectionK(Node* head, int k){
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k)break;
        temp = temp->next;
    }
 
    Node* prev = temp->back;
    Node* front = temp->next;

    if (prev == NULL && front == NULL){
        delete temp; return NULL;
    }
    else if(prev == NULL){
        delectionHead(head); return head;
    }
    else if (front == NULL){
        delectionLast(head); return head;
    }

    prev->next = front;
    front->back = prev;
    temp->next = NULL;
    temp->back = NULL;
    delete temp;
    return head;
   
}
void delectionNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if (prev == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
   

    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
}

//insert a node before 
Node* inserthead(Node* head,int val){
    Node* newnode = new Node(val,head,nullptr);
    head->back = newnode;
    return newnode;
}
Node* insertlast(Node* head,int val){
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newnode = new Node(val,tail,prev);
    prev->next = newnode;
    tail->back = newnode;
    return head;
}
Node* insertk (Node* head, int val, int k){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newnode = new Node(val,temp,prev);
    temp->back = newnode;
    prev->next = newnode;
    return head;
}
Node* insertnode (Node* head, int val, int el){
    Node* temp = head;
   
    while(temp){
    
        if(temp->data == el) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newnode = new Node(val,temp,prev);
    temp->back = newnode;
    prev->next = newnode;
    return head;
}

int main(){
    vector<int> arr={12,5,8,7};
     Node* head = convertArrLL(arr);
    head = insertnode(head,100,7);
    print(head);

    return 0;
}