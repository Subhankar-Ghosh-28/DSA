#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int optimal (vector<int>& nums, int k){
     // Write your code here
    int left =0,right = 0;
    long long sum = nums[0];
    int maxlenght = 0;
    int n = nums.size();
    while(right<n){
        while(left<=right && sum>k){
            sum -= nums[left];
            left++;
        }
        if(sum ==k){
            maxlenght = max(maxlenght,right-left+1);
        }
        right++;
        if (right<n) sum += nums[right];
    }
    return maxlenght;
}
// brute sol for both +ve and -ve;

int brute (vector <int> &a,int k){
      int n = a.size(); // size of the array.

    map<int, int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        //calculate the prefix sum till index i:
        sum += a[i];

        // if the sum = k, update the maxLen:
        if (sum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // calculate the sum of remaining part i.e. x-k:
        int rem = sum - k;

        //Calculate the length and update maxLen:
        if (preSumMap.find(rem) != preSumMap.end()) {
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }

        //Finally, update the map checking the conditions:
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;
        }
    }

    return maxLen;
}

int main(){
      vector<int> a = {2, 3, 5, 1, 9};
    int k = 10;
    int len = optimal(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";
    
    return 0;
}