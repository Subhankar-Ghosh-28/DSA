#include<bits/stdc++.h>
using namespace std;

int upperBound(int arr[],int n , int x){
       int low = 0;
     int high = n-1, ans = n;
     while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid]>x){
        ans = mid;
         high = mid -1;
        } 
        
        else  low = mid +1;
    }
    return ans;
}

int main(){
    
    int a[] = {2,4,5,7,8};
     int n = sizeof(a) / sizeof(a[0]);
    int key = 5;
    auto b = upperBound(a,n,key);

    //  int* b = upper_bound(a, a + n, key);
   
    cout<<"indeex of upper bound is "<<b;

    return 0;
}