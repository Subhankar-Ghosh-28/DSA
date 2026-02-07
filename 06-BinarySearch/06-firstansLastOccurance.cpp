// find the index of the first and last occurrence of the target key

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int lowerBound(vector<int> &nums, int x)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1, first = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == x)
            {
                first = mid;
                high = mid - 1;
            }
            else if (nums[mid] > x)
            {
                high = mid - 1;
            }

            else
                low = mid + 1;
        }
        return first;
    }

    int upperBound(vector<int> &nums, int x)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1, last = -1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == x)
            {
                last = mid;
                low = mid + 1;
            }
            else if (nums[mid] > x)
            {
                high = mid - 1;
            }

            else
                low = mid + 1;
        }
        return last;
    }

public:
    vector<int> bruteForce(vector<int> &nums, int k)
    {
        int first = -1, last = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == k)
            {
                if (first == -1)
                    first = i;
                last = i;
            }
        }
        return {first, last};
    }

    vector<int> optimal(vector<int> &nums, int k)
    {
        int first = lowerBound(nums, k);
        if (first == -1)
            return {-1, -1};

        int last = upperBound(nums, k);
        return {first, last};
    }
};

int main()
{
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};
    int k = 13;
    Solution sol;
    for (auto it : sol.optimal(v, k))
    {
        cout << it << " ";
    }
    return 0;
}