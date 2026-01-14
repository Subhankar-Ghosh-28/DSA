#include <bits/stdc++.h>
using namespace std;

bool helper(int index, int currSum, string curr, vector<string> &result, int targetSum, string s)
{
    if (index == s.size())
    {
        if (currSum == targetSum)
        {
            result.push_back(curr);
            return true;
        }
        return false;
    }

    curr.push_back(s[index]);
    currSum += s[index] - '0';
    // take the element
    if (helper(index + 1, currSum, curr, result, targetSum, s))
        return true;

    currSum -= s[index] - '0';
    curr.pop_back();
    // not take the element
    if (helper(index + 1, currSum, curr, result, targetSum, s))
        return true;
    return false;
}

vector<string> allSubsequence(string s, int targetSum)
{
    vector<string> result;
    helper(0, 0, "", result, targetSum, s);
    return result;
}

int main()
{
    string s = "211";
    int target = 2;

    vector<string> res = allSubsequence(s, target);

    for (auto &it : res)
        cout << it << " ";

    cout << endl;
    return 0;
}