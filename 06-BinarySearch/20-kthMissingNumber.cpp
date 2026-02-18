#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            if (nums[i] <= k)
                k++;
            else
                break;
        }
        return k;

        // TC -> O(N);
    }

    int optimal(vector<int> &nums, int k)
    {
    }
};

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int k = 4;

    Solution finder;
    int ans = finder.bruteForce(vec, k);

    cout << "The missing number is: " << ans << "\n";
    return 0;
}