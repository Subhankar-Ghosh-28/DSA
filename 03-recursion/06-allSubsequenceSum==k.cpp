#include <bits/stdc++.h>
using namespace std;

void helper(int index, int currSum, string curr, vector<string> &result, int targetSum, string s)
{
    if (index == s.size())
    {
        if (currSum == targetSum)
            result.push_back(curr);
        return;
    }

    curr.push_back(s[index]);
    currSum += s[index] - '0';
    // take the element
    helper(index + 1, currSum, curr, result, targetSum, s);

    currSum -= s[index] - '0';
    curr.pop_back();
    // not take the element
    helper(index + 1, currSum, curr, result, targetSum, s);
}

vector<string> allSubsequence(string s, int targetSum)
{
    vector<string> result;
    helper(0, 0, "", result, targetSum, s);
    return result;
}

int main()
{
    string s = "121";
    int target = 2;

    vector<string> res = allSubsequence(s, target);

    for (auto &it : res)
        cout << it << " ";

    cout << endl;
    return 0;
}