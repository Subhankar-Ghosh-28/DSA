#include<bits/stdc++.h>
using namespace std;

// longest substring of a given string with atmost K distring character

class Solution {
public:
    int bruteForce(string s, int k) // TC = O(n*n) * O(log n) ,, sc = o(256);
    {
        int n = s.size();
        int maxLen = 0;
        
        for (int i = 0; i < n; i++)
        {
            set<char> st;

            for (int j = i; j < n; j++)
            {
                st.insert(s[j]);
                if(st.size() <= k){
                    maxLen = max (maxLen, j-i+1);
                }

                else break;
            }
            
        }
        return maxLen;

    }

    int better(string s, int k)  //TC = O(n+n)+O(256), sc = O(256);
    {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        map<char,int> mpp;

        while(r<n){
            mpp[s[r]]++;
            while(mpp.size()>k){
                mpp[s[l]]--;
                if(mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                maxLen =  max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }

    int optimal(string s, int k)  // tc = O(n)+O(log 256), sc = O(256)
    {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        map<char,int> mpp;

        while(r<n){
            mpp[s[r]]++;
            if(mpp.size() > k){
                 mpp[s[l]]--;
                if(mpp[s[l]] == 0) {
                    mpp.erase(s[l]);
                }
                l++;
            }
            if(mpp.size() <= k){
                maxLen =  max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};

int main(){
    string s = "aaabcccddab";
    int k = 2;
    Solution sol;
    cout << sol.bruteForce(s, k) << endl;
    cout << sol.better(s, k) << endl;
    cout << sol.optimal(s, k) << endl;

return 0;
}