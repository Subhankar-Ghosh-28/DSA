#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bruteForce(vector<int> arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k < j; k++)
                {
                    sum += arr[k];
                    maxi = max(sum, maxi);
                }
            }
        }
        return maxi;
    }
    int better(vector<int> arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += arr[j];
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }

    int optimal(vector<int> arr)
    {
        int n = arr.size();
        long long int sum = 0;
        int maxi = LONG_MIN;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > maxi)
            {
                maxi = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
        /*
        int currSum = arr[0];
        int maxSum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            currSum = max(arr[i], currSum + arr[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
        */
    }

    // print the subarray

    vector<int> printSubarr(vector<int> arr)
    {
        int n = arr.size();
        long long maxi = LLONG_MIN, sum = 0;
        int start = 0, ansStart = -1, ansEnd = -1;

        for (int i = 0; i < n; i++)
        {
            if (sum == 0)
            {
                start = i;
            }
            sum += arr[i];
            if (sum > maxi)
            {
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }
        vector<int> ans;
        for (int i = ansStart; i <= ansEnd; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> arr = {-2, 1, -3, -1};

    Solution sol;

    int maxSum = sol.optimal(arr);

    cout << "The maximum subarray sum is: " << maxSum << endl;

    vector<int> subarr = sol.printSubarr(arr);

    for (auto element : subarr)
    {
        cout << element << " ";
    }
    return 0;
}