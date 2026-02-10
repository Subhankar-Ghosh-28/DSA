#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            bool left = (i == 0) || (nums[i] >= nums[i - 1]);
            bool right = (i == n - 1) || (nums[i] >= nums[i + 1]);

            if (left && right)
                return i;
        }
        return -1;
    }

    int optimal(vector<int> &nums)
    {
        int low = 0, high = nums.size() - 1;

        // Binary search loop
        while (low < high)
        {
            // Find mid point
            int mid = low + (high - low) / 2;

            // If mid element is greater than next
            if (nums[mid] > nums[mid + 1])
            {
                // Move to left half
                high = mid;
            }
            else
            {
                // Move to right half
                low = mid + 1;
            }
        }

        // Return peak index
        return low;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 20, 4, 1, 0};
    int index = sol.optimal(nums);
    cout << "Peak at index: " << index << " with value: " << nums[index] << endl;
    return 0;
}