#include <bits/stdc++.h>
using namespace std;

string commonPrefix(vector<string> &s)
{
    sort(s.begin(), s.end());

    string s1 = s[0], s2 = s[s.size() - 1];

    string ans = "";

    int len = min(s1.size(), s2.size());

    for (int i = 0; i < len; i++)
    {
        if (s1[i] == s2[i])
        {
            ans += s1[i];
        }
        else
            break;
    }
    return ans;
}

int main()
{
    vector<string> input = {"interview", "internet", "internal", "interval"};

    string result = commonPrefix(input);

    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}