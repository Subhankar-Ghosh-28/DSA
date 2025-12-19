#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1 , Node* next1){
         data = data1;
         next = next1;
    }

    public:
    Node(int data1){
         data = data1;
         next = nullptr;
    }
};
// print head after conver
Node* convertArrLL( vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for( int i = 1 ; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* print(Node* head){
     Node* temp = head;
      while(temp != nullptr){
    cout<<temp->data<<" ";
    temp = temp->next;
 }
 
}

int lenghtLL(Node* head){
    int cnt = 0;
    Node* temp = head;
     while(temp){
   
    temp = temp->next;
    cnt++;
 }
 return cnt;
    
}

bool checkIFpresent(Node* head, int val){
     Node* temp = head;
     while(temp){
        if(temp->data == val) return true;
    temp = temp->next;
    
 }
 return false;
}

// delection

Node* removeHEad(Node* head){
    if ( head == NULL) return head;
    Node* temp = head;
     head = head->next;
     delete temp;
     return head;
}
Node* removeTail(Node* head){
    if (head == NULL || head->next == NULL){
      return NULL;
    }
      Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}
Node* removeK(Node* head,int k){
    if(head == NULL ) return head;
    if(k==1){
     Node* temp = head;
     head = head->next;
     delete temp;
     return head;
    }
    int cnt = 0 ; 
    Node* temp = head;
    Node* prev = NULL ;
    while (temp){
        cnt ++;
        if (cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
    
}
Node* removeofNode(Node* head, int el){
     if (head == NULL) return head;

    // Case 1: if the head node is the one to delete
    if (head->data == el) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    // Case 2: delete a non-head node
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == el) {
            prev->next = temp->next;  // unlink node
            delete temp;              // free memory
            break;                    // exit after deletion
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
//insertion 

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val,head);
    return temp;
}
Node* insertLast(Node* head, int val){
    if(head == NULL) return new Node(val);
    Node* temp = head;
    while(temp->next){
     temp = temp->next;
    }
    Node* newnode = new Node(val);
    temp->next = newnode;
    return head;
    
}
Node* insertK(Node* head, int val,int k){
     if(head == NULL) {
     if(k== 1)   return new Node(val);
     else return head;//return something you prefare
     }
     if (k == 1){
        Node* temp = new Node(val,head);
        return temp;
     }
     int cnt = 0; 
     Node* temp = head;
     while(temp != NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x = new Node(val);
            x->next = temp->next;
           temp->next = x; break;
        }
          temp= temp->next;
     }
    
     return temp;
}
Node* insertNode(Node* head, int el,int val){
     if(head == NULL) return NULL;
     
     if(head->data == val)   return new Node(el,head);

     Node* temp = head;
     while(temp->next != NULL){
       
        if(head->next->data==val){
            Node* x = new Node(el,temp->next);
            
           temp->next = x; break;
        }
          temp= temp->next;
     }
    
     return head;
}



int main(){
    vector<int> arr={12,5,8,7};
    Node* head = convertArrLL(arr);
    head = insertNode(head,100,12);
    print(head);

    return 0;
}

