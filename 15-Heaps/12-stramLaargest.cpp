#include <bits/stdc++.h>
using namespace std;

// kth largest element of a stream we add data into vector and return;

class Solution
{

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

public:
    Solution(int k, vector<int> &nums)
    {
        size = k;

        for (int it : nums)
        {
            minHeap.push(it);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }
    }

    int add(int x)
    {
        minHeap.push(x);

        if (minHeap.size() > size)
            minHeap.pop();

        return minHeap.top();

        // TC-> O(log k);
        // SC-> O(k);
    }
};

int main()
{

    vector<int> nums = {4, 5, 8, 2};
    Solution kthLargest(3, nums);

    cout << kthLargest.add(3) << endl;
    cout << kthLargest.add(5) << endl;
    cout << kthLargest.add(10) << endl;
    cout << kthLargest.add(9) << endl;
    cout << kthLargest.add(4) << endl;

    return 0;
}