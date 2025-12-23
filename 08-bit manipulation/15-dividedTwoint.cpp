// without using '/' '%'

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(int dividend, int divisor)
    {

        int sum = 0;
        int cnt = 0;
        while (sum + divisor <= dividend)
        {
            cnt++;
            sum += divisor;
        }
        return cnt;
    }

    int optimal(int dividend, int divisor)
    {
        if (dividend == divisor)
            return 1;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (divisor == 1)
            return dividend;

        bool sign = !((dividend < 0) ^ (divisor < 0));

        /*
                bool sign = true; // true == posititve
                if ((dividend < 0 && divisor > 0) || (dividend >= 0 && divisor < 0))
                    sign = false; // false == negative;
        */
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);
        long long ans = 0;

        while (n >= d)
        {
            int cnt = 0;
            while (n >= (d << (cnt + 1)))
            {
                cnt++;
            }

            ans = ans + (1 << cnt);

            n = n - (d << cnt);
        }
        if (ans > INT_MAX && sign)
            return INT_MAX;
        if (ans > INT_MAX && !sign)
            return INT_MIN;

        /* Returning the quotient
        with proper sign */
        return sign ? ans : -1 * ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.bruteForce(21, 3) << endl;
    cout << sol.optimal(21, 3);
    return 0;
}