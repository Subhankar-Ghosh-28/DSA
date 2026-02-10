#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return -1;
        int mini = nums[0];
        int miniIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] < mini)
            {
                mini = nums[i];
                miniIndex = i;
            }
        }
        return miniIndex;

        // TC -> O(N);
    }

    int better(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                return i + 1;
            }
        }

        return 0;

        // TC -> O(N);
    }

    int optimal(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
            {
                low = mid + 1;
            }

            else
                high = mid;
        }

        return low;

        // TC -> O(log N);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {4,5,6,7,0,1,2,3};

    int rotations = sol.optimal(arr);

    cout << rotations << endl;
    return 0;
}