#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - 1];

        // O(nlog n);
    }

    int optimal(vector<int> &nums)
    {
        int maxi = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            maxi = max(maxi, nums[i]);
        }
        return maxi;

        //O(n);
    }
};

int main()
{
    Solution sol;

    vector<int> arr;

    int n;

    cout << "Enter the size: " << endl;
    cin >> n;

    cout << "Enter the element: ";

    for (int i = 0, element; i < n; i++)
    {
        cin >> element;
        arr.push_back(element);
    }

    cout << "Largest element: " << sol.optimal(arr);
    return 0;
}