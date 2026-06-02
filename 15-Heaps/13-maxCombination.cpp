#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxCombinations(vector<int> &a, vector<int> &b, int k)
    {
        vector<int> allSums;

        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                allSums.push_back(a[i] + b[j]);
            }
        }

        sort(allSums.begin(), allSums.end(), greater<int>());

        vector<int> res(allSums.begin(), allSums.begin() + k);

        return res;

        // TC-> O(n*m + nmlog(nm));
        //  sc->O(n*m);
    }

    vector<int> optimal(vector<int> &a, vector<int> &b, int k)
    {
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<tuple<int, int, int>> maxHeap;

        set<pair<int, int>> visited;

        maxHeap.push({a[0] + b[0], 0, 0});
        visited.insert({0, 0});

        vector<int> result;

        // Extract top k elements from the heap
        while (k-- && !maxHeap.empty())
        {
            auto temp = maxHeap.top();

            int sum = get<0>(temp);
            int i = get<1>(temp);
            int j = get<2>(temp);

            maxHeap.pop();

            result.push_back(sum);

            if (i + 1 < a.size() && !visited.count({i + 1, j}))
            {
                maxHeap.push({a[i + 1] + b[j], i + 1, j});
                visited.insert({i + 1, j});
            }

            if (j + 1 < a.size() && !visited.count({i, j + 1}))
            {
                maxHeap.push({a[i] + b[j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return result;

        // TC-> O(klog(k));
        //  sc->O(k);
    }
};

int main()
{
    Solution obj;
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};
    int k = 2;
    vector<int> result = obj.optimal(nums1, nums2, k);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}