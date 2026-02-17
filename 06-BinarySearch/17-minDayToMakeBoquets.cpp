#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPossible(vector<int> &bloomDays, int day, int m, int k)
    {
        int count = 0; // consecutive flowers that bloomed by 'day'
        int bouquets = 0;

        for (int bloom : bloomDays)
        {
            if (bloom <= day)
            {
                count++;
                if (count == k)
                {
                    bouquets++;
                    count = 0;
                }
            }
            else
            {
                count = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int bruteForce(vector<int> &bloomDays, int m, int k)
    {
        long long totalFlowers = 1LL * m * k;
        if (totalFlowers > bloomDays.size())
            return -1; 

        int low = *min_element(bloomDays.begin(), bloomDays.end());  // TC -> min(arr[])
        int high = *max_element(bloomDays.begin(), bloomDays.end()); // TC -> max(arr[])

        for (int day = low; day <= high; ++day)
        {
            if (isPossible(bloomDays, day, m, k))
            {
                return day;
            }
        }

        return -1; 

        // TC -> O((max(arr[])-min(arr[])+1) * N)
    }

    int optimal(vector<int> &bloomDays, int m, int k)
    {
        long long totalFlowers = 1LL * m * k;
        if (totalFlowers > bloomDays.size())
            return -1; 

        int mini = *min_element(bloomDays.begin(), bloomDays.end()); // TC -> min(arr[])
        int maxi = *max_element(bloomDays.begin(), bloomDays.end()); // TC -> max(arr[])

        int low = mini, high = maxi;
        int result = -1;

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (isPossible(bloomDays, mid, m, k))
            {
                result = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return result;

       // tc -> O(log(max(arr[])-min(arr[])+1) * N
    }
};

int main()
{
    vector<int> bloomDays = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;

    Solution garden;
    int result = garden.bruteForce(bloomDays, m, k);

    if (result == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << result << "\n";

    return 0;
}