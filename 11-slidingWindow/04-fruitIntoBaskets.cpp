#include <bits/stdc++.h>
using namespace std;

/*

Fruit Into Baskets
Problem Statement: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.

*/

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            set<int> st;
            for (int j = i; j < n; j++)
            {
                st.insert(nums[j]);
                if (st.size() <= k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                    break;
            }
        }
        return maxLen;
    }

    int better(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), maxLen = 0;
        map<int, int> mpp;

        while (r < n)
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            if (mpp.size() <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }

    int optimal(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), maxLen = 0;
        map<int, int> mpp;

        while (r < n)
        {
            mpp[nums[r]]++;
            if (mpp.size() > k)
            {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0)
                    mpp.erase(nums[l]);
                l++;
            }

            if (mpp.size() <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
            r++;
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    int k = 2;
    Solution sol;
    cout << sol.bruteForce(arr, k) << endl;
    cout << sol.better(arr, k) << endl;
    cout << sol.optimal(arr, k) << endl;

    return 0;
}