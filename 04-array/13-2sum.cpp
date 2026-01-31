#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> bruteForce(vector<int> &nums, int target)
    {
        int n = nums.size();
        int a, b;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    vector<int> better(vector<int> &nums, int target)
    {
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (mpp.find(complement) != mpp.end())
            {
                return {mpp[complement], i};
            }
            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }

    vector<int> optimal(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<pair<int, int>> numsWithIndex;

        for (int i = 0; i < n; i++)
        {
            numsWithIndex.push_back({nums[i], i});
        }
        sort(nums.begin(), nums.end());
        int r = n - 1, l = 0;
        while (r < nums.size())
        {
            int sum = numsWithIndex[l].first + numsWithIndex[r].first;

            if (sum == target)
            {
                return {numsWithIndex[l].second, numsWithIndex[r].second};
            }

            else if (sum > target)
                r--;
            else
                l++;
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    Solution sol;

    cout << "Brute Force Approach: ";
    vector<int> res1 = sol.bruteForce(arr, target);
    cout << "[" << res1[0] << ", " << res1[1] << "]\n";

    cout << "Better Approach (Hash Map): ";
    vector<int> res2 = sol.better(arr, target);
    cout << "[" << res2[0] << ", " << res2[1] << "]\n";

    cout << "Optimal Approach (Two Pointers): ";
    vector<int> res3 = sol.optimal(arr, target);
    cout << "[" << res3[0] << ", " << res3[1] << "]\n";

    return 0;
}
