#include <bits/stdc++.h>
using namespace std;

// next grester element not circuler

vector<int> bruteForce1(vector<int> arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] >= arr[i])
            {
                nge[i] = arr[j];
                break;
            }
        }
    }
    return nge;
}

vector<int> optimal1(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        nge[i] = st.empty() ? -1 : st.top();

        st.push(arr[i]);
    }
    return nge;
}

// next grester element using circuler array type

vector<int> bruteForce2(vector<int> arr)
{
    int n = arr.size();
    vector<int> nge(n, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < i + n - 1; j++)
        {
            int ind = j % n;
            if (arr[ind] > arr[i])
            {
                nge[i] = arr[ind];
                break;
            }
        }
    }

    return nge;
}

vector<int> optimal2(vector<int> &arr)
{
    int n = arr.size();

    vector<int> nge(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; --i)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }
        st.push(arr[i % n]);
    }
    return nge;
}

int main()
{

    vector<int> arr = {6, 0, 8, 1, 3};

    vector<int> ans = optimal2(arr);

    cout << "after nge: ";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}