#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int assignCookies(vector<int> &greed, vector<int> &cookies)
    {
        int n = greed.size();
        int m = cookies.size();

        int l = 0, r = 0;

        sort(greed.begin(), greed.end());
        sort(cookies.begin(), cookies.end());

        while (l < m && r < n)
        {
            if (greed[r] <= cookies[l])
            {
                r++;
            }
            l++;
        }
        return r;

        // TC-> O(n*logn + m*logm);
        // SC-> O(1);
    }
};

int main()
{

    vector<int> student = {1, 2, 3};
    vector<int> cookie = {1, 1};

    Solution solver;

    // Get the number of content students and print it
    int result = solver.assignCookies(student, cookie);
    cout << "Maximum number of content students: " << result << endl;

    return 0;
}