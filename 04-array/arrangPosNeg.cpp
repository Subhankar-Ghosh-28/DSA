#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//arange pos and neg of an array and pos and neg are not same number
vector<int> sol (vector <int> arr){
    int n = arr.size();
    vector <int> pos,neg;
    for(int i =0; i<n;i++){
        if(arr[i]<0){
            neg.push_back(arr[i]);
        }
        else pos.push_back(arr[i]);
    }
    
    if(pos.size() < neg.size()){
        for(int i=0;i<pos.size();i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
        }
          
    int index = pos.size() *2;
    for(int i = pos.size();i<neg.size();i++){
        
        arr[index] = neg[i];
    index++;
    }
}
else{
    for(int i =0;i<neg.size();i++){
     arr[2*i] = pos[i];
     arr[2*i+1] = neg[i];
    }
      int index = neg.size() *2;
      for(int i = neg.size();i<pos.size();i++){
           arr[index] = pos[i];
          index++;
      }
}
return arr;
}

int main(){
    vector<int> A = {1,2,-4,-5,-7};

  vector<int> ans =sol(A);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
    return 0;
}