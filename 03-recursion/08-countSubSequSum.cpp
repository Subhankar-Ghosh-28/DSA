// count sub sequences whose sums are eqrual to given sum;

#include <bits/stdc++.h>
using namespace std;

int helper(int ind, int currSum, vector<int> &nums, int sum)
{
    // slidely decrease the tc if we add this
    if(currSum > sum) return 0;
    if (ind == nums.size())
    {
        if (currSum == sum)
            return 1;
        else
            return 0;
    }
//take condition
    currSum += nums[ind];
    int l = helper(ind + 1, currSum, nums, sum);
//not take condition
    currSum -= nums[ind];
    int r = helper(ind + 1, currSum, nums, sum);
    return l + r;
}

int countSubSequence(vector<int> &nums, int sum)
{
    return helper(0, 0, nums, sum);
}

int main()
{
    vector<int> nums = {1, 2, 1, 1, 1};
    int sum = 2;
    cout << countSubSequence(nums, sum);
    return 0;
}