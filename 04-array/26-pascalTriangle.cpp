#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    // Generate full triangle
    vector<vector<int>> generator(int n)
    {
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++)
        {

            vector<int> row(i + 1, 1);

            for (int j = 1; j < i; j++)
            {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;

        // TC -> O(N*N); sc -> O(N*N)
    }

    vector<long long> onlyOneRow(int N)
    {
        vector<long long> row;
        long long val = 1;
        row.push_back(val);
        for (int i = 1; i < N; i++)
        {
            val = val * (N - i) / i;
            row.push_back(val);
        }
        return row;

        // TC -> O(N); sc -> O(N)
    }

    long long findPascalElement(int r, int c)
    {
        int n = r - 1;
        int k = c - 1;

        long long result = 1;
        for (int i = 0; i < k; i++)
        {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
};

int main()
{
    int n = 7;

    Solution1 sol;
    cout << "The pascal triangle of " << n << " is :" << endl;
    vector<vector<int>> ans = sol.generator(n);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << "\n";
    }
    cout << "\n";

    int N = 5;
    vector<long long> row = sol.onlyOneRow(N);
    cout << "ith row is :" << endl;
    for (auto it : row)
    {
        cout << it << " ";
    }
    cout << "\n";

    int r = 5, c = 3;
    cout << "The element at row " << r << " col " << c << " is : " << sol.findPascalElement(r, c);
    return 0;
}