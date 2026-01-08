#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string bruteForce(string s, string k)
    {
        int minlen = 1e9, sInd = -1, n = s.size(), m = k.size();

        for (int i = 0; i < n; i++)
        {
            int hash[256] = {0};
            for (int j = 0; j < m; j++)
            {
                hash[k[j]]++;
            }
            int cnt = 0;
            for (int j = i; j < n; j++)
            {
                if(hash[s[j]]>0) cnt++;
                hash[s[j]]--;
                if(cnt == m){
                    if(j-i+1 <minlen){
                        minlen = j-i+1;
                        sInd = i;
                    }
                    break;
                }
            }
            
        }
        return sInd == -1 ? "no" : s.substr(sInd, minlen);
    }

    string optimal(string s, string k)
    {
        int l = 0, r= 0, minlen = 1e9, sInd = -1, n = s.size(), m = k.size(), cnt = 0;
        int hash[256] = {0};

        for (int i = 0; i < m; i++)
        {
            hash[k[i]]++;
        }
        while(r<n){
            if(hash[s[r]]>0)cnt++;
            hash[s[r]]--;
            while(cnt == m){
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sInd = l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0)cnt--;
                l++;
            }
            r++;
        }
        return sInd == -1?"no": s.substr(sInd,minlen);   // tc = o(m)+o(n)+o(n) sc = o(256)
    }
};

int main(){
     string s = "ddaaabbca";
    string k = "abc";
    Solution sol;
    cout << sol.bruteForce(s, k) << endl;
    cout << sol.optimal(s, k) << endl;
return 0;
}