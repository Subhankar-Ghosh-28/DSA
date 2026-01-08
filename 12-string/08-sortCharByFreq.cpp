#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    static bool comparator(pair<int, char> p1, pair<int, char> p2)
    {
        if (p1.first > p2.first)
            return true;
        if (p1.first < p2.first)
            return false;
        return p1.second < p2.second;
    }

public:
    vector<char> optimal(string &s)
    {
        // Array to store frequency and character
        pair<int, char> freq[26];
        for (int i = 0; i < 26; i++)
        {
            freq[i] = {0, i + 'a'};
        }
        for (char ch : s)
        {
            freq[ch - 'a'].first++;
        }
        sort(freq, freq + 26, comparator);
        vector<char> ans;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i].first > 0)
                ans.push_back(freq[i].second);
        }
        return ans;
    }
};

int main()
{
    string s = "tree";
    Solution sol;
    for (auto it : sol.optimal(s))
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}