// Given a interval we insert it into his proper place

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert_Interval(int intervals[][2], int n, int newInterval[2])
{

    vector<vector<int>> result;

    int i = 0;

    // left
    while (i < n && intervals[i][1] < newInterval[0])
    {
        result.push_back({intervals[i][0], intervals[i][1]});
        i++;
    }

    // overlapping

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);

        i++;
    }
    result.push_back({newInterval[0], newInterval[1]});

    // right part

    while (i < n)
    {
        result.push_back({intervals[i][0], intervals[i][1]});
        i++;
    }
    return result;

    //TC-> O(N);
    //SC-> O(N);
}

int main()
{

    int intervals[][2] = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    cout << "Intervals Array: ";
    for (auto interval : intervals)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    cout << endl;

    int n = sizeof(intervals) / sizeof(intervals[0]);

    int newInterval[2] = {5, 8};
    cout << "New Interval to be Inserted: ";
    cout << "[" << newInterval[0] << ", " << newInterval[1] << "]" << endl;

    vector<vector<int>> result = insert_Interval(intervals, n, newInterval);
    for (auto interval : result)
    {
        cout << "[" << interval[0] << ", " << interval[1] << "], ";
    }
    cout << endl;

    return 0;
}