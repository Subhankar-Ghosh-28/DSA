// job sequence problem
// every job have a id and deadline and profit

#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int deadline;
    int profit;
};

class Solution
{
protected:
    static bool Comparator(const Job &j1, const Job &j2)
    {
        return j1.profit > j2.profit;
    }

public:
    pair<int, int> JobScheduling(vector<Job> arr)
    {
        sort(arr.begin(), arr.end(), Comparator);

        int maxDeadline = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            maxDeadline = max(maxDeadline, arr[i].deadline);
        }

        vector<int> hash(maxDeadline + 1, -1);

        int cnt = 0, totalProfit = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = arr[i].deadline - 1; j >= 0; j--)
            {
                if (hash[j] == -1)
                {
                    cnt++;
                    totalProfit += arr[i].profit;
                    hash[j] = arr[i].id;
                    break;
                }
            }
        }

        return {totalProfit, cnt};
    }
    // TC->  O(N log N) + O(N * M), O(N log N)
    // SC-> O(m) m = max deadline
};

int main()
{

    vector<Job> arr = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    Solution ob;
    pair<int, int> ans = ob.JobScheduling(arr);

    cout << ans.first << " " << ans.second << endl;

    return 0;
}