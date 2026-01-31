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
        vector<int> ans(n);
        int i = 0, j = 0;

        while (i < pos.size() && j < neg.size())
        {
            ans.push_back(pos[i++]);
            ans.push_back(neg[j++]);
        }

        while (i < pos.size())
            ans.push_back(pos[i++]);
        while (j < neg.size())
            ans.push_back(neg[j++]);

        return ans;

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