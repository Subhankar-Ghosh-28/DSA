#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],int n,int x){
    int low = 0;
    int high = n-1;
    while(low<= high){
        int mid = (low + high)/2;
        if(arr[mid]==x) return mid;
        else if (arr[mid]<= x) low = mid +1;
        else high = mid -1;
    }
    return -1;
}

int main(){
    int n = 5;
     int a[n] = {2,4,5,7,8};
     int b = binarySearch(a,n,5);
     cout<<b<<endl;
    return 0;
}