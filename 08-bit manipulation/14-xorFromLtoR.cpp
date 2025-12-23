
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorFromZeroToN(int n)
    {
        if (n % 4 == 1)
            return 1;
        else if (n % 4 == 2)
            return n + 1;
        else if (n % 4 == 3)
            return 0;
        else if (n % 4 == 0)
            return n;
    }

    int bruteForce(int l, int r)
    {
        int ans = 0;
        for (int i = l; i <= r; i++)
        {
            ans = ans ^ i;
        }
        return ans;
    }

    int optimal(int l, int r)
    {
        return xorFromZeroToN(l - 1) ^ xorFromZeroToN(r);
    }
};

int main()
{
    Solution sol;
    cout << sol.optimal(3, 7);
    return 0;
}