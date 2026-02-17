/* Problem Statement: You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to
another. The packages must be shipped within 'd' days. The weights of the packages are given in an array 'of weights'. The
packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not
exceed the maximum weight capacity of the ship. Find out the least-weight capacity so that you can ship all the packages
within 'd' days .
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int daysNeeded(vector<int> &weights, int capacity)
    {
        int days = 1;
        int currentLoad = 0;
        for (int w : weights)
        {
            if (currentLoad + w > capacity)
            {
                days++;
                currentLoad = w;
            }
            else
            {
                currentLoad += w;
            }
        }
        return days;
    }

public:
    int bruteForce(vector<int> &weights, int day)
    {
        int left = *max_element(weights.begin(), weights.end());

        // Find total sum as maximum capacity
        int right = accumulate(weights.begin(), weights.end(), 0);

        // Iterate from minimum to maximum capacity
        for (int capacity = left; capacity <= right; capacity++)
        {
            int needed = daysNeeded(weights, capacity);
            if (needed <= day)
            {
                return capacity;
            }
        }

        return right;

        // TC -> O((sum_weights - max_weight) * N)
    }

    int optimal(vector<int> &weights, int day)
    {
        int left = *max_element(weights.begin(), weights.end());

        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int needed = daysNeeded(weights, mid);
            if (needed <= day)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;

        // TC -> O(N * log(S)),, S = sum_weights - max_weight;
    }
};

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    Solution sol;
    cout << sol.bruteForce(weights, d) << "\n";
    return 0;
}