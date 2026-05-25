#include <bits/stdc++.h>
using namespace std;

// sort k sorted array

class Solution
{
public:
    vector<int> sortNearlySortedArray(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        return arr;

        // TC->O(n log n);
        // sc-> O(1);
    }

    vector<int> usingHeap(vector<int> &arr, int k)
    {

        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i <= k && i < arr.size(); i++)
        {
            minHeap.push(arr[i]);
        }

        for (int i = k + 1; i < arr.size(); i++)
        {
            result.push_back(minHeap.top());
            minHeap.pop();

            minHeap.push(arr[i]);
        }

        while (!minHeap.empty())
        {
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;

        // TC->O(n log k); nsert n elements into a min heap of size k + 1, insertion/removal from heap costs O(log k).
        // sc-> O(k) for min heap;
    }
};

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};

    int k = 3;

    Solution obj;

    vector<int> result = obj.usingHeap(arr, k);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}