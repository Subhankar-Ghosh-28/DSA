#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> mpp;

        for (auto it : tasks)
        {
            mpp[it]++;
        }

        priority_queue<int> maxHeap;

        for (auto &entry : mpp)
        {
            maxHeap.push(entry.second);
        }

        int time = 0;

        while (!maxHeap.empty())
        {
            vector<int> temp;

            int cycle = n + 1;

            int i = 0;

            while (i < cycle && !maxHeap.empty())
            {
                int cnt = maxHeap.top();
                maxHeap.pop();

                cnt--;

                if (cnt > 0)
                    temp.push_back(cnt);

                time++, i++;
            }

            for (auto it : temp)
                maxHeap.push(it);

            if (maxHeap.empty())
                break;

            time += cycle - i;
        }

        return time;

        // TC->O(nlog k) count frequencies in O(N) and use a max heap of K unique tasks.
        // Each task can be pushed and popped from the heap multiple times resulting (log K) per operation.

        // sc-> O(k); K is the number of unique tasks.
    }
};

int main()
{
    Solution obj;

    // Input task list
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};

    // Cooldown period
    int n = 2;

    // Output the least interval required to finish all tasks
    cout << obj.leastInterval(tasks, n) << endl;

    return 0;
}