#include <bits/stdc++.h>
using namespace std;

int prefixMax(int *arr, int n, int x)
{

    int prefix[n];

    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    return prefix[x];
}

int suffixMax(int *arr, int n, int x)
{

    int suffix[n];

    suffix[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    return suffix[x];
}

int bruteForce(int *arr, int n)
{

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int leftMax = prefixMax(arr, n, i);
        int rightMax = suffixMax(arr, n, i);

        if (arr[i] < leftMax && arr[i] < rightMax)
        {
            total += min(leftMax, rightMax) - arr[i];
        }
    }
    return total;
}

int ooptimal(int *arr, int n)
{
    int lMax = 0;
    int rMax = 0;
    int total = 0;
    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (arr[l] <= arr[r])
        {
            if (lMax > arr[l])
            {
                total += lMax - arr[l];
            }

            else
            {
                lMax = arr[l];
            }
            l++;
        }

        else
        {
            if (rMax > arr[r])
            {
                total += rMax - arr[r];
            }
            else
            {
                rMax = arr[r];
            }
            r--;
        }
    }
    return total;
}

int main()
{
    int arr[] = {8, 1, 8 ,2 ,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "total rain water : " << ooptimal(arr, n) << endl;
    return 0;
}