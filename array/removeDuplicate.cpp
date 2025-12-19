#include<iostream>
#include<set>
#include<bits/stdc++.h>
using namespace std;
// array is sorted;
void brute_sol(vector<int> &arr,int n){
    set<int>st;
    for(int i = 0;i<n;i++){
        st.insert(arr[i]);
    }
    int index =0;
    for(auto it : st){
    arr[index]=it;
    index++;
    }
    cout<<"total number ";
 cout<<index<<endl;
 cout<<"the numbers"<<endl;
  for(auto it : st){
    cout<<it<<" ";
    
    }
}
void optimal_sol(vector<int> &arr,int n){
    int i = 0;
    for(int j =1;j<n;j++){
        if(arr[i] != arr[j]){
              i++;
          arr[i] = arr[j];
        
        }
    }
    int k = i+1;
    
    for(int i=0;i<k;i++){
  cout<<arr[i];
   }
    
}
int main(){
    int n;
    vector<int> arr;
    cout<<"Enter the number of the element "<<endl;
    cin>>n;
    cout<<"Enter the element "<<endl;
    for(int i =0;i<n;i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    optimal_sol(arr,n);
    //     cout<<"output"<<endl;
    // for(auto it : arr){
    //     cout<<it<<" ";
    // }
  
    return 0;
}