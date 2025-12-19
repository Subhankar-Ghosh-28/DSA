#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
private:
    stack<pair<int,int>> st; // {price, index}
    int index;
    
public:
    StockSpanner() {
        index = 0;
    }
    
    int next(int price) {
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        
        int span = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        index++;
        
        return span;
    }
};

class Solution {
public:
    vector<int> bruteforce(vector<int> &arr, int n) {
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int currSpan = 0;
            for (int j = i; j >= 0; j--) {
                if(arr[j] <= arr[i]) currSpan++;
                else break;
            }
            ans[i] = currSpan;
        }
        return ans;
    }

    vector<int> optimal(vector<int> &arr, int n) {
        stack<pair<int,int>> st;
        vector<int> ans(n);
        
        for (int i = 0; i < n; i++) {
            while(!st.empty() && st.top().first <= arr[i]) {
                st.pop();
            }
            
            ans[i] = i - (st.empty() ? -1 : st.top().second); 
            st.push({arr[i], i});
        }
        
        return ans;
    }
};

int main() {
    int n = 7;
    vector<int> arr = {7, 2, 1, 3, 3, 1, 8};

    // Using Solution class (batch processing)
    Solution sol;
    vector<int> ans = sol.optimal(arr, n);
    cout << "Stock span (batch): ";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    // Using StockSpanner class (online/streaming)
    StockSpanner spanner;
    cout << "Stock span (online): ";
    for (int i = 0; i < n; i++) {
        cout << spanner.next(arr[i]) << " ";
    }
    cout << endl;
    
    return 0;
}