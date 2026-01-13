/*
if 'abcd' is string then 'acd' is subsequence,,matter in order 'bac' not a subsequene ORDER MATTER;
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void optimalHelper(string &s, int index, string curr, vector<string> &result)
    {
        if (index == s.size())
        {
            if (curr == "")
                result.push_back("{}"); // empty subset
            else
                result.push_back(curr); // normal subset
            return;
        }
        // EXclude current character and recurse
        optimalHelper(s, index + 1, curr, result);

        curr.push_back(s[index]);

        // Include current character and recurse
        optimalHelper(s, index + 1, curr, result);

        // Backtrack: remove last character before returning to previous call
        curr.pop_back();
    }

public:
    vector<string> bruteForce(string s)
    {
        int n = s.length();
        vector<string> ans;
        int subsets = 1 << n; //-> 2^n

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
        /*
        TC -> O(2^n)*O(n)
        SC ->auxilary space
        */
    }

    vector<string> optimal(string s)
    {
        vector<string> result;

        string current = "";
        optimalHelper(s, 0, current, result);
        return result;

        /*
        tc->  O(n * 2^n)
        */
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

    result = sol.optimal(s);

    cout << "Output for optimal force: " << endl;
    cout << "[ ";
    for (auto &it : result)
    {
        cout << it << " ";
    }
    cout << "]" << endl;
    return 0;
}