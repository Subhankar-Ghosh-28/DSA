// Print all the Unique Subsets
// Given an array nums, which can have duplicate entries, provide the power set.
// Duplicate subsets cannot exist in the solution set. Return the answer in any sequence

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper1(int index, vector<int> curr, set<vector<int>> &result, vector<int> &nums)
    {
        if (index == nums.size())
        {
            result.insert(curr);
            return;
        }
        // take
        curr.push_back(nums[index]);
        helper1(index + 1, curr, result, nums);
        // not take
        curr.pop_back();
        helper1(index + 1, curr, result, nums);
    }

    void optimalHelper(int index, vector<int> &current, vector<vector<int>> &result, vector<int> &nums)
    {
        result.push_back(current);

        for (int i = index; i < nums.size(); i++)
        { // Skip duplicates to avoid repeating combinations
            if (i > index && nums[i] == nums[i - 1])
                continue;
            // If the current element is greater than the remaining target, break the loop

            current.push_back(nums[i]);

            optimalHelper(i + 1, current, result, nums);
            current.pop_back();
        }
    }

public:
    set<vector<int>> bitMasking(vector<int> &masks)
    {
        int n = masks.size();
        set<vector<int>> ans;
        int subsets = 1 << n;

        for (int mask = 0; mask < subsets; mask++)
        {

            vector<int> list;
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                    list.push_back(masks[i]);
            }
            ans.insert(list);
        }
        return ans;

        // tc =  Outer × Inner × Insert
        //    = 2^n × n × n = O(n^2* 2^n)
    }

    set<vector<int>> recursive1(vector<int> &nums)
    {
        set<vector<int>> result;
        vector<int> curr;
        helper1(0, curr, result, nums);
        return result;

        // tc ->O(2^n log(2^n))
    }

    vector<vector<int>> optimalRecursive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> current;
        optimalHelper(0, current, result, nums);
        return result;

        /* Time Complexity: O(2^N),In the worst case (all unique elements), we generate all possible subsets, which is 2^N.
            Sorting takes O(N log N), so total complexity is O(2^N + N log N) ≈ O(2^N).

            Space Complexity: O(N) ,Due to recursion depth and storage of the current subset in the call stack.
            The output storage is O(2^N) for all subsets.
        */
    }
};

int main()
{
    vector<int> arr = {1, 2, 2};
    Solution sol;
    set<vector<int>> result = sol.bitMasking(arr);
    cout << "RESULT:" << endl
         << "[" << endl;
    for (auto subset : result)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << endl;

    result = sol.recursive1(arr);

    cout << "RESULT:" << endl
         << "[" << endl;
    for (auto subset : result)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << endl;

    vector<vector<int>> result1 = sol.optimalRecursive(arr);

    cout << "RESULT:" << endl
         << "[" << endl;
    for (auto subset : result1)
    {
        cout << "[ ";
        for (auto num : subset)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    cout << "]" << endl;
    cout << endl;
    return 0;
}