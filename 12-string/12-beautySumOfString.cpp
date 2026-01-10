/*
a substring (max frequeny of a substring - min freq in the substring) and return total;

substring->  aabc  max freq 'a' = 2 and min b/c = 1 sum = 2-1;

totalSum = ...

*/
#include <bits/stdc++.h>
using namespace std;

int beautySum(string s)
{
    int n = s.length();
    int sum = 0;

    // Loop over all substrings
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> freq;

        for (int j = i; j < n; j++)
        {
            // Increase frequency of current character
            freq[s[j]]++;

            int maxi = INT_MIN;
            int mini = INT_MAX;

            // Find max and min frequency
            for (auto it : freq)
            {
                mini = min(mini, it.second);
                maxi = max(maxi, it.second);
            }

            // Add difference to sum
            sum += (maxi - mini);
        }
    }

    return sum;
}

int main()
{
    string s = "aabcbaa";
    cout << "Beauty Sum: " << beautySum(s) << endl;
    return 0;
}
