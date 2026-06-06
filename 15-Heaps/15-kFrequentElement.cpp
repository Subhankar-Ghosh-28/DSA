// top k frequent element in an array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFreq(vector<int> &arr, int k)
    {

        // Count frequencies
        unordered_map<int, int> freq;
        for (int x : arr)
        {
            freq[x]++;
        }
        // Code here
        priority_queue<pair<int, int>> maxHeap;

        for (auto it : freq)
        {
            maxHeap.push({it.second, it.first});
        }

        vector<int> ans;

        for (int i = 0; i < k; i++)
        {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;

        // TC->O(n log n) maxheap
        // SC->O(n)
    }
};

int main()
{
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1};
    int k = 2;

    Solution sol;

    vector<int> ans = sol.topKFreq(arr, k);

    cout << "Top " << k << " element ";
    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}