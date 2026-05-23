// kth smallest = n-k+1 largest element;
//  same as previous

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int randomIndex(int &left, int &right)
    {

        int len = right - left + 1;

        return (rand() % len) + left;
    }

    int partitionAndReturnIndex(vector<int> &nums, int pivotIndex, int left, int right)
    {
        int pivot = nums[pivotIndex];

        swap(nums[left], nums[pivotIndex]);

        int ind = left + 1;

        for (int i = left + 1; i <= right; i++)
        {

            if (nums[i] < pivot)
            {
                swap(nums[ind], nums[i]);

                ind++;
            }
        }

        swap(nums[left], nums[ind - 1]);

        return ind - 1;
    }

public:
    int bruteForce(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        // Add the first K elements in the Min-heap
        for (int i = 0; i < k; i++)
            pq.push(nums[i]);

        for (int i = k; i < nums.size(); i++)
        {
            // Check if a new smallest element is found
            if (nums[i] < pq.top())
            {

                pq.pop(); // remove the largest from the min-heap

                // Add the current element to the min-heap
                pq.push(nums[i]);
            }
        }
        return pq.top();

        // TC->O(n log k);
        // SC->O(k);
    }

    int optimal(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return -1;

        int left = 0, right = nums.size() - 1;

        // Until the Kth smallest element is found
        while (true)
        {
            // Get the pivot index
            int pivotIndex = randomIndex(left, right);

            // Update the pivotIndex
            pivotIndex = partitionAndReturnIndex(nums, pivotIndex, left, right);

            if (pivotIndex == k - 1)
                return nums[pivotIndex];

            else if (pivotIndex > k - 1)
                right = pivotIndex - 1;
            else
                left = pivotIndex + 1;
        }

        return -1;

        /*
        Average TC = O(n)
        Worst TC = O(n²)
        SC = O(1)
        */
    }
};

int main()
{
    vector<int> nums = {-5, 4, 1, 2, -3};
    int k = 2;

    Solution sol;

    int ans = sol.optimal(nums, k);

    cout << "The Kth smallest element in the array is: " << ans << endl;

    return 0;
}