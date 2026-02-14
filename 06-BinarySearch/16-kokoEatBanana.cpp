#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int calculateHours(vector<int> &nums, int hour)
    {
        int totalHour = 0;

        for (int pile : nums)
        {
            totalHour += (pile + hour - 1) / hour;
        }
        return totalHour;
    }

public:
    int bruteForce(vector<int> &nums, int totalHour)
    {
        int maxval = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            maxval = max(maxval, nums[i]);
        }

        for (int i = 1; i <= maxval; i++)
        {
            int hour = calculateHours(nums, i);

            if (hour <= totalHour)
            {
                return i;
            }
        }
        return maxval;

        // TC -> O(n * max(nums[]))
    }

    int optimal(vector<int> &nums, int totalHour)
    {
        int n = nums.size();

        int maxPile = INT_MIN;

        for (auto pile : nums)
        {
            if (maxPile < pile)
                maxPile = pile;
        }

        int low = 0, high = maxPile;
        int ans = maxPile;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            int hour = calculateHours(nums, mid);

            if (hour <= totalHour)
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;

        // TC -> O(log N * max(nums[]))
    }
};

int main()
{

    vector<int> a = {3, 6, 7, 11};
    // Hours allowed
    int h = 8;

    Solution obj;
    cout << obj.optimal(a, h);

    return 0;
}