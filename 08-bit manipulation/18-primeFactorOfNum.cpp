#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPrine(int num)
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
        return (cnt == 2) ? true : false;
    }

    vector<int> bruteForce(int num)
    {
        vector<int> ans;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                if (checkPrine(i))
                    ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int> better(int num)
    {
        vector<int> ans;
        for (int i = 1; i*i <= num; i++)
        {
            if (num % i == 0)
            {
                if (checkPrine(i))
                    ans.push_back(i);
            }
        }
        return ans;
    }

    vector<int>optimal(int num){
        vector<int> ans;

        // Check for factor 2
        if (num % 2 == 0) {
            ans.push_back(2);
            while (num % 2 == 0)
                num /= 2;
        }

        // Check odd factors
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                ans.push_back(i);
                while (num % i == 0)
                    num /= i;
            }
        }

        // Remaining prime factor
        if (num > 1)
            ans.push_back(num);

        return ans;
    }
};
int main()
{
    Solution sol;
    for (auto it : sol.optimal(36))
    {
        cout << it << " ";
    }
    cout << "\n";
    return 0;
}