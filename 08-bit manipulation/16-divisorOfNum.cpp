#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> bruteForce(int num)
    {
        vector<int> ans;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
                ans.push_back(i);
        }
        return ans;
    }
    vector<int> optimal(int n)
    {
        vector<int> ans;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ans.push_back(i);
                if (n / i != i)
                {
                    ans.push_back(n / i);
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    for (auto it : sol.bruteForce(36))
    {
        cout << it << " ";
    }
    cout << "\n";
    for (auto it : sol.optimal(36))
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}