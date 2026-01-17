#include <bits/stdc++.h>
using namespace std;
// a given arr and sum a give all possible combination subarray ,, a element all single time
class Solution
{

private:
    void bruteHelper(int index, int target, vector<int> &current, set<vector<int>> &result, vector<int> &nums)
    {
        if (index == nums.size())
        {
            if (target == 0)
                result.insert(current);
            return;
        }
        // take
        if (nums[index] <= target)
        {
            current.push_back(nums[index]);
            bruteHelper(index + 1, target - nums[index], current, result, nums);
            current.pop_back();
        }

        // non take
        bruteHelper(index + 1, target, current, result, nums);
    }

    void optimalHelper(int index, int target, vector<int> &current, vector<vector<int>> &result, vector<int> &nums)
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        { // Skip duplicates to avoid repeating combinations
            if (i > index && nums[i] == nums[i - 1])
                continue;
            // If the current element is greater than the remaining target, break the loop
            if (nums[i] > target)
                break;

            current.push_back(nums[i]);

            optimalHelper(i + 1, target - nums[i], current, result, nums);
            current.pop_back();
        }
    }

public:
    set<vector<int>> bruteForce(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        vector<int> current;
        bruteHelper(0, target, current, result, nums);
        return result;
    }

    vector<vector<int>> optimal(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        optimalHelper(0, target, current, result, nums);
        return result;
    }
};

int main()
{
    vector<int> v{1, 1, 1, 2, 2};
    int target = 7;

    Solution sol;

    vector<vector<int>> result = sol.optimal(v, target);
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