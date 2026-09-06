// N meeting in one room, given starting and ending time of a meeting in arrays
// maximum meeting do in one room also we can retrun which meetings occurs

#include <bits/stdc++.h>
using namespace std;

class Data
{
public:
    int start, end, position;
};

class Solution
{
private:
    static bool Comparator(Data val1, Data val2)
    {
        return val1.end < val2.end;
    }

public:
    vector<int> NmeetingRoom(vector<int> &start, vector<int> &end)
    {
        int n = start.size();

        vector<Data> arr(n);

        for (int i = 0; i < n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].position = i + 1;
        }

        sort(arr.begin(), arr.end(), Comparator);

        int freeTime = arr[0].end;

        vector<int> ds;
        ds.push_back(arr[0].position); // 1st meeting always held;

        for (int i = 1; i < n; i++)
        {
            if (arr[i].start >= freeTime)
            {
                ds.push_back(arr[i].position);
                freeTime = arr[i].end;
            }
        }

        return ds;

        // TC-> O(nlog n + n + n)
        //  SC->O(3N + N)
    }
};

int main()
{
    vector<int> start = {0, 2, 1, 5, 5, 8};
    vector<int> end = {5, 4, 2, 9, 7, 9};

    Solution sol;

    vector<int> ans = sol.NmeetingRoom(start, end);

    cout << "The number of meeting held is: " << ans.size() << endl;
    cout << "The positon of the meetings which occuriesd are: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}