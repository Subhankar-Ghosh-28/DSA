// give partition of give string which is palindromme
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string &s, int low, int high)
{
    while (low < high)
    {

        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }

    return true;
}
void backtrack(int index, string &s, vector<string> &current, vector<vector<string>> &ans)
{
    if (index == s.size())
    {
        ans.push_back(current);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            current.push_back(s.substr(index, i - index + 1));

            backtrack(i + 1, s, current, ans);
            current.pop_back();
        }
    }
}

//Time Complexity: O(2^N * N),, sc = O(2^N * N)+ O(N)

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> result;
    vector<string> current;

    backtrack(0, s, current, result);
    return result;
}

int main()
{

    string s = "aabb";

    for (auto &x : partition(s))
    {
        cout << "[";
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "]";
        cout << endl;
    }
    return 0;
}
