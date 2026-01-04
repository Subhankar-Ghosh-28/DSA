#include <bits/stdc++.h>
using namespace std;

// you pick the card from any two side not from middle

int solution(vector<int> &arr, int k)
{
    int lsum = 0, rsum = 0, n = arr.size(), maxSum = 0;
    if (k > arr.size())
        return 0;
    for (int i = 0; i < k; i++)
    {
        lsum += arr[i];
    }
    maxSum = lsum;
    int rindx = n - 1;
    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= arr[i];
        rsum += arr[rindx];
        rindx--;
        maxSum = max(maxSum, lsum + rsum);
    }
    return maxSum;
}

int main()
{
    vector<int> arr = {2, 5, 1, 7, 10};
    int k = 3;
    cout << solution(arr, k);
    return 0;
}