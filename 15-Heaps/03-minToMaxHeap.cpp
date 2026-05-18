// convert min heap to max heap

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void heapify(vector<int> &arr, int n, int i)
    {

        int largest = i;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);

            heapify(arr, n, largest);
        }
    }

public:
    vector<int> bruteForce(vector<int> &nums)
    {
        // if just return any maxheap then

        int n = nums.size();

        int r = n - 1, l = 0;

        while (l <= r)
        {
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        return nums;

        // TC->O(n/2);
        // SC->O(1);
    }

    int optimal(vector<int> &nums)
    {
        // using heapify function;

        int n = nums.size();
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heapify(nums, n, i);
        }
        //  Heapify():	O(logN) + o(n/2);
    }
};

int main()
{
    Solution sol;

    // Test case 1: Brute Force approach
    vector<int> minHeap1 = {1, 2, 3, 4, 5};
    cout << "Original Min Heap: ";
    for (int x : minHeap1)
        cout << x << " ";
    cout << "\n";

    vector<int> result1 = sol.bruteForce(minHeap1);
    cout << "After Brute Force (reverse): ";
    for (int x : result1)
        cout << x << " ";
    cout << "\n\n";

    // Test case 2: Optimal approach
    vector<int> minHeap2 = {1, 2, 3, 4, 5};
    cout << "Original Min Heap: ";
    for (int x : minHeap2)
        cout << x << " ";
    cout << "\n";

    sol.optimal(minHeap2);
    cout << "After Optimal (heapify): ";
    for (int x : minHeap2)
        cout << x << " ";
    cout << "\n";

    return 0;
}