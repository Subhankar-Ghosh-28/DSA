#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteforce(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = ans ^ i;
        }
        return ans;
    }

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
};

int main()
{
    Solution sol;
    cout << sol.xorFromZeroToN(5);
    return 0;
}