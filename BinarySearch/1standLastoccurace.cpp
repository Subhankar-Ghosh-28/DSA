#include<bits/stdc++.h>
using namespace std;

int first(int arr[],int n , int x){
       int low = 0;
     int high = n-1, ans = -1 ;
     while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid]==x){
         ans = mid;
         high = mid -1;
        } 
        else if(arr[mid] <x) low = mid +1;
        else   high = mid -1;
    }
    return ans;
}

int last(int arr[],int n , int x){
       int low = 0;
     int high = n-1, ans = -1;
     while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid]==x){
        ans = mid;
        low = mid +1;
        } 
        
        else if(arr[mid]>x)  high = mid -1;
        else low = mid +1;
    }
    return ans;
}

int main(){
    
    int a[] = {2,4,5,7,8};
     int n = sizeof(a) / sizeof(a[0]);
    int key = 6;
    int b = first(a,n,key);
    int c = last(a,n,key);

    //  int* b = lower_bound(a, a + n, key);
   
      cout<<"index of first occurance is "<<b<<endl;
      cout<<"index of last occurance is "<<c<<endl;
      

    return 0;
}