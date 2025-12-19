#include <bits/stdc++.h>
using namespace std;

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

int bruteForce(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse = FindNSE(arr, n);
    vector<int> psee = FindPSEE(arr, n);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i] * (nse[i] - psee[i] - 1));
    }
    return maxi;
}

int optimal(vector<int> &arr)
{
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int element = arr[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            maxArea = max((element * (nse - pse - 1)), maxArea);
        }
        st.push(i);
    }

    while (!st.empty())
    {
        int nse = arr.size();
        int element = arr[st.top()];
        st.pop();
        int pse = st.empty() ? -1 : st.top();
        maxArea = max(maxArea, ((nse - pse - 1) * element));
    }
    return maxArea;
}

int main()
{
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    cout << "maxArea is : " << optimal(arr) << endl;
    return 0;
}