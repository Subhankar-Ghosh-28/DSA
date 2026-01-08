#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bruteForce(string s, string t)
    {
        if (s.length() != t.length())
        {
            return false; 
        }

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != t[i])
            {
                return false; 
            }
        }

        return true;     //tc-> o(nlogn);
    }

    bool brute2(string s, string t)
    {
        int n = s.size(), m = t.size();   //tc->o(nlog k)
        if (n != m)
            return false;
        map<char, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[s[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (mpp[t[i]] > 0)
            {
                mpp[t[i]]--;
            }

            if (mpp[t[i]] == 0)
                mpp.erase(t[i]);
        }
        if (mpp.size() == 0)
            return true;
        return false;
    }

    int optimal(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        int freq[26] = {0};

        for (char c : s)
            freq[c - 'a']++;
        for (char c : t)
            freq[c - 'a']--;

        for (int x : freq)
            if (x != 0)
                return false;

        return true;
    }
};

int main()
{
    string s = "cat",  t = "act";
    Solution sol;
    cout << sol.bruteForce(s, t) << endl;
    cout << sol.brute2(s, t) << endl;
    cout << sol.optimal(s, t) << endl;
    return 0;
}