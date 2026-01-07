#include <bits/stdc++.h>
using namespace std;

// number of substring of a given string of all 3 char

class Solution
{
public:
    int bruteForce(string s, int k)
    {
        int cnt = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            int hash[256] = {0};

            for (int j = i; j < n; j++)
            {
                hash[s[j] - 'a'] = 1;

                int hashSum = 0;
                for (int i = 0; i < 256; i++)
                {
                    hashSum += hash[i];
                }

                if (hashSum == k)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    int optimal(string s, int k)
    {
        int n = s.size(), cnt = 0;
        int lastSeen[3] = {-1, -1, -1};
        for (int i = 0; i < n; i++)
        {
            lastSeen[s[i] - 'a'] = i;

            cnt = cnt + (1 + *min_element(lastSeen, lastSeen + 3)); // = min(lastSeen[0],min(lastSeen[1],lastSeen[2]))
        }
        return cnt;
    }
};

int main()
{
    string s = "bbacba";
    int k = 3;
    Solution sol;
    cout << sol.bruteForce(s, k) << endl;
    cout << sol.optimal(s, k) << endl;
    return 0;
}