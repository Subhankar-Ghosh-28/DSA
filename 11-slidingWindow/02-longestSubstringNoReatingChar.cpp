#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteforce(string s)
    {
        int n = s.size();
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            int hash[256] = {0};

            for (int j = i; j < n; j++)
            {
                if (hash[s[j]] == 1)
                    break;
                int len = j - i + 1;
                maxLen = max(len, maxLen);
                hash[s[j]] = 1;
            }
        }
        return maxLen;
    }

    int optimal(string s)
    {
        int l = 0, r = 0, len = 0, maxlen = 0, hash[256] = {-1}, n = s.size();
        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                if (hash[s[r]] >= l)
                {
                    l = hash[s[r]] + 1;
                }
            }
            len = r - l + 1;
            maxlen = max(len, maxlen);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};

int main()
{
    string s = "cadbzabcd";
    Solution sol;
    cout << sol.optimal(s);
    return 0;
}
