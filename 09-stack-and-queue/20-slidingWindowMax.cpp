#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bruteforce(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> list;
        for (int i = 0; i <= n - k; i++)
        {
            int maxi = arr[i];
            for (int j = i; j <= i + k - 1; j++)
            {
                maxi = max(maxi, arr[j]);
            }
            list.push_back(maxi);
        }
        return list;
    }

    vector<int> optimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        vector<int> list;
        deque<int> dq;
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() <= i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && arr[dq.back()] <= arr[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                list.push_back(arr[dq.front()]);
            }
        }
        return list;
    }
};

int main()
{
    int k = 3;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 2, 1, 6};
    Solution sol;
    vector<int> ans = sol.optimal(arr, k);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}