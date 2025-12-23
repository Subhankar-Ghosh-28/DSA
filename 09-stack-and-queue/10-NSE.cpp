#include <bits/stdc++.h>
using namespace std;

// nearest smaller element from the LEFT

vector<int> bruteForce1(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i - 1; j >= 0; --j)
        {
            if (arr[j] < arr[i])
            {
                nse[i] = arr[j];
                break;
            }
        }
    }
    return nse;
}

vector<int> optimal1(vector<int> &arr)
{
    int n = arr.size();
    vector<int> nse(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return nse;
}

// next smallest element using circuler array type

vector<int> bruteForce2(vector<int> arr)
{
    int n = arr.size();
    vector<int> nse(n, -1);

    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = n + i - 1; j >= i + 1; --j)
        {
            int ind = j % n;
            if (arr[ind] < arr[i])
            {
                nse[i] = arr[ind];
                break;
            }
        }
    }
    return nse;
}

vector<int> optimal2(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nse(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; ++i)
    {
        while (!st.empty() && st.top() >= arr[i % n])
        {
            st.pop();
        }
        if (i >= n)
        {
            nse[i % n] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return nse;
}

int main()
{
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> ans = optimal2(arr);

    cout << "after nse: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}