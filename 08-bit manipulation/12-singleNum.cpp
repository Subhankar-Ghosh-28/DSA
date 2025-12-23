#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class SingleNum1
    {
        // there all numbers are in pair,only one number in 1 time
    public:
        int bruteForce(vector<int> &arr)
        {
            int n = arr.size();
            map<int, int> mpp;
            for (int i = 0; i < n; i++)
            {
                mpp[arr[i]]++;
            }

            for (auto it : mpp)
            {
                if (it.second == 1)
                    return it.first;
            }
            return -1;
        }

        int optimal(vector<int> &arr)
        {
            int n = arr.size();
            int Xor = 1;
            for (int i = 0; i < n; i++)
            {
                Xor = Xor ^ arr[i];
            }
            return Xor;
        }
    };

    class SingleNum2
    {
        // numbers repeats 3 times only one number at 1 time;
    public:
        int bruteforce(vector<int> &arr)
        {
            int n = arr.size();
            map<int, int> mpp;
            for (int i = 0; i < n; i++)
            {
                mpp[arr[i]]++;
            }

            for (auto it : mpp)
            {
                if (it.second == 1)
                    return it.first;
            }
            return -1;
        }

        int better(vector<int> &arr)
        {
            int n = arr.size();
            int ans = 0;

            for (int num = 0; num < 31; num++)
            {
                int cnt = 0;
                for (int i = 0; i < n; i++)
                {
                    if (arr[i] & (1 << num))
                    {
                        cnt++;
                    }
                }
                ans = (cnt % 3) ? (ans | (1 << num)) : ans;
            }
            return ans;
        }

        int optimal(vector<int> &arr)
        {
            int n = arr.size();

            sort(arr.begin(), arr.end());

            for (int i = 1; i < n; i += 3)
            {
                if (arr[i] != arr[i - 1])
                    return arr[i - 1];
            }
            return arr[n - 1];
        }

        int bestOptimal(vector<int> &arr)
        {
            int n = arr.size();
            int one = 0;
            int two = 0;

            for (int i = 0; i < n; i++)
            {
                one = (one ^ arr[i]) & ~two;
                two = (two ^ arr[i]) & ~one;
            }
            return one;
        }
    };

    SingleNum1 singleNum1;
    SingleNum2 singleNum2;

    class SingleNum3
    {

        // there is two indivisual distrint number

    public:
        vector<int> bruteForce(vector<int> &arr)
        {
            int n = arr.size();
            map<int, int> mpp;
            for (int i : arr)
            {
                mpp[i]++;
            }

            vector<int> ans;
            for (auto it : mpp)
            {
                if (it.second == 1)
                    ans.push_back(it.first);
            }
            return ans;
        }

        vector<int> optimal(vector<int> &arr)
        {
            int n = arr.size();

            long xorr = 0;

            for (int i = 0; i < n; i++)
            {
                xorr ^= arr[i];
            }
            int rightMost = (xorr & (xorr - 1)) ^ xorr;
            int b1 = 0;
            int b2 = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] & rightMost)
                {
                    b1 = b1 ^ arr[i];
                }

                else
                    b2 = b2 ^ arr[i];
            }
            return {b1, b2};
        }
    };
};

int main()
{
    vector<int> arr = {1, 6, 2, 2, 3, 3};

    Solution sol;
    int x = sol.singleNum1.bruteForce(arr);
    cout << x << endl;

    Solution::SingleNum2 obj2;
    cout << obj2.bestOptimal(arr) << endl;

    Solution::SingleNum3 obj3;
     vector<int>y = obj3.bruteForce(arr);

     for(auto it : y){
        cout<<it<<" ";
     }

    return 0;
}