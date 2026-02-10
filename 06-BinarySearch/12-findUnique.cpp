// there is a nums with same pair element and only 1 element is one time find it;

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (nums[1] != nums[0])
                    return nums[0];
            }
            else if (i == n - 1)
            {
                if (nums[n - 1] != nums[n - 2])
                    return nums[n - 1];
            }
            else
            {
                if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1])
                    return nums[i];
            }
        }
        return -1;
    }

    int better(vector<int> &nums)
    {
        int n = nums.size();

        int xor1 = 0;

        for (int i = 0; i < n; i++)
        {
            xor1 = xor1 ^ nums[i];
        }
        return xor1 == 0 ? -1 : xor1;
    }

    int optimal(vector<int> &nums)
    {
        int n = nums.size();

        if (n == 1)
            return nums[0];
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        int low = 1, high = n - 2;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
            {
                // Move to the right half
                low = mid + 1;
            }
            else
                // Move to the left half
                high = mid - 1;
        }
        // TC -> O(log N);
        return -1;
    }
};
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};

    Solution obj;

    int ans = obj.optimal(nums);

    cout << "The single element is: " << ans << "\n";
    return 0;
}