#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(int n)
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i * i <= n)
                ans = i;
        }
        return ans;
        // TC -> O(N);
    }

    int optimal(int n)
    {
        int low = 1, high = n / 2, ans = 0;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (mid * mid <= n)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;

        // TC -> O(log N)
    }
};

int main()
{
    int n;
    cout << "Enter A number: ";
    cin >> n;
    Solution sol;
    cout << "Square root of " << n << " is: " << sol.optimal(n);
    return 0;
}