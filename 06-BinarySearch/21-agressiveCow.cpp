#include <bits/stdc++.h>
using namespace std;

// this is the pattern (min)max,,, (max)min

// aggressive cow is min distance b/w two cow is max

class Solution
{
private:
    bool canPlace(vector<int> &arr, int dist, int cows)
    {
        int cow = 1, lastCow = arr[0];

        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastCow >= dist)
            {
                cow++;
                lastCow = arr[i];
            }
        }
        return (cow >= cows);
    }

public:
    int bruteForce(vector<int> &arr, int cows)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        int maxDist = arr[n - 1] - arr[0];

        for (int i = 1; i <= maxDist; i++)
        {
            if (canPlace(arr, i, cows))
                ans = i;
        }
        return ans;

        // TC -> O(nlog n) + O(max - min) * O(n);
    }

    int optimal(vector<int> &arr, int cows)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int ans = 0;
        int low = arr[0], high = arr[n - 1] - arr[0];

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (canPlace(arr, mid, cows))
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;

        // TC -> O(nlog n) + O(log (max - min)) * O(n);
    }
};

int main()
{
    vector<int> arr = {0, 3, 7, 4, 10, 9};
    int cows = 4;

    Solution sol;
    cout << "The maximum value of minimum distance b/w cows is : " << sol.optimal(arr, cows);
    return 0;
}