#include <bits/stdc++.h>
using namespace std;

// all possible set of k numbers,, which sum = n , combination 1 to 9 an take one time a number

void helper(int n, int last, vector<int> &current, int k, vector<vector<int>> &result)
{
    if (current.size() == k && n == 0)
    {
        result.push_back(current);
        return;
    }

    if (n <= 0 || current.size() > k)
        return;

    for (int i = last; i <= 9; i++)
    {
        // If the current number is less than or equal to the sum
        if (i <= n)
        {
            // Add the number to the current combination
            current.push_back(i);

            helper(n - i, i + 1, current, k, result);
            current.pop_back();
        }
        // If the number is greater than the sum, break the loop
        else
            break;
    }
}

vector<vector<int>> combinationSum(int k, int n)
{ // k = the lenght of the possible ans

    vector<vector<int>> result;
    vector<int> current;
    helper(n, 1, current, k, result);
    return result;
    // Time Complexity: O(2^9 * k)
    //  Space Complexity: O(k), where k is the number of elements in the combination.
}

int main()
{
    int n = 9, k = 3;

    vector<vector<int>> result = combinationSum(k, n);
    cout << "Combinations are: " << endl;
    cout << "[ ";
    for (auto &x : result)
    {
        cout << "[ ";
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << " ]";
    }
    cout << " ]";
    return 0;
}