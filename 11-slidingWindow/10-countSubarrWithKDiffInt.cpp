#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            set<int> st;
            for (int j = i; j < nums.size(); j++)
            {
                st.insert(nums[j]);
                if (st.size() == k)
                    cnt++;
                else if (st.size() > k)
                    break;
            }
        }
        return cnt;
    }

    int func(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;
        int l = 0, r = 0, n = nums.size(), cnt = 0;
        map<int, int> mpp;

        while (r < n)
        {
            mpp[nums[r]]++;
            while (mpp.size() > k)
            {                   // -> if instead of while when shrinking If the window becomes
                mpp[nums[l]]--; // very invalid,removing only one element may still leave
                if (mpp[nums[l]] == 0)
                {
                    mpp.erase(nums[l]);
                }
                l++;
            }
            if (mpp.size() <= k)
            {
                cnt += r - l + 1;
            }
            r++;
        }
        return cnt;
    }

    int optimal(vector<int> &nums, int k)
    {
        return func(nums, k) - func(nums, k - 1);
    }
};

int main()
{
    vector<int> nums = {1, 2, 1, 3, 4};
    int goal = 3;
    Solution sol;
    cout << sol.bruteForce(nums, goal) << endl;
    cout << sol.optimal(nums, goal) << endl;
    return 0;
}