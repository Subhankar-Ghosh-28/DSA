#include <bits/stdc++.h>
using namespace std;
//  given digits from 2 to 9 (inclusive). Return all possible letter combination in a dial pad

void func(int ind, string digits, string s, vector<string> &ans, string combos[])
{
    if (ind == digits.size())
    {
        ans.push_back(s);
        return;
    }
    // Convert the current character to an integer
    int digit = digits[ind] - '0';
    // take 1st digit and then other
    for (int i = 0; i < combos[digit].size(); i++)
    {

        func(ind + 1, digits, s + combos[digit][i], ans, combos);
    }
}

vector<string> letterCombinations(string digits)
{
    // Mapping digits to corresponding characters
    string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string s = "";
    func(0, digits, s, ans, combos);
    return ans;
}

/* Time Complexity: O(4^N * N), where n is the length of the input digits.
This is because each digit can map to up to 4 letters, and there are n digits.
Space Complexity: O(N), where n is the length of the input digits. This is due to the recursion stack depth. */

int main()
{

    string digit = "34";

    for (auto it : letterCombinations(digit))
    {
        cout << it << " ";
    }

    return 0;
}