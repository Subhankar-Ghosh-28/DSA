// minimum element of the arr

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        int mini = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < mini)
                mini = nums[i];
        }
        return -1;

        // TC -> O(N);
    }

    int optimal(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }

            else
                high = mid;
        }

        return nums[low];
    }
};

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};

    Solution sol;

    int result = sol.optimal(nums);

    cout << "Minimum element is " << result << endl;

    return 0;
}