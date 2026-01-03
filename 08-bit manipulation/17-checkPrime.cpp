#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bruteForce(int num)
    {
        int cnt = 0;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
                cnt++;
        }
        if (cnt == 2)
            return true;
        return false;
    }

    bool optimal(int num)
    {
        int cnt = 0;
        for (int i = 1; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                cnt++;
                if (num / i != i)
                    cnt++;
            }
        }
        return (cnt==2)? true: false;
    }
};

int main()
{
    Solution sol;
    cout << sol.bruteForce(1);
    return 0;
}