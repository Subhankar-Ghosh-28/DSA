#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(string s, int k)
    {
        int maxLen = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int hash[26] = {0};
            int maxf = 0;
            for (int j = i; j < s.size(); j++)
            {
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxf;
                if (changes <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                    break;
            }
        }
        return maxLen;
    }

    int better(string s, int k)
    {
        int l = 0, r = 0, maxLen = 0, n = s.size(), maxf = 0, hash[26] = {0};

        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);

            while ((r - l + 1) - maxf > k)
            {
                hash[s[l] - 'A']--;
                maxf = 0;
                for (int i = 0; i < 25; i++)
                {
                    maxf = max(maxf, hash[i]);
                }
                l++;
            }

            if ((r - l + 1) - maxf <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }

    int optimal(string s, int k)
    {
        int n = s.size(), l = 0, r = 0, maxf = 0, maxlen = 0, hash[26] = {0};

        while (r < n)
        {
            hash[s[r] - 'A']++;
            maxf = max(maxf, hash[s[r] - 'A']);
            if ((r - l + 1) - maxf > k)
            {
                hash[s[l] - 'A']--;
                l++;
            }
            if ((r - l + 1) - maxf <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};

int main()
{
    string s = "AAABBCCD";
    int k = 2;
    Solution sol;
    cout << sol.bruteForce(s, k) << endl;
    cout << sol.better(s, k) << endl;
    cout << sol.optimal(s, k) << endl;
    return 0;
}