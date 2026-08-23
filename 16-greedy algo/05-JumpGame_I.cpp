// is it possible to go last element

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int jumpGame(vector<int> &arr)
    {
        int maxIndex = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            if (maxIndex < i)
            {
                return false;
            }

            maxIndex = max(maxIndex, i + arr[i]);

            if (maxIndex > arr.size())
                break;
        }
        return true;
        // TC-> O(n), SC-> O(1)
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 1, 1, 0, 2, 5};

    Solution sol;

    sol.jumpGame(arr) ? cout << "The jump is possible." : cout << "The is not possible to the last element." << endl;
}