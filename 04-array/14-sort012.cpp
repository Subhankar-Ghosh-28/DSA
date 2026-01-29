#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bruteForce(vector<int> &nums)
    {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                cnt0++;
            else if (nums[i] == 1)
                cnt1++;
            else
                cnt2++;
        }
        int idx = 0;
        vector<int> ans;

        while (cnt0 > 0)
        {
            ans[idx++] = 0;
            cnt0--;
        }
        while (cnt1 > 0)
        {
            ans[idx++] = 1;
            cnt1--;
        }
        while (cnt2 > 0)
        {
            ans[idx++] = 2;
            cnt2--;
        }
        return ans;
    }

    void optimal(vector<int> &nums)
    { // Don't change the original create a duplicate
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution sol;
    sol.optimal(nums);

    for (int val : nums)
        cout << val << " ";

    return 0;
}