
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int index, int currSum, vector<int> &result, vector<int> &nums)
    {
        if (index == nums.size())
        {
            result.push_back(currSum);
            return;
        }
        // take
        helper(index + 1, currSum + nums[index], result, nums);
        // not take
        helper(index + 1, currSum, result, nums);
    }

public:
    vector<int> bitMasking(vector<int> &masks)
    {
        int n = masks.size();
        vector<int> ans;
        int subsets = 1 << n;

        for (int mask = 0; mask < subsets; mask++)
        {
            vector<int> list;
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    sum += masks[i];
            }
            ans.push_back(sum);
        }
        return ans;
    }

    vector<int> recursive(vector<int> &nums)
    {
        vector<int> result;

        helper(0, 0, result, nums);

        sort(result.begin(), result.end());
        return result;
    }

    // tc ->O(2^n log(2^n))
};

int main()
{
    vector<int> arr = {2, 3};
    Solution sol;
    vector<int> result = sol.recursive(arr);
    for (auto it : result)
    {
        cout << it << " ";
    }
    return 0;
}