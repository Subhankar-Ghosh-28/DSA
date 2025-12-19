#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// array is also sorted;
int brute_sol(vector<int> arr,int N){
    
    int i;
    for( i =1; i<=N;i++){
        int flag = 0;
        for(int j =0; j<N-1;j++){
            if (arr[j] ==i){
              flag = 1;                             //worst case O(n*n), sc -> O(1);
              break;
            }
        }
     if (flag==0) return i;
    }
    return -1;
}
int better_sol(vector<int> arr,int N){
  int hash[N+1]={0};
  for(int i =0; i<N-1;i++){
    hash[arr[i]]++;
  }
   for(int i =1; i<=N;i++){
    if(hash[i] == 0){
        return i;
    }
   }
return -1;
}
int optimal_sol(vector<int> arr,int N){
    int sum = N*(N+1)/2;
    int s=0;
    int n = arr.size();
    for(int i =0;i<n;i++){
      s += arr[i];
    }
    return sum-s;
}

int main(){
    vector<int> arr;
    int n, N;
    cout << "Number of elements in array (should be N - 1): ";
    cin >> n;

    cout << "Input the maximum number N: ";
    cin >> N;

    cout << "Input array elements:\n";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    int ans = better_sol(arr, N);
    cout << "Missing element is: " << ans << endl;

    return 0;
}