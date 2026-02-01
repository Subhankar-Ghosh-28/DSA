#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;

                for (int ind = i; ind <= j; ind++)
                {
                    sum += nums[ind];
                }
                if (sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int better(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int optimal(vector<int> &nums, int k)
    {
        map<int, int> prefixSumCnt;

        prefixSumCnt[0] = 1;

        int prefixSum = 0, count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];

            int remove = prefixSum - k;

            if (prefixSumCnt.find(remove) != prefixSumCnt.end())
            {
                count += prefixSumCnt[remove];
            }

            prefixSumCnt[prefixSum]++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 4};

    int k = 6;

    Solution sol;

    int result = sol.optimal(arr, k);

    cout << "The number of subarrays is: " << result << "\n";
    return 0;
}