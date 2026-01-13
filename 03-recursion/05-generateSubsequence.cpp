/*
if 'abcd' is string then 'acd' is subsequence,,matter in order 'bac' not a subsequene ORDER MATTER;
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> bruteForce(string s)
    {
        int n = s.length();
        vector<string> ans;
        int subsets = 1 << n;

        for (int num = 0; num < subsets; num++)
        {
            string subseq = "";

            for (int i = 0; i < n; i++)
            {
                if (num & (1 << i))
                {
                    subseq += s[i];
                }
            }
            ans.push_back(subseq);
        }
        return ans;
    }

    int optimal(string s)
    {
    }
};

int main()
{
    string s = "abc";

    Solution sol;

    vector<string> result = sol.bruteForce(s);

    cout << "Output for brute force: " << endl;
    cout << "[ ";
    for (auto &it : result)
    {
        cout << it << " ";
    }
    cout << "]" << endl;
    return 0;
}