#include <bits/stdc++.h>
using namespace std;

// the given array is min heap or not
class Solution
{
public:
    bool isMinHeap(vector<int> &arr)
    {
        int n = arr.size();

        for (int i = 0; i <= n / 2 - 1; i++)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && arr[i] > arr[left])
                return false;
            if (right < n && arr[i] > arr[right])
                return false;
        }
        return true;

        // TC->O(n); Each comparison (at most two per node) is constant time.
        // SC->O(1);
    }
};

int main()
{
    vector<int> arr = {10, 20, 30, 21, 23};

    Solution sol;

    if (sol.isMinHeap(arr))
    {
        cout << "The array is min heap." << endl;
    }
    else
    {
        cout << "The array is not min heap." << endl;
    }
    return 0;
}