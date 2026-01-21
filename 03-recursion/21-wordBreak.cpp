#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.length();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(n + 1, false);
    dp[0] = true;

    int maxLen = 0;

    for (auto &word : wordDict)
    {
        maxLen = max(maxLen, (int)word.size());
    }

    // DP to check if the string can be segmented
    for (int i = 1; i <= n; ++i)
    {
        for (int j = max(0, i - maxLen); j < i; ++j)
        {
            if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end())
            {
                dp[i] = true;
                break; // Early termination when we find a valid word
            }
        }
    }

    return dp[n];
}

// tc : O(n*m) n -> string len ,,, m -> dict avg len for inner loop
// sc : O(n) for dp size

int main()
{
    string s = "takeuforward";
    vector<string> wordDict = {"take", "forward", "you", "u"};

    if (wordBreak(s, wordDict))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}