#include <bits/stdc++.h>
using namespace std;

int bruteForce(vector<int> arr, int n)
{
    int sum = 0;
    int mod = (int)(1e9 + 7);

    for (int i = 0; i < n; i++)
    {
        int mini = arr[i];
        for (int j = i; j < n; j++)
        {
            mini = min(mini, arr[j]);
            sum = (sum + mini) % mod;
        }
    }

    return sum;
}

// optimal

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

int optimal(vector<int> arr, int n)
{
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

int main()
{
    vector<int> arr = {3, 1, 2, 4};
    int n = arr.size();

    cout << "Sum of subarray minimjum is : " << optimal(arr, n) << endl;
    return 0;
}