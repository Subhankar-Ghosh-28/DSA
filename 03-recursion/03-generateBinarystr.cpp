// Problem Statement: Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.

#include <bits/stdc++.h>
using namespace std;

void generate(int n, string curr, vector<string> &result)
{
    if (curr.size() == n)
    {
        result.push_back(curr);
        return;
    }

    generate(n, curr + "0", result);

    if (curr.empty() || curr.back() == '0')
    {
        generate(n, curr + "1", result);
    }
}
int main()
{
    // Input length n
    int n = 3;

    // Vector to store results
    vector<string> result;

    // Start recursion with empty string
    generate(n, "", result);

    // Print results
    for (string &s : result)
    {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}