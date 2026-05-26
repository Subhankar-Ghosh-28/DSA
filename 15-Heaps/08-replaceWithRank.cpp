#include <bits/stdc++.h>
using namespace std;

// replace the array element with his rank;

class Solution
{
public:
    vector<int> brute_force(vector<int> &arr)
    {
        vector<int> result;

        for (int i = 0; i < arr.size(); i++)
        {
            unordered_set<int> smaller;

            for (int j = 0; j < arr.size(); j++)
            {
                if (arr[j] < arr[i])
                {
                    smaller.insert(arr[j]);
                }
            }
            int rank = smaller.size() + 1;

            result.push_back(rank);
        }
        return result;
    }

    vector<int> optimal(vector<int> &arr)
    {
        vector<int> ans, temp;
        int N = arr.size();

        temp = arr;
        sort(temp.begin(), temp.end());

        map<int, int> mpp;
        int rank = 1;

        for (int i = 0; i < N; i++)
        {
            if (mpp.find(temp[i]) == mpp.end())
            {
                mpp[temp[i]] = rank++;
            }
        }

        for (int i = 0; i < N; i++)
        {
            ans.push_back(mpp[arr[i]]);
        }
        return ans;

        // TC-> O(n log n);
        // SC-> O(n);
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {2, 2, 1, 6};

    vector<int> res = obj.optimal(arr);

    for (int x : res)
    {
        cout << x << " ";
    }

    return 0;
}