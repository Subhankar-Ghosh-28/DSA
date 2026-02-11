#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(int n, int m)
    {
        for (int i = 1; i <= m; i++)
        {
            long long power = pow(i, n);

            if (power == m)
                return i;

            if (power > m)
                break;
        }
        return -1;

        // TC -> O(M)
    }

    int optimal(int n, int m)
    {
        int low = 1, high = m;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            long long ans = 1;
            for (int i = 0; i < n; i++)
            {
                ans *= mid;
                if (ans > m)
                    break;
            }
            if (ans == m)
                return mid;

            else if (ans > m)
                high = mid - 1;
            else
                low = mid - 1;
        }
        return -1;
        // TC -> O(log M);
    }
};

int main()
{
    Solution sol;
    int n = 3, m = 27;

    // Find nth root
    cout << "Nth Root: " << sol.optimal(n, m) << endl;

    return 0;
}