#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// arange pos and neg of an array and pos and neg are not same number
class Solution
{
public:
    vector<int> bruteForce(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] < 0)
            {
                neg.push_back(nums[i]);
            }
            else
                pos.push_back(nums[i]);
        }

        if (pos.size() < neg.size())
        {
            for (int i = 0; i < pos.size(); i++)
            {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }

            int index = pos.size() * 2;
            for (int i = pos.size(); i < neg.size(); i++)
            {

                nums[index] = neg[i];
                index++;
            }
        }
        else
        {
            for (int i = 0; i < neg.size(); i++)
            {
                nums[2 * i] = pos[i];
                nums[2 * i + 1] = neg[i];
            }
            int index = neg.size() * 2;
            for (int i = neg.size(); i < pos.size(); i++)
            {
                nums[index] = pos[i];
                index++;
            }
        }
        return nums;

        // TC -> O(N) sc ->O(N); overall
    }
    // “The index-jump optimal solution works only when positives and negatives are equal; otherwise we must handle remaining elements separately.”
    vector<int> optimal(vector<int> &nums)
    {
        int n = nums.size(), positive = 0, negative = 1;
        vector<int> ans(n);

        for (auto num : nums)
        {
            if (num < 0)
            {
                ans[negative] = num;
                negative += 2;
            }
            else
            {
                ans[positive] = num;
                positive += 2;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> A = {1, 2, -4, -5, -7};
    Solution sol;
    vector<int> ans = sol.optimal(A);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}