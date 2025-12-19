#include<bits/stdc++.h>
using namespace std;
void reverse1 (vector<int> &nums,int start,int end){
     
    while(start<end){
        int temp = nums[start];
        nums[start]= nums[end];
        nums[end]= temp;
        start++;
        end--;
        }
    }
void optimal(vector<int> &arr , int m){
     vector<int> ans;
     int n = arr.size();
     reverse1(arr,m,n-1);
}

int main(){
     vector<int> arr ={1,2,3,4,5};
     int m =2;
     optimal(arr,m);
     for(auto it: arr){
     cout<<it;
     }
    return 0;
}