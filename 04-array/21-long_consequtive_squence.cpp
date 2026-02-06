#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool linearSearch(vector<int> &a, int target)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[i] == target)
                return true;
        }
        return false;
    }

public:
    int bruteForce(vector<int> &arr)
    {
        int n = arr.size();
        int longest = 1;

        for (int i = 0; i < n; i++)
        {

            int x = arr[i];
            int count = 1;
            while (linearSearch(arr, x + 1) == true)
            {
                x++;
                count++;
            }
            longest = max(count, longest);
        }
        return longest;

        // TC -> O(N^2),,, SC -> O(1);
    }

    int better(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int longest = 1, count = 1, lastSmaller = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - 1 == lastSmaller)
            {
                count++;
                lastSmaller = arr[i];
            }
            else if (arr[i] != lastSmaller)
            {
                count = 1;
                lastSmaller = arr[i];
            }
            longest = max(count, longest);
        }
        return longest;

        // TC -> O(Nlog N),,, SC -> O(1);
    }

    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
        }
        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x++;
                    count++;
                }
                longest = max(longest, count);
            }
        }
        return longest;

        // TC -> O(N),,, SC -> O(N);
    }
};

int main()
{
    vector<int> a = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    Solution sol;
    cout << sol.optimal(a);

    return 0;
}