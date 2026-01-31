#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        int n = nums.size();
        int maxProfit = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int profit = nums[j] - nums[i];

                maxProfit = max(maxProfit, profit);
            }
        }
        return maxProfit;
    }

    int optimal(vector<int> &nums)
    {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minPrice)
                minPrice = nums[i];
            else
                maxProfit = max(maxProfit, nums[i] - minPrice);
        }
        return maxProfit;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Max Profit: " << sol.bruteForce(prices) << endl;
    cout << "Max Profit: " << sol.optimal(prices) << endl;

    return 0;
}