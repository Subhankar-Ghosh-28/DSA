// a number that is appear one time butother 2 times;

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
            int cnt = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] == nums[j])
                {
                    cnt++;
                }
            }
            if (cnt == 0)
                return nums[i];
        }
        return -1;

        // TC -> O(N^2);
        // SC -> O(1);
    }

    int better(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> mpp;

        for (auto it : nums)
        {
            mpp[it]++;
        }

        for (auto it : mpp)
        {
            if (it.second == 1)
            {
                return it.first;
            }
        }
        return -1;
    }

    int optimal(vector<int> &nums)
    {
        int n = nums.size();
        int Xor = 0;

        for (int i = 0; i < n; i++)
        {
            Xor ^= nums[i];
        }
        return Xor == 0 ? -1 : Xor;
    }
};

int main()
{
    vector<int> nums = {1, 2, 2};

    Solution sol;
    cout << sol.bruteForce(nums) << endl;
    cout << sol.better(nums) << endl;
    cout << sol.optimal(nums) << endl;
    return 0;
}