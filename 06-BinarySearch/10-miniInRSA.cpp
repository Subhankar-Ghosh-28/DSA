// minimum element of the arr

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int mini = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < mini)
                mini = nums[i];
        }
        return -1;

        // TC -> O(N);
    }

    int optimal(vector<int> &nums, int k)
    {
    }
};

int main()
{

    return 0;
}