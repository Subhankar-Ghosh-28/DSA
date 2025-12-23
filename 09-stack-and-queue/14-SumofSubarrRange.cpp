#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int largest = arr[i], smallest = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum += (largest - smallest);
        }
    }
    return sum;
}

vector<int> FindNSE(vector<int> arr, int n)
{
    vector<int> nse(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> FindPSEE(vector<int> arr, int n)
{
    vector<int> psee(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        psee[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return psee;
}

vector<int> FindNGE(vector<int> arr, int n)
{
    vector<int> nge(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nge;
}

vector<int> FindPGE(vector<int> arr, int n)
{
    vector<int> pge(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pge;
}

int sumOfSubarrMin(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse = FindNSE(arr, n);
    vector<int> psee = FindPSEE(arr, n);

    int total = 0;
    int mod = (int)(1e9 + 7);

    for (int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1ll;

        int val = (freq * arr[i] * 1ll) % mod;

        total = (total + val) % mod;
    }
    return total;
}

int sumOfSubarrMax(vector<int> arr)
{
    int n = arr.size();
    vector<int> nge = FindNGE(arr, n);
    vector<int> pgee = FindPGE(arr, n);

    int total = 0;
    int mod = (int)(1e9 + 7);

    for (int i = 0; i < n; i++)
    {
        int left = i - pgee[i];
        int right = nge[i] - i;

        long long freq = left * right * 1ll;

        int val = (freq * arr[i] * 1ll) % mod;

        total = (total + val) % mod;
    }
    return total;
}

int optimal(vector<int> arr)
{

    return sumOfSubarrMax(arr) - sumOfSubarrMin(arr);
}

int main()
{
    vector<int> arr = {1, 4, 3, 2};
    cout << "Sum of subarray range: " << optimal(arr) << endl;
    return 0;
}