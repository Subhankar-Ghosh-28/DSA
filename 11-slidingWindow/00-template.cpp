/*
there is 4 type question in sliding window

    1. constand window
    2.longest substring/subarray where <condition>
    3.no. of subarray where <condtion>
    4. minimum window where <condition>

*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class pattern1
    {
    public:
        // max sum of a subarray with k element
        int bruteForce(vector<int> &arr, int k)
        {
            int n = arr.size();
            int maxSum = INT_MIN;

            for (int i = 0; i <= n - k; i++)
            {
                int sum = 0;

                for (int j = i; j < i + k; j++)
                {
                    sum += arr[j];
                }

                maxSum = max(maxSum, sum);
            }

            return maxSum;
        }

        int optimal(vector<int> &arr, int k)
        {
            int l = 0, r = k - 1, maxSum = INT_MIN, sum = 0, n = arr.size();

            for (int i = l; i <= r; i++)
            {
                sum = sum + arr[i];
            }

            while (r < n - 1)
            {
                sum -= arr[l];
                l++;
                r++;
                sum += arr[r];
                maxSum = max(maxSum, sum);
            }
            return maxSum;
        }
    };
    pattern1 pattern1;

    class pattern2
    {
    public:
        // longest or len subarray / substring where <condtion>
        int bruteForce(vector<int> &arr, int k)
        {
            int n = arr.size();
            int maxlen = 0;

            for (int i = 0; i < n; i++)
            {
                int sum = 0;
                for (int j = i; j < n; j++)
                {
                    sum += arr[j];
                    if (sum <= k)
                    {
                        maxlen = max(maxlen, j - i + 1);
                    }

                    else
                        break;
                }
            }
            return maxlen;
        }

        int better(vector<int> &arr, int k)
        {
            int l = 0, r = 0, n = arr.size(), len = 0, sum = 0;
            while (r < n)
            {
                sum = sum + arr[r];
                while (sum > k)
                {
                    sum = sum - arr[l];
                    l++;
                }
                if (sum <= k)
                {
                    len = max(len, r - l + 1);
                }
                r++;
            }
            return len; // tc = o(n+n)
        }

        int optimal(vector<int> &arr, int k)
        {
            int l = 0, r = 0, maxlen = 0, n = arr.size(), sum = 0;

            while (r < n)
            {
                sum += arr[r];
                while (sum > k)
                {
                    sum -= arr[l];
                    l++;
                }
                if (sum <= k)
                {
                    maxlen = max(maxlen, r - l + 1);
                }
                r++;
            }
            return maxlen;
        }

        /*
        pattern 3 is use of pattern 2 like
         no of subarray where sum <= k = x
         no of subarray where sum <= k-1 = y
         and final ans = x-y
        */
        // pattern4 is an another mathode just
    };
};

int main()
{
    vector<int> arr = {2, 5, 1, 7, 10};
    int k = 14;
    Solution::pattern2 sol;
    cout << sol.bruteForce(arr, k);
    return 0;
}