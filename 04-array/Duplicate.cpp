#include<bits/stdc++.h>
using namespace std;
int brute_sol(vector<int> &arr,int n){
  
   int ans =0 ;
   for(auto it : arr){
    ans = ans^it;
   }
   return ans;
}

int main(){
    int n = 5;
     vector<int> a = {1,2,3,2,4};
     brute_sol(a,n);
    return 0;
}