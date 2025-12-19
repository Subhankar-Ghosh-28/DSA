#include <bits/stdc++.h>
using namespace std;

int brute_sol(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k < j; k++)
            {
                sum += arr[k];
                maxi = max(sum, maxi);
            }
        }
    }
    return maxi;
}
int better_sol(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j];
            maxi = max(sum, maxi);
        }
    }
    return maxi;
}

int optimal_sol(vector<int> arr)
{
    int n = arr.size();
    long long int sum = 0;
    int maxi = LONG_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    if (maxi < 0)
        return 0;
    return maxi;
}
int main()
{
    int n;
    vector<int> arr;
    cout << "Enter the number of the element " << endl;
    cin >> n;
    cout << "Enter the element " << endl;
    for (int i = 0; i < n; i++)
    {
        int element;
        cin >> element;
        arr.push_back(element);
    }
    cout << optimal_sol(arr);
    return 0;
}