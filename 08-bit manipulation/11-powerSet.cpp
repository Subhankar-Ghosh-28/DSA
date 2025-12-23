// subset of a function

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> powerSet(vector<int> &arr)
{
    int n = arr.size();

    vector<vector<int>> ans;
    int subsets = 1 << n;
    for (int num = 0; num < subsets; num++)
    {
        vector<int> list;
        for (int i = 0; i < n; i++)
        {
            if (num & (1 << i))
                list.push_back(arr[i]);
        }
        ans.push_back(list);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = powerSet(arr);
    cout << "Subsets: " << endl;
    for (auto subset : ans)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}