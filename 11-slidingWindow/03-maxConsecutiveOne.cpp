#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int maxLen = 0;
        int len = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int zeros = 0;
            for (int j = i; j < n; j++)
            {
                if (nums[j] == 0)
                    zeros++;
                if (zeros <= k)
                {
                    len = j - i + 1;
                    maxLen = max(maxLen, len);
                }
                else
                    break;
            }
        }
        return maxLen;
    }

    int better(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), len = 0, zeros = 0, maxLen = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;
            while (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
            {
                len = r - l + 1;
                maxLen = max(len, maxLen);
                r++;
            }
        }
        return maxLen;
    }

    int optimal(vector<int> &nums, int k)
    {
        int l = 0, r = 0, n = nums.size(), len = 0, zeros = 0, maxLen = 0;
        while (r < n)
        {
            if (nums[r] == 0)
                zeros++;
            while (zeros > k)
            {
                if (nums[l] == 0)
                    zeros--;
                l++;
            }
            if (zeros <= k)
            {
                len = r - l + 1;
                maxLen = max(len, maxLen);
                r++;
            }
        }
        return maxLen;
    }
};

int main()
{

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution sol;
    cout << sol.bruteForce(nums, k) << endl;
    cout << sol.better(nums, k) << endl;
    cout << sol.optimal(nums, k) << endl;

    return 0;
}