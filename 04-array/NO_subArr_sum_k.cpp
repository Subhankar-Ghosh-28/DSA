#include<bits/stdc++.h>
using namespace std;

int brute(vector<int> &arr,int k){
    int n = arr.size();
    int count= 0;
    for(int i =0; i<n;i++){
        for (int j = i; j < n; j++){
          int  sum =0;
            for(int k= i;k<=j; k++){
                sum += arr[k];
            }
            if(sum == k) count ++;
        }
    }
    return count;
}

int better(vector<int> &arr,int k){
     int n = arr.size();
    int count= 0;
    for(int i =0; i<n;i++){
          int  sum =0;
        for (int j = i; j < n; j++){
                sum += arr[j];
            if(sum == k) count ++;
        }
    }
    return count;
}

int optimal(vector<int> &arr,int k){
    int n = arr.size();
    map<int,int>mpp;
    mpp[0] = 1;
    int presum= 0;
    int cnt = 0;
    for(int i =0; i<n;i++){            // TC = o(n) sc = o(n)
        presum += arr[i];
        int remove = presum -k;
        cnt += mpp[remove];
        mpp[presum] +=1;
    }
    return cnt;
}

int main(){
      vector<int> arr = {3, 1, 2, 4};
    int k = 6;
    int cnt = optimal(arr, k);
    cout << "The number of subarrays is: " << cnt << "\n";
    return 0;
    
}