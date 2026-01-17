#include <bits/stdc++.h>
using namespace std;
// a given arr and sum a give all possible combination subarray ,, a element all multiply time
class Solution
{
private:
    void helper(int index, int target, vector<int> &current, vector<vector<int>> &result, vector<int> &nums)
    {
        if (index == nums.size())
        {
            if (target == 0)
                result.push_back(current);
            return;
        }
        // take
        if (nums[index] <= target)
        {
            current.push_back(nums[index]);
            helper(index, target - nums[index], current, result, nums);
            current.pop_back();
        }

        // non take
        helper(index + 1, target, current, result, nums);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        vector<int> current;
        helper(0, target, current, result, nums);
        return result;
    }
};
;

int main()
{
    vector<int> v{2, 3, 6, 7};
    int target = 7;

    Solution sol;

    vector<vector<int>> result = sol.combinationSum(v, target);
    cout << "Combinations are: " << endl;
    for (auto &x : result)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}