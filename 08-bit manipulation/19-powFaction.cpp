#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double bruteForce(double x, int n)
    {
        double ans = 1.0;
        for (int i = 1; i <= abs(n); i++)
        {
            ans = ans * x;
        }
        return (n < 0) ? (1.0 / ans) : ans;
    }

    double optimal(double x, int n)
    {
        double ans = 1.0;
        int power = n;

        if (power < 0)
            power = -power;

        while (power > 0)
        {
            if (power % 2 == 1)
            {
                ans = ans * x;
                power--;
            }
            else
            {
                power /= 2;
                x = x * x;
            }
        }
        return (n < 0) ? (1.0 / ans) : ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.bruteForce(2, -3) << endl;
    cout << sol.optimal(2, -3);
    return 0;
}