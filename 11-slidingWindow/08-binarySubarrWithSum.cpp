#include <bits/stdc++.h>
using namespace std;

// binary subarray with given sum there is same  question in array that is longest subarray with given sum.

class Solution
{
public:
    int bruteForce(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[goal];
                }
                if (sum == goal)
                    count++;
            }
        }
        return count;
    }

    int better(vector<int> &nums, int goal)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];

                if (sum == goal)
                    count++;
            }
        }
        return count;
    }

    int optimal(vector<int> &nums, int goal)
    {
        int n = nums.size();
        map<int, int> mpp;
        mpp[0] = 1;
        int presum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        { // TC = o(n) sc = o(n)
            presum += nums[i];
            int remove = presum - goal;
            cnt += mpp[remove];
            mpp[presum] += 1;
        }
        return cnt;
    }

    // it is a binary array for this there is some improvement in optimal
    // not the TC only in SC.

    int optimal2(vector<int> &nums, int goal)
    {
        if (goal < 0)
            return 0;

        int l = 0, r = 0, sum = 0, count = 0, n = nums.size();

        while (r < n)
        {
            sum += nums[r];
            while (sum > goal)
            {
                sum = sum - nums[l];
                l++;
            }
            if (sum <= goal)
                count = count + (r - l + 1);
            r++;
        }
        return count;
    }

    int fuctioncall(vector<int> &nums, int goal)
    {
        return optimal2(nums, goal) - optimal2(nums, goal - 1);
    }
};

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    Solution sol;
    cout << sol.bruteForce(nums, goal) << endl;
    cout << sol.better(nums, goal) << endl;
    cout << sol.optimal(nums, goal) << endl;
    cout << sol.fuctioncall(nums, goal) << endl;
    return 0;
}