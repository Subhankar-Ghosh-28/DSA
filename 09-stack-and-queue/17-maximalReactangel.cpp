#include <bits/stdc++.h>
using namespace std;

int largestReactangelHistrogram(vector<int> &arr)
{
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
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

int func(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int maxArea = 0;
    vector<vector<int>> prefixSum(n, vector<int>(m));
    for (int j = 0; j < m; j++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += mat[i][j];
            if (mat[i][j] == 0)
            {
                prefixSum[i][j] = 0;
                sum = 0;
            }

            prefixSum[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int area = largestReactangelHistrogram(prefixSum[i]);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main()
{
    vector<vector<int>> arr = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0}};

    int ans = func(arr);

    cout << "the largestreactangel area is: " << ans << endl;

    return 0;
}
