#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class OnlyPositive
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;

                for (int l = i; l <= j; l++)
                {
                    sum += nums[l];
                }
                if (sum == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;

        // TC -> O(N^3)  SC->O(1)
    }

    int better(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += nums[j];
                if (sum == k)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        return maxLen;
        // TC -> O(N^2)  SC->O(1)
    }
    int optimal(vector<int> &nums, int k)
    {
        // Write your code here
        int left = 0, right = 0;
        long long sum = nums[0];
        int maxlength = 0;
        int n = nums.size();
        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= nums[left];
                left++;
            }
            if (sum == k)
            {
                maxlength = max(maxlength, right - left + 1);
            }
            right++;
            if (right < n)
                sum += nums[right];
        }
        return maxlength;
        // TC -> O(N + N)  SC->O(1)
    }
};
// brute sol for both +ve and -ve;

class BothPosNeg
{
public:
    int bruteForce(vector<int> &nums, int k)
    {
        OnlyPositive sol;
        return sol.bruteForce(nums, k);
    }
    int better(vector<int> &nums, int k)
    {
        OnlyPositive sol;
        return sol.better(nums, k);
    }
    int optimal(vector<int> &nums, int k)
    {
        int n = nums.size(); 
        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
           
            sum += nums[i];

            
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;

            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
        // TC -> O(N)  SC->O(N)
    }
};

int main()
{
    vector<int> a = {2, 3, 5, 1, 9};
    int k = 10;
    BothPosNeg sol;
    int len = sol.optimal(a, k);
    cout << "The length of the longest subarray is: " << len << "\n";

    return 0;
}