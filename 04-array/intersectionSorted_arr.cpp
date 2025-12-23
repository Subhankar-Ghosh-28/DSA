#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> brute_sol(vector<int> arr1,vector<int> arr2){
 int n1= arr1.size();
 int n2 = arr2.size();
 vector<int> ans;
 int vis[n2]= {0};
 for(int i =0; i<n1;i++){
    for(int j =0; j<n2;j++){
        if ( arr1[i] == arr2[j] && vis[j] == 0){
           ans.push_back(arr1[i]);
           vis[j]=1;
           break;
        }
        if(arr2[j]>arr1[i]) break;
    }
 }
 return ans;
}
 vector<int> optimal_sol(vector<int> &arr1,vector<int> &arr2){
    int n1= arr1.size();
    int n2 = arr2.size();
    int i =0,j=0;
    vector<int> ans;
     while(i<n1 && j<n2){
     if(arr1[i]< arr2[j]){
        i++;
       }
        else if (arr2[j]<arr1[i]){ j++;}
        else {
         ans.push_back(arr1[i]);
         i++;
         j++;
         }
        }
return ans;
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
  cout<<"after intersection ";
  for(auto it:ve ){
    cout<<it<<" ";
  }
    return 0;
}