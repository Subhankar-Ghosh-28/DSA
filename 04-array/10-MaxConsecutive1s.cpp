#include <bits/stdc++.h>
using namespace std;

int consecutiveOnes(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        maxLen = max(maxLen, cnt);
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 3, 1, 1, 1, 1, 0, 0, 1, 1, 0};
    cout << "Maximum Consecutive 1s: " << consecutiveOnes(arr);
    return 0;
}