#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
   int n;
  cin>>n;
  cout<<"input"<<"\n";
  for(int i =0;i<n ;i++){
    int element;
    cin>>element;
    arr.push_back(element);
  }
  
  cout<<"output"<<endl;
  for(auto it : arr){
    cout<<it<<" ";
  }
    return 0;
}