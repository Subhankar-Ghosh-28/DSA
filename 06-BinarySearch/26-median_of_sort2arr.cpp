// median of 2 sorted arr

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> merge(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> temp;
        int left = 0;
        int right = 0;
        while (left < arr1.size() && right < arr2.size())
        {
            if (arr1[left] <= arr2[right])
            {
                temp.push_back(arr1[left]);
                left++;
            }
            else
            {
                temp.push_back(arr2[right]);
                right++;
            }
        }
        while (left < arr1.size())
        {
            temp.push_back(arr1[left]);
            left++;
        }
        while (right < arr2.size())
        {
            temp.push_back(arr2[right]);
            right++;
        }

        return temp;
    }

public:
    int bruteForce(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> temp = merge(nums1, nums2);
    }

    int better(vector<int> &nums)
    {
    }

    int optimal(vector<int> &nums)
    {
    }
};

int main()
{

    return 0;
}