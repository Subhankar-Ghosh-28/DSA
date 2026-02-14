#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long calculateDivisor(vector<int> &nums, int divisor)
    {
        long long totalHour = 0;

        for (int pile : nums)
        {
            totalHour += (pile + divisor - 1) / divisor;
        }
        return totalHour;
    }

public:
    int bruteForce(vector<int> &nums, int maxlimit)
    {
        int maxval = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            maxval = max(maxval, nums[i]);
        }

        for (int i = 1; i <= maxval; i++)
        {
            long long limit = calculateDivisor(nums, i);

            if (limit <= maxlimit)
            {
                return i;
            }
        }
        return maxval;

        // TC -> O(n * max(nums[]))
    }

    int optimal(vector<int> &nums, int limit)
    {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int result = right;
        int n = nums.size();

        while (left <= right)
        {
            int mid = left + (right - left) / 2; 
            long long hours = 0;

            for (int i = 0; i < n; i++)
            {
                hours += ceil((double)nums[i] / (double)mid);
            }

            if (hours <= limit)
            {
                result = mid; 
                right = mid - 1;
            }
            else
            {
                left = mid + 1; 
            }
        }

        return result;
        // TC -> O(log N * max(nums[]))
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;

    Solution obj;
    int ans = obj.optimal(arr, limit);

    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}