#include <bits/stdc++.h> 
using namespace std;
void reverse (vector<int> &nums,int start,int end){
    while(start<end){
        int temp = nums[start];
        nums[start]= nums[end];
        nums[end]= temp;
        start++;
        end--;
        }
    }
vector<vector<int>> leftRotationsOfArray(vector<int> nums, vector<int> queries) {
   vector<vector<int>> result;

   for(auto k : queries){
       vector<int > temp= nums;
       int n = temp.size();
       k %=n;

       reverse(temp,0,k-1);
       reverse(temp,k,n-1); 
       reverse(temp,0,n-1);
       
       result.push_back(temp);
   }
   return result;
}

vector<vector<int>> rightRotationsOfArray(vector<int> nums, vector<int> queries){
    vector<vector<int>> result;
     for(auto k : queries){
       vector<int > temp= nums;
       int n = temp.size();
       k %=n;

       reverse(temp,0,n-k-1);
       reverse(temp,n-k,n-1); 
       reverse(temp,0,n-1);
       
       result.push_back(temp);
   }
   return result;
}



int main(){
   vector<int> arr;
   int n;
   cout<<"number array element "<<endl;
  cin>>n;
  cout<<"input arrray "<<"\n";
  for(int i =0;i<n ;i++){
    int element;
    cin>>element;
    arr.push_back(element);
  }
  int q;
  cout<<"enter number of queries ";
  cin>>q;
    vector<int> queries(q);
    cout<<"enter queries ";
    for(int i =0;i< q;i++){
        cin>>queries[i];
    }
 rightRotationsOfArray(arr,queries);
  cout<<"output"<<endl;

  for(const auto& it : rightRotationsOfArray(arr,queries)){
   for(auto val: it){
    cout<<val<<" ";
   }
   cout<<endl;
  }
  
 
    return 0;
}