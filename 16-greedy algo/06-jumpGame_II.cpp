// It is strickly go to end
// minimum step to go end

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int position)
    {
        if (position >= nums.size() - 1)
            return 0;

        if (nums[position] == 0)
            return INT_MAX;

        int minStep = INT_MAX;

        for (int jump = 1; jump <= nums[position]; ++jump)
        {
            int subResult = bruteForce(nums, position + jump);

            if (subResult != INT_MAX)
                minStep = min(minStep, 1 + subResult);
        }

        return minStep;

        // TC-> O(2 ^ n);
    }

    int optimal(vector<int> &nums)
    {
        int jumps = 0, currentEnd = 0, farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i)
        {

            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd)
            {
                jumps++;

                currentEnd = farthest;
            }
        }
        return jumps; // TC-> O(n);
    }
};

int main()
{

    Solution sol;
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Minimum jumps required: " << sol.optimal(nums) << endl;

    return 0;
}