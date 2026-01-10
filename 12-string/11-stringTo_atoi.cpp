// similer of atoi() fuction

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1;
        long res = 0;

        while (i < s.size() && s[i] == ' ')
            i++;
        if (s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (s[i] == '+')
        {
            sign = 1;
            i++;
        }
        if (i == s.size())
            return 0;

        while (i < s.size() && isdigit(s[i]))
        {
            res = res * 10 + (s[i] - '0');
            if (sign * res > INT_MAX)
                return INT_MAX;
            if (sign * res < INT_MIN)
                return INT_MIN;

            i++;
        }
        return (int)(sign * res);
    }
};

int main()
{
    Solution sol;

    string input = "   -42";

    int result = sol.myAtoi(input);
    cout << "Converted integer: " << result << endl;

    return 0;
}