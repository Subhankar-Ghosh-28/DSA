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
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = nums[high] - (mid + 1);

            if (missing < k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low + k; // high + 1 + k;   ans = arr[higg] + more,, more = k - (arr[high] - (high+1));

        // TC -> O(log N);
    }
};

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int k = 4;

    Solution finder;
    int ans = finder.optimal(vec, k);

    cout << "The missing number is: " << ans << "\n";
    return 0;
}