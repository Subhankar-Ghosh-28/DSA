#include<bits/stdc++.h>
using namespace std;
//search for the index of the target value in the sorted array.

int inssertPosition(vector<int> &arr, int k){
    int low = 0, high = arr.size();
    int ans = arr.size();
    while(low<= high){
        int mid = low + (high - low)/2;

        if(arr[mid] >= k){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
int main(){

return 0;
}