#include <bits/stdc++.h>
using namespace std;

void solve(int idx, vector<int> &arr, vector<vector<int>> &ans)
{
    // Base case: one permutation completed
    if (idx == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[idx], arr[i]);   // choose
        solve(idx + 1, arr, ans); // explore
        swap(arr[idx], arr[i]);   // backtrack
    }
}

vector<vector<int>> getPermutations(vector<int> arr)
{
    vector<vector<int>> ans;
    solve(0, arr, ans);
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};

    vector<vector<int>> result = getPermutations(arr);

    for (auto &perm : result)
    {
        for (int x : perm)
            cout << x << " ";
        cout << endl;
    }
}
