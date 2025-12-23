#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void brute_sol(vector<int> arr1,vector<int> arr2){
    int n1= arr1.size();
    int n2 = arr2.size();
    set<int>st;
    vector<int> unionn;
    for(int i =0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i =0;i<n2;i++){
        st.insert(arr2[i]);
    }
   unionn[st.size()];
   int i =0;
   for(auto &it : st){
    unionn.push_back(it);
   }
  for(int it : unionn){
  cout<<it;
  }
   }
 vector<int> optimal_sol(vector<int> arr1,vector<int> arr2){
     int n1= arr1.size();
    int n2 = arr2.size();
    int i =0,j=0;
     vector<int> unionn;
     while(i<n1 && j<n2){
        if(arr1[i]<= arr2[j]){
            if(unionn.size() == 0 || unionn.back() != arr1[i])
                unionn.push_back(arr1[i]);
                i++;
                
          }
        else{
                 if(unionn.size() == 0 || unionn.back() != arr2[j]){
                unionn.push_back(arr2[j]);
                j++;
                }
                }
     
     }

 while(i<n1){
    if(unionn.size() == 0 || unionn.back() != arr1[i])
        unionn.push_back(arr1[i]);
         i++;
            
 }
 while(j<n2){
    if(unionn.size() == 0 || unionn.back() != arr2[j])
                unionn.push_back(arr2[j]);
                j++;
                 
   }
   return unionn;
}

int main(){
      vector<int> arr1,arr2;
   int n1,n2;
   cout<<"number array1 element "<<endl;
  cin>>n1;
  cout<<"input arrray 1 "<<"\n";
  for(int i =0;i<n1 ;i++){
    int element;
    cin>>element;
    arr1.push_back(element);
  }
  cout<<"number array2 element "<<endl;
  cin>>n2;
  cout<<"input arrray 2 "<<"\n";
  for(int i =0;i<n2 ;i++){
    int element;
    cin>>element;
    arr2.push_back(element);
  }
  vector<int> ve;
  ve = optimal_sol(arr1,arr2);
  cout<<"after union ";
  for(auto it:ve ){
    cout<<it<<" ";
  }
    return 0;
}