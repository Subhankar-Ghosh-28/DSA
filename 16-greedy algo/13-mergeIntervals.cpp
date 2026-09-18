// merge the overlapping intervals

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> bruteForce(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        int n = intervals.size();

        for (int i = 0; i < n;)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i + 1;

            while (j < n && intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
                j++;
            }

            ans.push_back({start, end});
            i = j;
        }
        return ans;

        // TC -> O(n*n)
        // SC -> O(N), additonal space used to store the non-overlapping intervals.
    }

    vector<vector<int>> optimal(vector<vector<int>> &intervals)
    {
        vector<vector<int>> mergeInterval;

        int n = intervals.size();

        if (n == 0)
            return mergeInterval;

        sort(intervals.begin(), intervals.end());

        vector<int> temp = intervals[0];

        for (auto it : intervals)
        {
            if (it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }

            else
            {
                mergeInterval.push_back(temp);

                temp = it;
            }
        }

        mergeInterval.push_back(temp);

        return mergeInterval;

        // TC-> O(n log n) + O(N);
        // SC-> O(n);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.optimal(intervals);

    cout << "Output: ";
    for (auto interval : result)
    {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}